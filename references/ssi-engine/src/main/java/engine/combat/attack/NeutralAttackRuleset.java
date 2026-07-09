package engine.combat.attack;

/**
 * Default/neutral {@link AttackRuleset}: every ability-score adjustment is 0.
 *
 * <p>This is the correct ruleset hook for Buck Rogers: Matrix Cubed until its
 * own stat-to-combat-bonus formulas are recovered from evidence --
 * candidate/unresolved, not an assertion that Matrix Cubed has no such
 * bonuses. See {@link AttackRuleset} for the universal-engine boundary this
 * class sits behind.</p>
 */
public final class NeutralAttackRuleset implements AttackRuleset {

	public static final NeutralAttackRuleset INSTANCE = new NeutralAttackRuleset();

	@Override
	public int strengthToHitBonus(int strengthScore, int strengthPercentile, boolean strengthBonusApplies) {
		return 0;
	}

	@Override
	public int strengthDamageBonus(int strengthScore, int strengthPercentile, boolean strengthBonusApplies) {
		return 0;
	}

	@Override
	public int dexterityArmorClassBonus(int dexterityScore) {
		return 0;
	}

	@Override
	public int dexterityReactionToHitBonus(int dexterityScore) {
		return 0;
	}
}
