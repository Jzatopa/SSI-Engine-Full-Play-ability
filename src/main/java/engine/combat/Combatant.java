package engine.combat;

import java.util.Objects;

/**
 * Stateful combatant used by the Java Matrix Cubed combat vertical slice.
 *
 * <p>This intentionally separates two concepts:</p>
 * <ul>
 *   <li>decoded/original evidence such as monster name, HP and AC,</li>
 *   <li>temporary runtime state such as position, current HP and acted flag.</li>
 * </ul>
 *
 * <p>Attack math remains a visible scaffold until original combat formulas are
 * validated from DOS captures or recovered GAME.OVR routines.</p>
 */
public final class Combatant {
	public enum Side {
		PARTY, MONSTER
	}

	/**
	 * Subset of COAB's {@code Classes/Enums.cs Status} needed for combat
	 * (coab commit 9dc46f1). The remaining original states (animated,
	 * tempgone, running, stoned, gone) arrive with the effect/NPC passes.
	 */
	public enum HealthStatus {
		OKAY, UNCONSCIOUS, DYING, DEAD
	}

	private final int id;
	private final String name;
	private final Side side;
	private final int maxHitPoints;
	private final int armorClass;
	private final int thac0;
	private final int damageMin;
	private final int damageMax;
	private final int movement;
	private final String evidence;

	private int hitPoints;
	private HealthStatus healthStatus = HealthStatus.OKAY;
	private int bleeding;
	private CombatPosition position;
	private boolean acted;

	public Combatant(
		int id,
		String name,
		Side side,
		int maxHitPoints,
		int armorClass,
		int thac0,
		int damageMin,
		int damageMax,
		int movement,
		CombatPosition position,
		String evidence
	) {
		if (maxHitPoints <= 0) {
			throw new IllegalArgumentException("maxHitPoints must be positive");
		}
		if (damageMin <= 0 || damageMax < damageMin) {
			throw new IllegalArgumentException("invalid damage range " + damageMin + "-" + damageMax);
		}
		if (movement < 0) {
			throw new IllegalArgumentException("movement must be non-negative");
		}
		this.id = id;
		this.name = Objects.requireNonNull(name, "name");
		this.side = Objects.requireNonNull(side, "side");
		this.maxHitPoints = maxHitPoints;
		this.armorClass = armorClass;
		this.thac0 = thac0;
		this.damageMin = damageMin;
		this.damageMax = damageMax;
		this.movement = movement;
		this.position = Objects.requireNonNull(position, "position");
		this.evidence = evidence == null ? "" : evidence;
		this.hitPoints = maxHitPoints;
	}

	public static Combatant partyMember(int id, String name, CombatPosition position) {
		return new Combatant(
			id,
			name,
			Side.PARTY,
			38,
			4,
			14,
			6,
			12,
			6,
			position,
			"Party placeholder derived from playable Matrix Cubed vertical-slice needs; replace with CHRDATA-backed stats."
		);
	}

	public static Combatant ratwurst(int id, CombatPosition position) {
		return new Combatant(
			id,
			"RATWURST",
			Side.MONSTER,
			52,
			4,
			13,
			4,
			10,
			5,
			position,
			"Enemy label/HP/AC taken from supplied Matrix Cubed combat screenshot; formulas remain unproven."
		);
	}

	public int id() {
		return id;
	}

	public String name() {
		return name;
	}

	public Side side() {
		return side;
	}

	public int maxHitPoints() {
		return maxHitPoints;
	}

	public int hitPoints() {
		return hitPoints;
	}

	public int armorClass() {
		return armorClass;
	}

	public int thac0() {
		return thac0;
	}

	public int damageMin() {
		return damageMin;
	}

	public int damageMax() {
		return damageMax;
	}

	public int movement() {
		return movement;
	}

	public CombatPosition position() {
		return position;
	}

	public String evidence() {
		return evidence;
	}

	public boolean hasActed() {
		return acted;
	}

	public boolean isAlive() {
		return hitPoints > 0;
	}

	public HealthStatus healthStatus() {
		return healthStatus;
	}

	/** Rounds of bleeding accumulated while {@link HealthStatus#DYING}; dead past 9. */
	public int bleeding() {
		return bleeding;
	}

	public void moveTo(CombatPosition next) {
		position = Objects.requireNonNull(next, "next");
	}

	/**
	 * Damage semantics ported from COAB {@code ovr025.damage_player}
	 * (coab commit 9dc46f1): overkill past 0 HP by more than 9 kills
	 * outright; overkill by 1..9 leaves the combatant dying with the
	 * bleeding counter starting at the overkill amount; landing exactly on
	 * 0 knocks the combatant unconscious. Any non-okay status pins hit
	 * points to 0 and takes the combatant out of the fight. The original's
	 * animated-at-zero-is-dead branch is deferred until animated status is
	 * modeled.
	 */
	public int applyDamage(int amount) {
		int damage = Math.max(0, amount);
		if (damage == 0) {
			return 0;
		}
		int before = hitPoints;
		int newHp = 0;
		int negHp = 0;
		if (hitPoints >= damage) {
			newHp = hitPoints - damage;
		} else {
			negHp = damage - hitPoints;
		}
		if (negHp > 9) {
			healthStatus = HealthStatus.DEAD;
		} else if (negHp > 0) {
			healthStatus = HealthStatus.DYING;
			bleeding = negHp;
		} else if (newHp == 0) {
			healthStatus = HealthStatus.UNCONSCIOUS;
		}
		hitPoints = healthStatus == HealthStatus.OKAY ? newHp : 0;
		return before - hitPoints;
	}

	/**
	 * One end-of-round bleeding tick for a dying combatant, from COAB
	 * {@code ovr009.BattleRoundChecks}: bleeding grows by 1 per round and
	 * the combatant dies when it exceeds 9.
	 *
	 * @return true when this tick killed the combatant
	 */
	public boolean bleedOneRound() {
		if (healthStatus != HealthStatus.DYING) {
			return false;
		}
		bleeding++;
		if (bleeding > 9) {
			healthStatus = HealthStatus.DEAD;
			return true;
		}
		return false;
	}

	/**
	 * Candidate healing behavior: restores hit points and clears a non-dead
	 * combatant back to okay. COAB's real cure/bandage routines
	 * ({@code ovr005}, {@code ovr025.bandage}) arrive with the effect pass;
	 * until then this stays a labeled scaffold with no original evidence.
	 */
	public int heal(int amount) {
		if (healthStatus == HealthStatus.DEAD) {
			return 0;
		}
		int healing = Math.max(0, amount);
		int before = hitPoints;
		hitPoints = Math.min(maxHitPoints, hitPoints + healing);
		if (hitPoints > 0) {
			healthStatus = HealthStatus.OKAY;
			bleeding = 0;
		}
		return hitPoints - before;
	}

	public void markActed() {
		acted = true;
	}

	public void clearActed() {
		acted = false;
	}

	public Combatant copy() {
		Combatant copy = new Combatant(
			id,
			name,
			side,
			maxHitPoints,
			armorClass,
			thac0,
			damageMin,
			damageMax,
			movement,
			position,
			evidence
		);
		copy.hitPoints = hitPoints;
		copy.healthStatus = healthStatus;
		copy.bleeding = bleeding;
		copy.acted = acted;
		return copy;
	}

	@Override
	public String toString() {
		String status = healthStatus == HealthStatus.OKAY ? "" : " " + healthStatus;
		return name + " " + side + " HP " + hitPoints + "/" + maxHitPoints + " AC " + armorClass + " at " + position + status;
	}
}
