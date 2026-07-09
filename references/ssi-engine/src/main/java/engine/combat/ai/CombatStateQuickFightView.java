package engine.combat.ai;

import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.Optional;
import java.util.OptionalInt;

import engine.combat.CombatState;
import engine.combat.Combatant;
import engine.combat.map.CombatMapService;
import engine.combat.map.ReachResult;
import engine.combat.map.TileTraits;

/**
 * UI-neutral adapter from {@link CombatState} into the COAB quick-fight planner.
 *
 * <p>The wrapped {@link Combatant} model currently exposes melee combat facts
 * only. Every spell, item, morale, undead and ranged hook therefore returns a
 * documented neutral value here instead of inventing Matrix Cubed semantics.
 * The adapter still delegates geometry to the ported {@link CombatMapService}
 * with open-field tile traits until title-specific wall/height tables are
 * decoded.</p>
 */
public final class CombatStateQuickFightView implements QuickFightBattleView {
	private static final TileTraits OPEN_FIELD_TILES = new TileTraits() {
		@Override
		public int eyeHeight(int x, int y) {
			return 1;
		}

		@Override
		public int wallBlockHeight(int x, int y) {
			return 0;
		}
	};

	private final CombatState state;
	private final CombatMapService mapService;
	private final Map<Integer, CombatantQuickFightView> viewsById = new HashMap<>();

	public CombatStateQuickFightView(CombatState state) {
		this(state, new CombatMapService(OPEN_FIELD_TILES));
	}

	CombatStateQuickFightView(CombatState state, CombatMapService mapService) {
		this.state = state;
		this.mapService = mapService;
	}

	public Optional<QuickFightCombatantView> viewFor(Combatant combatant) {
		if (combatant == null) {
			return Optional.empty();
		}
		return Optional.of(viewForId(combatant.id(), combatant));
	}

	public Optional<Combatant> combatantFor(QuickFightCombatantView view) {
		if (view == null) {
			return Optional.empty();
		}
		for (Combatant combatant : state.combatants()) {
			if (combatant.id() == view.id()) {
				return Optional.of(combatant);
			}
		}
		return Optional.empty();
	}

	@Override
	public List<QuickFightCombatantView> combatants() {
		List<QuickFightCombatantView> views = new ArrayList<>();
		for (Combatant combatant : state.combatants()) {
			views.add(viewForId(combatant.id(), combatant));
		}
		return Collections.unmodifiableList(views);
	}

	@Override
	public boolean canSee(QuickFightCombatantView self, QuickFightCombatantView target) {
		Optional<Combatant> source = combatantFor(self);
		Optional<Combatant> destination = combatantFor(target);
		if (source.isEmpty() || destination.isEmpty()) {
			return false;
		}
		return mapService.reach(source.get().position(), destination.get().position(), false).reach();
	}

	@Override
	public List<QuickFightCombatantView> enemiesWithin(QuickFightCombatantView self, int maxRange, boolean ignoreWalls) {
		Optional<Combatant> source = combatantFor(self);
		if (source.isEmpty()) {
			return List.of();
		}
		List<Combatant> enemies = new ArrayList<>();
		for (Combatant combatant : state.combatants()) {
			if (combatant.side() == source.get().side() || !combatant.isAlive()) {
				continue;
			}
			ReachResult reach = mapService.reach(source.get().position(), combatant.position(), ignoreWalls);
			if (reach.reach() && wholeTileDistance(reach.range()) <= maxRange) {
				enemies.add(combatant);
			}
		}
		enemies.sort(Comparator
			.comparingInt((Combatant combatant) -> wholeTileDistance(
				mapService.reach(source.get().position(), combatant.position(), ignoreWalls).range()))
			.thenComparingInt(Combatant::id));

		List<QuickFightCombatantView> views = new ArrayList<>();
		for (Combatant enemy : enemies) {
			views.add(viewForId(enemy.id(), enemy));
		}
		return Collections.unmodifiableList(views);
	}

