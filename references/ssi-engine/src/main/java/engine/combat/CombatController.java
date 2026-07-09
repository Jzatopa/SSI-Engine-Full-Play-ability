package engine.combat;

import java.util.Comparator;
import java.util.List;
import java.util.Optional;
import java.util.Random;

import engine.combat.Combatant.Side;
import engine.combat.ai.CombatStateQuickFightView;
import engine.combat.ai.DiceRoller;
import engine.combat.ai.QuickFightCombatantView;
import engine.combat.ai.QuickFightIntent;
import engine.combat.ai.QuickFightPlanner;

/**
 * Thin command/controller layer for interactive Java combat.
 *
 * <p>This class is the bridge between a UI (Swing for now, the SSI Engine UI
 * later) and {@link CombatState}.  It owns a cursor, applies keyboard-style
 * commands, performs contextual move/attack actions, and advances monster
 * turns with the ported COAB quick-fight planner.  The controller is designed so
 * the same state can later be driven by recovered ECL/VM combat callbacks.</p>
 */
public final class CombatController {
	public enum Action {
		MOVED,
		ATTACKED,
		ENDED_TURN,
		MONSTER_ACTED,
		BLOCKED,
		NO_TARGET,
		COMBAT_OVER
	}

	private final CombatState state;
	private final Random random;
	private final CombatStateQuickFightView quickFightView;
	private final QuickFightPlanner quickFightPlanner;
	private CombatPosition cursor;

	public CombatController(CombatState state) {
		this(state, 52017L);
	}

	public CombatController(CombatState state, long seed) {
		this.state = state;
		this.random = new Random(seed);
		this.quickFightView = new CombatStateQuickFightView(state);
		this.quickFightPlanner = new QuickFightPlanner(quickFightView, DiceRoller.seeded(seed ^ 0x3504BL));
		this.state.addEvidence("QuickFightPlanner live AI wire: COAB ovr010 PlayerQuickFight decision planner drives monster turns through CombatStateQuickFightView; spells, items, morale/flee/surrender and ranged weapon execution stay neutral/deferred until Combatant exposes title evidence.");
		Combatant current = state.current();
		this.cursor = current == null ? CombatPosition.of(0, 0) : current.position();
	}

	public CombatState state() {
		return state;
	}

	public CombatPosition cursor() {
		return cursor;
	}

	public void setCursor(CombatPosition cursor) {
		this.cursor = cursor;
	}

	public void moveCursor(int dx, int dy) {
		int nextX = clamp(cursor.x() + dx, 0, BattlefieldBuffer.WIDTH - 1);
		int nextY = clamp(cursor.y() + dy, 0, BattlefieldBuffer.HEIGHT - 1);
		cursor = CombatPosition.of(nextX, nextY);
	}

	public Action selectNextEnemy() {
		if (isCombatOver()) {
			return Action.COMBAT_OVER;
		}
		List<Combatant> enemies = state.livingCombatants().stream()
			.filter(c -> state.current() != null && c.side() != state.current().side())
			.sorted(Comparator.comparingInt(Combatant::id))
			.toList();
		if (enemies.isEmpty()) {
			return Action.NO_TARGET;
		}
		int selected = -1;
		for (int i = 0; i < enemies.size(); i++) {
			if (enemies.get(i).position().equals(cursor)) {
				selected = i;
				break;
			}
		}
		cursor = enemies.get((selected + 1) % enemies.size()).position();
		return Action.NO_TARGET;
	}

	public Action contextualAction() {
		if (isCombatOver()) {
			return Action.COMBAT_OVER;
		}
		Combatant current = state.current();
		if (current == null) {
			return Action.BLOCKED;
		}
		if (current.side() == Side.MONSTER) {
			return resolveMonsterTurn();
		}
		Optional<Combatant> target = state.occupantAt(cursor);
		if (target.isPresent() && target.get().side() != current.side()) {
			return attackCursor();
		}
		if (state.moveCurrentTo(cursor)) {
			return Action.MOVED;
		}
		return Action.BLOCKED;
	}

	public Action attackCursor() {
		if (isCombatOver()) {
			return Action.COMBAT_OVER;
		}
		Combatant current = state.current();
		if (current == null) {
			return Action.BLOCKED;
		}
		Optional<Combatant> target = state.occupantAt(cursor);
		if (target.isEmpty() || target.get().side() == current.side()) {
			return Action.NO_TARGET;
		}
		state.attack(target.get(), rollD20());
		state.endTurn();
		syncCursorToCurrent();
		return Action.ATTACKED;
	}

