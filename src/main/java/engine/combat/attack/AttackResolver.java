package engine.combat.attack;

import java.util.Objects;
import java.util.function.IntSupplier;

/**
 * Hit/damage-input determination for a single attack swing, ported from COAB
 * (https://github.com/simeonpilgrim/coab, commit 9dc46f1):
 * <ul>
 * <li>engine/ovr024.cs: {@code CanHitTarget} (sub_641DD) and
 * {@code PC_CanHitTarget} (sub_64245).</li>
 * <li>engine/ovr025.cs: {@code CalculateAttackValues} (sub_66023) to-hit/damage
 * bonus assembly.</li>
 * <li>engine/ovr014.cs: the target-AC selection, backstab check
 * ({@code CanBackStabTarget}, sub_408D7) and large-weapon-dice swap inside
 * {@code AttackTarget01} (sub_3F4EB).</li>
 * </ul>
 *
 * <p>Given read-only {@link AttackerView}/{@link DefenderView} adapters, an
 * {@link AttackRuleset} and an injected d20 roll supplier, {@link #resolveSwing}
 * returns a structured {@link AttackOutcome} for one swing WITHOUT mutating
 * any combatant, consuming any attack pool, rolling damage dice or performing
 * any display/inventory side effect. The integrator drives the multi-swing
 * loop ({@code AttackTarget01}'s {@code for (attackIdx = actions.attackIdx;
 * attackIdx >= 1; attackIdx--) while (AttacksLeft(attackIdx) > 0) ...}) by
 * calling {@link #resolveSwing} once per remaining attack and applying each
 * outcome to their own combat state.</p>
 */
public final class AttackResolver {

	private AttackResolver() {
	}

	/**
	 * Result of a single d20 attack roll, shared by {@link #canHitTarget} and
	 * {@link #pcCanHitTarget}.
	 *
	 * @param hit whether this roll beats the target's AC under the caller's comparison rule
	 * @param rawAttackRoll the raw 1..20 roll before the natural-20 correction
	 * @param correctedAttackRoll the roll after COAB's natural-20-becomes-100 correction
	 *   (equal to {@code rawAttackRoll} otherwise, including on a natural-1 miss)
	 * @param totalToHitValue {@code correctedAttackRoll} plus whatever flat bonus the caller supplied
	 */
	public record AttackRollResult(boolean hit, int rawAttackRoll, int correctedAttackRoll, int totalToHitValue) {
	}

	/**
	 * Ported from COAB {@code ovr024.CanHitTarget} (sub_641DD): a general
	 * (non-team-bonus) hit check used outside the PC attack loop.
	 *
	 * <p>Quirks preserved faithfully: a natural 1 always misses without
	 * evaluating AC; a natural 20 is corrected to 100 before comparison (an
	 * effective always-hit against any plausible AC); the comparison is
	 * strictly-greater ({@code >}), unlike {@link #pcCanHitTarget}'s
	 * greater-or-equal. COAB's own redundant {@code if (gbl.attack_roll >= 0)}
	 * guard is elided here: given the {@code roll > 1} guard already passed
	 * and the roll only ever lands in {2..19} or is corrected to 100, that
	 * check is always true and never changes the result.</p>
	 *
	 * @param targetAc COAB {@code target.ac}
	 * @param flatToHitBonus COAB {@code bonus}, the caller's already-assembled to-hit bonus
	 * @param d20 injected 1..20 die roll (COAB {@code roll_dice(20, 1)})
	 */
	public static AttackRollResult canHitTarget(int targetAc, int flatToHitBonus, IntSupplier d20) {
		int raw = d20.getAsInt();
		if (raw > 1) {
			int corrected = raw == 20 ? 100 : raw;
			int total = corrected + flatToHitBonus;
			return new AttackRollResult(total > targetAc, raw, corrected, total);
		}
		return new AttackRollResult(false, raw, raw, raw + flatToHitBonus);
	}

	/**
	 * Ported from COAB {@code ovr024.PC_CanHitTarget} (sub_64245): the hit
	 * check used inside the player-character attack loop, folding in the
	 * attacker's assembled hit bonus and the combat-wide team bonus.
	 *
	 * <p>Same natural-1/natural-20 handling as {@link #canHitTarget}, but the
	 * comparison is greater-or-equal ({@code >=}) rather than strictly-greater
	 * -- ported faithfully as a genuine difference between the two COAB
	 * functions, not normalized away.</p>
	 *
	 * @param targetAc the AC for this swing (already includes any behind/backstab/ranged-defense
	 *   adjustment; COAB {@code target_ac} as computed inline in {@code AttackTarget01})
	 * @param attackerHitBonus COAB {@code attacker.hitBonus}, e.g. from {@link #toHitBonus}
	 * @param teamToHitBonus COAB {@code area2_ptr.field_6E2}/{@code field_6E0}; see
	 *   {@link AttackerView#teamToHitBonus()}
	 * @param d20 injected 1..20 die roll
	 */
	public static AttackRollResult pcCanHitTarget(int targetAc, int attackerHitBonus, int teamToHitBonus, IntSupplier d20) {
		int raw = d20.getAsInt();
		if (raw > 1) {
			int corrected = raw == 20 ? 100 : raw;
			int total = corrected + attackerHitBonus + teamToHitBonus;
			return new AttackRollResult(total >= targetAc, raw, corrected, total);
		}
		return new AttackRollResult(false, raw, raw, raw + attackerHitBonus + teamToHitBonus);
	}

