package engine.combat.attack;

/**
 * Read-only defender-side facts needed by {@link AttackResolver} and
 * {@link AttackTargetingRules}.
 *
 * <p>Ported from COAB (https://github.com/simeonpilgrim/coab, commit 9dc46f1)
 * engine/ovr014.cs ({@code AttackTarget01}, sub_3F4EB; {@code CanBackStabTarget},
 * sub_408D7; {@code RangedDefenseBonus}, sub_3FCED), which read these facts
 * off the target {@code Classes.Player}.</p>
 */
public interface DefenderView {

	/**
	 * COAB {@code target.ac}: armor class facing the attacker head-on. Already
	 * assembled by the integrator (including any dexterity AC bonus from
	 * {@link AttackRuleset#dexterityArmorClassBonus}); this package treats it
	 * as an opaque number where a hit requires {@code totalToHitValue >= armorClass()}.
	 */
	int armorClass();

	/**
	 * COAB {@code target.ac_behind}: armor class when struck from behind (used
	 * for both the "attacked from behind" and backstab cases).
	 */
	int armorClassBehind();

	/** COAB {@code target.hit_point_current}, needed only for {@link AttackResolver#slayHelplessOutcome}. */
	int currentHitPoints();

	/**
	 * COAB {@code target.IsHeld()}: paralyzed/held/otherwise unable to defend.
	 * A held target both short-circuits the whole turn to an automatic "slays
	 * helpless" outcome at the top of {@code AttackTarget01} (see
	 * {@link AttackResolver#slayHelplessOutcome}) and, ported faithfully, is
	 * also OR-ed into the per-swing hit check inside the attack loop.
	 */
	boolean isHeld();

	/** COAB {@code target.actions.AttacksReceived}: attacks already landed on the target this round. */
	int attacksReceivedThisRound();

	/** COAB {@code target.actions.directionChanges}: accumulated facing churn this round. */
	int directionChangesThisRound();

	/**
	 * COAB {@code ovr014.getTargetDirection(target, attacker) == target.actions.direction}:
	 * true when the attacker is standing in the direction the target is
	 * currently facing. The octant geometry (sub_409BC) is out of scope for
	 * this package; the integrator computes it from the existing
	 * {@code engine.combat.CombatPosition} model and supplies the boolean.
	 */
	boolean attackerSharesFacingDirection();

	/**
	 * COAB {@code target.field_DE}: an unlabeled packed byte. {@code AttackTarget01}
	 * consumes it two different ways -- {@code field_DE > 0x80 || (field_DE & 7) > 1}
	 * selects the attacker's large/two-handed weapon dice, and
	 * {@code (field_DE & 0x7F) <= 1} gates backstab eligibility in
	 * {@code CanBackStabTarget}. Its real meaning (candidate: adjacent-combatant
	 * crowding / room to swing) was not recovered from decompilation; ported
	 * faithfully as an opaque byte the integrator must supply.
	 */
	int positionFlags();

	/**
	 * COAB {@code ovr025.getTargetRange(target, attacker)}: the attacker/target
	 * range used by {@code RangedDefenseBonus}. Range-metric derivation
	 * (sub_40... geometry) is out of scope; the integrator supplies the
	 * already-computed value.
	 */
	int rangeToAttacker();
}
