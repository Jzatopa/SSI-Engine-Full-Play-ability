package engine.combat.attack;

import java.util.Objects;

import engine.combat.Combatant;

/**
 * Adapts {@code engine.combat.Combatant} onto {@link DefenderView} for
 * {@link AttackResolver}.
 *
 * <p>Directly mapped from Combatant: {@link #armorClass()} and {@link
 * #armorClassBehind()} (both derived from {@code Combatant.armorClass()} --
 * Combatant has no separate behind/flank AC, so the same value is used both
 * ways; this is neutral, not a claim that Matrix Cubed lacks a facing-AC
 * mechanic) and {@link #currentHitPoints()} ({@code Combatant.hitPoints()}).</p>
 *
 * <p>Combatant's {@code armorClass} is a classic DESCENDING Gold Box value
 * (lower = better armor), but the ported {@link AttackResolver} compares
 * against an ASCENDING AC (higher = harder to hit; a hit needs
 * {@code roll + attackerHitBonus >= targetAc}). This adapter converts:
 * ascending AC = {@link CombatantAttackerView#GOLD_BOX_ASCENDING_AC_BASELINE}
 * {@code - Combatant.armorClass()}, using the SAME baseline the attacker
 * view uses for its to-hit bonus. Because both sides share the baseline, it
 * cancels and the resolver reproduces {@code d20 >= thac0 - armorClass}
 * exactly -- see {@link CombatantAttackerView}'s class javadoc for the full
 * derivation and the candidate-constant note.</p>
 *
 * <p>Everything else is neutral/candidate pending decoded Combatant facing,
 * status-effect and crowding data: see each method's javadoc. In particular
 * {@link #positionFlags()} returns 0, which keeps {@link
 * AttackResolver#largeWeaponDiceApply} false and
 * {@link AttackResolver#canBackStabTarget}'s {@code (positionFlags & 0x7F) <= 1}
 * clause satisfied on its own -- backstab still requires {@link
 * AttackerView#canBackstabWithCurrentWeapon()}, which {@link
 * CombatantAttackerView} also returns false, so no backstab is ever modeled
 * through this adapter pair today.</p>
 */
public final class CombatantDefenderView implements DefenderView {

	private final Combatant defender;

	public CombatantDefenderView(Combatant defender) {
		this.defender = Objects.requireNonNull(defender, "defender");
	}

	/**
	 * Combatant's descending Gold Box armor class converted to COAB's
	 * ascending AC form: {@code GOLD_BOX_ASCENDING_AC_BASELINE - armorClass}.
	 * See class javadoc for why this reproduces {@code d20 >= thac0 - armorClass}
	 * exactly.
	 */
	@Override
	public int armorClass() {
		return CombatantAttackerView.GOLD_BOX_ASCENDING_AC_BASELINE - defender.armorClass();
	}

	/** Mirrors {@link #armorClass()} (Combatant has no separate behind AC); see class javadoc. */
	@Override
	public int armorClassBehind() {
		return CombatantAttackerView.GOLD_BOX_ASCENDING_AC_BASELINE - defender.armorClass();
	}

	@Override
	public int currentHitPoints() {
		return defender.hitPoints();
	}

	/** Neutral/candidate pending decoded status-effect data on Combatant: held/paralysis is not modeled. */
	@Override
	public boolean isHeld() {
		return false;
	}

	/** Neutral/candidate pending decoded per-round attack-count tracking on Combatant: always 0. */
	@Override
	public int attacksReceivedThisRound() {
		return 0;
	}

	/** Neutral/candidate pending decoded facing data on Combatant: always 0. */
	@Override
	public int directionChangesThisRound() {
		return 0;
	}

	/** Neutral/candidate pending decoded facing/geometry data on Combatant: always false. */
	@Override
	public boolean attackerSharesFacingDirection() {
		return false;
	}

	/** Neutral/candidate pending recovered meaning of COAB's unlabeled field_DE: always 0. */
	@Override
	public int positionFlags() {
		return 0;
	}

	/** Neutral/candidate pending decoded range-geometry data on Combatant: always 0 (melee range). */
	@Override
	public int rangeToAttacker() {
		return 0;
	}
}
