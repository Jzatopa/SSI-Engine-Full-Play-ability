package engine.combat.attack;

/**
 * AD&D flavor, ported from COAB, NOT Matrix Cubed evidence.
 *
 * <p>Ported from COAB (https://github.com/simeonpilgrim/coab, commit 9dc46f1)
 * engine/ovr025.cs: {@code player_strength_group}, {@code strengthHitBonus},
 * {@code strengthDamBonus}, {@code DexAcBonus} ({@code stat_bonus}) and
 * {@code DexReactionAdj}. These are classic AD&D ability-score tables baked
 * into the original Gold Box engine; only wire this ruleset in for a
 * game/profile confirmed to use AD&D ability scores. Buck Rogers: Matrix
 * Cubed should use {@link NeutralAttackRuleset} until its own tables are
 * recovered.</p>
 */
public final class AdndAttackRuleset implements AttackRuleset {

	public static final AdndAttackRuleset INSTANCE = new AdndAttackRuleset();

	/**
	 * COAB {@code ovr025.player_strength_group} ({@code playerStrengh}):
	 * folds 18/xx exceptional strength into the 19-23 band used by the bonus
	 * tables below.
	 *
	 * @throws IllegalArgumentException for strength scores COAB's own
	 *   {@code NotSupportedException} branches reject (outside 0..25).
	 */
	static int strengthGroup(int strengthScore, int strengthPercentile) {
		if (strengthScore >= 0 && strengthScore <= 17) {
			return strengthScore;
		}
		if (strengthScore == 18) {
			if (strengthPercentile == 0) {
				return 18;
			} else if (strengthPercentile >= 1 && strengthPercentile <= 50) {
				return 19;
			} else if (strengthPercentile >= 51 && strengthPercentile <= 75) {
				return 20;
			} else if (strengthPercentile >= 76 && strengthPercentile <= 90) {
				return 21;
			} else if (strengthPercentile >= 91 && strengthPercentile <= 99) {
				return 22;
			} else if (strengthPercentile >= 100) {
				return 23;
			}
			throw new IllegalArgumentException("unsupported strength percentile: " + strengthPercentile);
		}
		if (strengthScore >= 19 && strengthScore <= 25) {
			return strengthScore + 5;
		}
		throw new IllegalArgumentException("unsupported strength score: " + strengthScore);
	}

	@Override
	public int strengthToHitBonus(int strengthScore, int strengthPercentile, boolean strengthBonusApplies) {
		if (!strengthBonusApplies) {
			return 0;
		}
		int group = strengthGroup(strengthScore, strengthPercentile);
		if (group >= 1 && group <= 3) {
			return -3;
		} else if (group == 4 || group == 5) {
			return -2;
		} else if (group == 6 || group == 7) {
			return -1;
		} else if (group >= 17 && group <= 19) {
			return 1;
		} else if (group >= 20 && group <= 22) {
			return 2;
		} else if (group >= 23 && group <= 25) {
			return 3;
		} else if (group == 26 || group == 27) {
			return 4;
		} else if (group >= 28 && group <= 30) {
			return group - 23;
		}
		return 0;
	}

	@Override
	public int strengthDamageBonus(int strengthScore, int strengthPercentile, boolean strengthBonusApplies) {
		if (!strengthBonusApplies) {
			return 0;
		}
		int group = strengthGroup(strengthScore, strengthPercentile);
		if (group == 1 || group == 2) {
			return -2;
		} else if (group >= 3 && group <= 5) {
			return -1;
		} else if (group == 16) {
			return 1;
		} else if (group >= 17 && group <= 19) {
			return group - 16;
		} else if (group >= 20 && group <= 29) {
			return group - 17;
		} else if (group == 30) {
			return 14;
		}
		return 0;
	}

	@Override
	public int dexterityArmorClassBonus(int dexterityScore) {
		if (dexterityScore >= 1 && dexterityScore <= 3) {
			return -4;
		} else if (dexterityScore >= 4 && dexterityScore <= 6) {
			return dexterityScore - 7;
		} else if (dexterityScore >= 15 && dexterityScore <= 18) {
			return dexterityScore - 14;
		} else if (dexterityScore == 19 || dexterityScore == 20) {
			return 4;
		} else if (dexterityScore >= 21 && dexterityScore <= 23) {
			return 5;
		} else if (dexterityScore == 24 || dexterityScore == 25) {
			return 6;
		}
		return 0;
	}

	@Override
	public int dexterityReactionToHitBonus(int dexterityScore) {
		if (dexterityScore >= 0 && dexterityScore <= 2) {
			return -4;
		} else if (dexterityScore >= 3 && dexterityScore <= 5) {
			return dexterityScore - 6;
		} else if (dexterityScore >= 16 && dexterityScore <= 18) {
			return dexterityScore - 15;
		} else if (dexterityScore >= 19 && dexterityScore <= 20) {
			return 3;
		} else if (dexterityScore >= 21 && dexterityScore <= 23) {
			return 4;
		} else if (dexterityScore >= 24 && dexterityScore <= 25) {
			return 5;
		}
		return 0;
	}
}
