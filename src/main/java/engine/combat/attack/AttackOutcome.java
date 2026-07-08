package engine.combat.attack;

/**
 * Structured result of resolving a single attack swing, produced by
 * {@link AttackResolver}. Deliberately inert: it carries what happened and
 * the damage-roll inputs an integrator needs, but never mutates a combatant
 * and never rolls damage dice itself (that belongs to the caller, once they
 * decide how to apply {@link #damageDiceCount()} x {@link #damageDiceSize()}
 * + {@link #damageBonus()}, times {@link #backstabDamageMultiplier()}, floored
 * at 0 -- see COAB {@code ovr014.sub_3E192}).
 *
 * @param hit whether the swing connects (or the target is helpless, see {@link #slaysHelpless()})
 * @param slaysHelpless true only for {@link AttackResolver#slayHelplessOutcome}: COAB's
 *   {@code AttackTarget01} "target.IsHeld()" top-of-function branch, which auto-hits and
 *   consumes the attacker's whole turn instead of running the normal per-swing loop
 * @param rawAttackRoll the raw 1..20 roll (COAB {@code roll_dice(20, 1)}), before the natural-20 correction
 * @param correctedAttackRoll the roll after COAB's natural-20-becomes-100 correction (equal to
 *   {@code rawAttackRoll} otherwise; equal to {@code rawAttackRoll} on a miss-by-guard-clause too)
 * @param totalToHitValue {@code correctedAttackRoll + attacker hit bonus + team bonus}, the value
 *   compared against {@link #targetArmorClass()}
 * @param targetArmorClass the AC actually rolled against this swing (behind/backstab/ranged adjustments applied)
 * @param backstab whether COAB {@code CanBackStabTarget} (sub_408D7) was true for this swing
 * @param behindAttack whether the swing was resolved as a from-behind attack (explicit request or the
 *   auto-behind quirk: attacked more than once already this round, from the same facing, with more
 *   than 4 accumulated direction changes)
 * @param damageDiceCount weapon damage dice to roll if {@link #hit()} (normal or large grip, per the
 *   COAB {@code target.field_DE} room check)
 * @param damageDiceSize size of each damage die to roll if {@link #hit()}
 * @param damageBonus flat damage bonus to add after rolling {@link #damageDiceCount()}d{@link #damageDiceSize()}
 *   (for {@link #slaysHelpless()} outcomes, this alone is the full lethal damage amount, dice count/size are 0)
 * @param backstabDamageMultiplier COAB {@code ((thiefSkillLevel - 1) / 4) + 2} when {@link #backstab()}, else 1
 */
public record AttackOutcome(
	boolean hit,
	boolean slaysHelpless,
	int rawAttackRoll,
	int correctedAttackRoll,
	int totalToHitValue,
	int targetArmorClass,
	boolean backstab,
	boolean behindAttack,
	int damageDiceCount,
	int damageDiceSize,
	int damageBonus,
	int backstabDamageMultiplier
) {
}