	/**
	 * Ported from COAB {@code ovr025.CalculateAttackValues} (sub_66023)
	 * to-hit assembly.
	 *
	 * <p>Quirk preserved faithfully: {@link AttackerView#racialWeaponToHitBonus()}
	 * (the elvish bow/sword +1) is folded in here, but deliberately NOT in
	 * {@link #damageBonus} -- in COAB the elvish increment happens after
	 * {@code attack1_DamageBonus} is already assigned, so it only ever
	 * reaches the to-hit total.</p>
	 */
	public static int toHitBonus(AttackerView attacker, AttackRuleset ruleset) {
		Objects.requireNonNull(attacker, "attacker");
		Objects.requireNonNull(ruleset, "ruleset");
		int hitBonus = attacker.thac0();
		if (attacker.weaponAppliesDexterityToHit()) {
			hitBonus += ruleset.dexterityReactionToHitBonus(attacker.dexterityScore());
		}
		if (attacker.weaponIsMelee()) {
			hitBonus += ruleset.strengthToHitBonus(
				attacker.strengthScore(), attacker.strengthPercentile(), attacker.strengthBonusApplies());
		}
		int bonus = attacker.weaponMagicPlus();
		hitBonus += bonus;
		if (attacker.racialWeaponToHitBonus()) {
			hitBonus += 1;
		}
		return hitBonus;
	}

	/**
	 * Ported from COAB {@code ovr025.CalculateAttackValues} (sub_66023)
	 * damage-bonus assembly, using the normal (one-handed) weapon bonus. Call
	 * {@link #applyLargeWeaponDamageSwap} afterwards when the large-weapon
	 * dice swap applies for this swing.
	 */
	public static int damageBonus(AttackerView attacker, AttackRuleset ruleset) {
		Objects.requireNonNull(attacker, "attacker");
		Objects.requireNonNull(ruleset, "ruleset");
		int damageBonus = attacker.weaponBonusNormal();
		if (attacker.weaponIsMelee()) {
			damageBonus += ruleset.strengthDamageBonus(
				attacker.strengthScore(), attacker.strengthPercentile(), attacker.strengthBonusApplies());
		}
		damageBonus += attacker.weaponMagicPlus();
		return damageBonus;
	}

	/**
	 * Ported from the COAB {@code AttackTarget01} (sub_3F4EB) large-weapon
	 * override: {@code attacker.attack1_DamageBonus -= itemData.bonusNormal;
	 * attacker.attack1_DamageBonus += itemData.bonusLarge;}. Swaps only the
	 * flat weapon-bonus component of an already-assembled {@link #damageBonus}
	 * total, leaving the strength/magic components untouched.
	 */
	public static int applyLargeWeaponDamageSwap(int normalDamageBonus, AttackerView attacker) {
		return normalDamageBonus - attacker.weaponBonusNormal() + attacker.weaponBonusLarge();
	}

	/**
	 * Ported from COAB {@code ovr014.CanBackStabTarget} (sub_408D7).
	 */
	public static boolean canBackStabTarget(AttackerView attacker, DefenderView defender) {
		Objects.requireNonNull(attacker, "attacker");
		Objects.requireNonNull(defender, "defender");
		return attacker.canBackstabWithCurrentWeapon()
			&& defender.attacksReceivedThisRound() > 1
			&& (defender.positionFlags() & 0x7F) <= 1
			&& defender.attackerSharesFacingDirection();
	}

	/**
	 * Whether COAB's {@code target.field_DE > 0x80 || (target.field_DE & 7) > 1}
	 * large/two-handed weapon dice swap applies for this swing, from
	 * {@code AttackTarget01} (sub_3F4EB). Requires the attacker to have a
	 * weapon equipped at all (COAB checks {@code primaryWeapon != null}
	 * first).
	 */
	public static boolean largeWeaponDiceApply(AttackerView attacker, DefenderView defender) {
		if (!attacker.hasEquippedWeapon()) {
			return false;
		}
		int positionFlags = defender.positionFlags();
		return positionFlags > 0x80 || (positionFlags & 7) > 1;
	}