	public Action moveCurrentToCursor() {
		if (isCombatOver()) {
			return Action.COMBAT_OVER;
		}
		Combatant current = state.current();
		if (current == null || current.side() == Side.MONSTER) {
			return Action.BLOCKED;
		}
		if (state.moveCurrentTo(cursor)) {
			return Action.MOVED;
		}
		return Action.BLOCKED;
	}

	public Action endTurn() {
		if (isCombatOver()) {
			return Action.COMBAT_OVER;
		}
		state.endTurn();
		syncCursorToCurrent();
		return Action.ENDED_TURN;
	}

	public Action forceVictoryForDebug() {
		if (isCombatOver()) {
			return Action.COMBAT_OVER;
		}
		state.forceVictory("Debug auto-resolve key forced victory for VM/Swing handoff validation; not original combat behavior.");
		return Action.COMBAT_OVER;
	}

	public Action resolveMonsterTurn() {
		if (isCombatOver()) {
			return Action.COMBAT_OVER;
		}
		Combatant monster = state.current();
		if (monster == null || monster.side() != Side.MONSTER) {
			return Action.BLOCKED;
		}
		QuickFightCombatantView monsterView = quickFightView.viewFor(monster).orElseThrow();
		QuickFightIntent intent = quickFightPlanner.plan(monsterView);
		executeQuickFightIntent(monster, intent);
		syncCursorToCurrent();
		return Action.MONSTER_ACTED;
	}

	public void syncCursorToCurrent() {
		Combatant current = state.current();
		if (current != null) {
			cursor = current.position();
		}
	}

	public boolean isCombatOver() {
		return state.phase() == CombatState.Phase.VICTORY || state.phase() == CombatState.Phase.DEFEAT
			|| state.phase() == CombatState.Phase.EXPIRED;
	}

	private void executeQuickFightIntent(Combatant monster, QuickFightIntent intent) {
		switch (intent.kind()) {
			case ATTACK -> executeQuickFightAttack(intent);
			case MOVE_TOWARD -> executeQuickFightMoveToward(monster, intent);
			case END_TURN, GUARD -> state.endTurn();
			case FLEE, SURRENDER, BANDAGE, TURN_UNDEAD, CAST_QUEUED_SPELL, CAST_SPELL, USE_ITEM_SPELL, SWITCH_WEAPON ->
				state.endTurn();
		}
	}

	private void executeQuickFightAttack(QuickFightIntent intent) {
		Optional<Combatant> target = intent.target().flatMap(quickFightView::combatantFor);
		if (target.isPresent() && target.get().isAlive() && target.get().side() != state.current().side()) {
			cursor = target.get().position();
			state.attack(target.get(), rollD20());
		}
		state.endTurn();
	}

	private void executeQuickFightMoveToward(Combatant monster, QuickFightIntent intent) {
		Optional<Combatant> target = intent.target().flatMap(quickFightView::combatantFor);
		if (target.isPresent()) {
			CombatPosition step = stepToward(monster.position(), target.get().position());
			if (!state.moveCurrentTo(step)) {
				tryOrthogonalFallback(monster, target.get());
			}
		}
		state.endTurn();
	}

	private void tryOrthogonalFallback(Combatant monster, Combatant target) {
		int dx = Integer.compare(target.position().x(), monster.position().x());
		int dy = Integer.compare(target.position().y(), monster.position().y());
		CombatPosition alt = tryPosition(monster.position().x() + dx, monster.position().y()).orElse(null);
		if (alt == null || !state.moveCurrentTo(alt)) {
			alt = tryPosition(monster.position().x(), monster.position().y() + dy).orElse(null);
			if (alt != null) {
				state.moveCurrentTo(alt);
			}
		}
	}

	private CombatPosition stepToward(CombatPosition from, CombatPosition to) {
		int dx = Integer.compare(to.x(), from.x());
		int dy = Integer.compare(to.y(), from.y());
		if (Math.abs(to.x() - from.x()) >= Math.abs(to.y() - from.y()) && dx != 0) {
			return tryPosition(from.x() + dx, from.y()).orElse(from);
		}
		if (dy != 0) {
			return tryPosition(from.x(), from.y() + dy).orElse(from);
		}
		if (dx != 0) {
			return tryPosition(from.x() + dx, from.y()).orElse(from);
		}
		return from;
	}

	private Optional<CombatPosition> tryPosition(int x, int y) {
		if (!CombatPosition.isInside(x, y)) {
			return Optional.empty();
		}
		CombatPosition position = CombatPosition.of(x, y);
		if (state.occupantAt(position).isPresent()) {
			return Optional.empty();
		}
		return Optional.of(position);
	}

	private int rollD20() {
		return random.nextInt(20) + 1;
	}

	private int clamp(int value, int min, int max) {
		return Math.max(min, Math.min(max, value));
	}
}