	@Override
	public OptionalInt pathStepsTo(QuickFightCombatantView self, QuickFightCombatantView target) {
		Optional<Combatant> source = combatantFor(self);
		Optional<Combatant> destination = combatantFor(target);
		if (source.isEmpty() || destination.isEmpty()) {
			return OptionalInt.empty();
		}
		ReachResult reach = mapService.reach(source.get().position(), destination.get().position(), false);
		return reach.reach() ? OptionalInt.of(reach.range()) : OptionalInt.empty();
	}

	@Override
	public int distanceTo(QuickFightCombatantView self, QuickFightCombatantView target) {
		Optional<Combatant> source = combatantFor(self);
		Optional<Combatant> destination = combatantFor(target);
		if (source.isEmpty() || destination.isEmpty()) {
			return QuickFightCombatantView.UNREACHABLE;
		}
		ReachResult reach = mapService.reach(source.get().position(), destination.get().position(), true);
		return reach.reach() ? wholeTileDistance(reach.range()) : QuickFightCombatantView.UNREACHABLE;
	}

	@Override
	public int battleBaseMorale() {
		return 50;
	}

	@Override
	public boolean areaForbidsSpells() {
		return false;
	}

	@Override
	public boolean autoPartyCastsMagic() {
		return false;
	}

	@Override
	public boolean anyPartyTeammateDying() {
		for (Combatant combatant : state.combatants()) {
			if (combatant.side() == Combatant.Side.PARTY
				&& combatant.healthStatus() == Combatant.HealthStatus.DYING) {

				return true;
			}
		}
		return false;
	}

	private CombatantQuickFightView viewForId(int id, Combatant combatant) {
		CombatantQuickFightView existing = viewsById.get(id);
		if (existing != null && existing.combatant == combatant) {
			return existing;
		}
		CombatantQuickFightView created = new CombatantQuickFightView(combatant);
		viewsById.put(id, created);
		return created;
	}

	private static int wholeTileDistance(int rawSteps) {
		return rawSteps / 2;
	}

	private static final class CombatantQuickFightView implements QuickFightCombatantView {
		private final Combatant combatant;

		CombatantQuickFightView(Combatant combatant) {
			this.combatant = combatant;
		}

		@Override
		public int id() {
			return combatant.id();
		}

		@Override
		public boolean inCombat() {
			return combatant.isAlive();
		}

		@Override
		public QuickFightTeam team() {
			return combatant.side() == Combatant.Side.PARTY ? QuickFightTeam.OURS : QuickFightTeam.ENEMY;
		}

		@Override
		public int hitPointsCurrent() {
			return combatant.hitPoints();
		}

		@Override
		public int hitPointsMax() {
			return combatant.maxHitPoints();
		}

		@Override
		public int movementPoints() {
			return combatant.movement();
		}

		@Override
		public int movePointsLeft() {
			return combatant.hasActed() ? 0 : combatant.movement();
		}

		@Override
		public int delayLeft() {
			return combatant.hasActed() ? 0 : 1;
		}

		@Override
		public boolean forcedFleeing() {
			return false;
		}

		@Override
		public boolean held() {
			return false;
		}

		@Override
		public int intelligence() {
			return 0;
		}

		@Override
		public boolean npcControlled() {
			return false;
		}

		@Override
		public int moraleScore() {
			return 0;
		}

		@Override
		public boolean wearsArmor() {
			return false;
		}

		@Override
		public boolean fragileCaster() {
			return false;
		}

		@Override
		public boolean canTurnUndead() {
			return false;
		}

		@Override
		public boolean hasTurnedUndead() {
			return false;
		}

		@Override
		public int undeadRank() {
			return 0;
		}

		@Override
		public int queuedSpellId() {
			return 0;
		}

		@Override
		public boolean canCastSpells() {
			return false;
		}

		@Override
		public boolean canUseItems() {
			return false;
		}

		@Override
		public boolean hasRangedWeapon() {
			return false;
		}

		@Override
		public boolean hasRangedMeleeWeapon() {
			return false;
		}

		@Override
		public int primaryWeaponRawRange() {
			return 0;
		}

		@Override
		public int[] learntSpellIds() {
			return new int[0];
		}

		@Override
		public int[] readiedItemSpellIds() {
			return new int[0];
		}
	}
}