	/**
	 * Resolves one attack swing end to end: target-AC selection (backstab /
	 * behind / normal, plus ranged defense), to-hit/damage bonus assembly
	 * (including the large-weapon dice swap), and the {@code PC_CanHitTarget}
	 * roll -- ported from the relevant slice of COAB {@code AttackTarget01}'s
	 * per-swing loop body (sub_3F4EB).
	 *
	 * <p>Quirk preserved faithfully: the hit check is
	 * {@code PC_CanHitTarget(...) || target.IsHeld()} -- a target that became
	 * held between swings auto-hits without a roll even inside the normal
	 * per-swing loop, independent of the whole-turn {@link #slayHelplessOutcome}
	 * short-circuit COAB runs at the top of {@code AttackTarget01}.</p>
	 *
	 * @param attacker read-only attacker facts
	 * @param defender read-only defender facts
	 * @param ruleset the ability-score bonus table hook; use {@link NeutralAttackRuleset#INSTANCE}
	 *   unless the game/profile is confirmed classic AD&D
	 * @param behindAttackRequested COAB {@code arg_8 != 0} / {@code attackType != 0}: an explicit
	 *   request to attack from behind, as opposed to the auto-behind quirk this method also checks
	 * @param d20 injected 1..20 die roll supplier
	 */
	public static AttackOutcome resolveSwing(
		AttackerView attacker,
		DefenderView defender,
		AttackRuleset ruleset,
		boolean behindAttackRequested,
		IntSupplier d20
	) {
		Objects.requireNonNull(attacker, "attacker");
		Objects.requireNonNull(defender, "defender");
		Objects.requireNonNull(ruleset, "ruleset");
		Objects.requireNonNull(d20, "d20");

		boolean backstab = canBackStabTarget(attacker, defender);
		boolean behind = behindAttackRequested;
		int targetAc;
		if (backstab) {
			targetAc = defender.armorClassBehind() - 4;
		} else {
			if (defender.attacksReceivedThisRound() > 1
				&& defender.attackerSharesFacingDirection()
				&& defender.directionChangesThisRound() > 4) {
				behind = true;
			}
			targetAc = behind ? defender.armorClassBehind() : defender.armorClass();
		}
		targetAc += AttackTargetingRules.rangedDefenseBonus(
			attacker.isRangedWeapon(), attacker.rangedWeaponRange(), defender.rangeToAttacker());

		int hitBonus = toHitBonus(attacker, ruleset);

		boolean largeWeapon = largeWeaponDiceApply(attacker, defender);
		int diceCount = attacker.weaponDiceCountNormal();
		int diceSize = attacker.weaponDiceSizeNormal();
		int damageBonus = damageBonus(attacker, ruleset);
		if (largeWeapon) {
			damageBonus = applyLargeWeaponDamageSwap(damageBonus, attacker);
			diceCount = attacker.weaponDiceCountLarge();
			diceSize = attacker.weaponDiceSizeLarge();
		}

		AttackRollResult roll = pcCanHitTarget(targetAc, hitBonus, attacker.teamToHitBonus(), d20);
		boolean hit = roll.hit() || defender.isHeld();

		int backstabMultiplier = 1;
		if (backstab) {
			backstabMultiplier = ((attacker.thiefSkillLevel() - 1) / 4) + 2;
		}

		return new AttackOutcome(
			hit,
			false,
			roll.rawAttackRoll(),
			roll.correctedAttackRoll(),
			roll.totalToHitValue(),
			targetAc,
			backstab,
			behind,
			diceCount,
			diceSize,
			damageBonus,
			backstabMultiplier
		);
	}

	/**
	 * Ported from the top-of-function {@code target.IsHeld()} branch of COAB
	 * {@code AttackTarget01} (sub_3F4EB): a held/paralyzed target is slain
	 * automatically without a roll, for a lethal amount
	 * ({@code target.hit_point_current + 5}) that consumes the attacker's
	 * whole turn (both attack pools) rather than a single swing.
	 *
	 * <p>COAB's {@code DisplayAttackMessage} shows a nominal "1" point of
	 * damage in this case but actually applies {@code hit_point_current + 5};
	 * this method returns the lethal applied amount as {@link
	 * AttackOutcome#damageBonus()} (with zero dice, since none are rolled),
	 * since the display-only "1" has no effect outside COAB's UI.</p>
	 */
	public static AttackOutcome slayHelplessOutcome(DefenderView defender) {
		Objects.requireNonNull(defender, "defender");
		return new AttackOutcome(true, true, 0, 0, 0, defender.armorClass(), false, false, 0, 0,
			defender.currentHitPoints() + 5, 1);
	}
}
