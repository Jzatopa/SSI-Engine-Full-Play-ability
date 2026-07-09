package engine.combat.attack;

/**
 * Universal-engine hook for the ability-score bonus tables COAB mixes into
 * attack rolls and damage.
 *
 * <p>Buck Rogers: Matrix Cubed does not use classic AD&D ability scores (or,
 * if it does, the mapping to combat bonuses has not been recovered from
 * evidence). To keep the Java engine safe for other Gold Box games while not
 * asserting unverified Matrix Cubed formulas, {@link AttackResolver} and
 * friends take this interface rather than a hardcoded table.</p>
 *
 * <ul>
 * <li>{@link NeutralAttackRuleset} is the default/neutral hook: every method
 * returns 0. This is the correct choice for Buck Rogers until its own
 * stat-to-combat-bonus formulas are recovered -- candidate/unresolved, not an
 * assertion that Matrix Cubed lacks such bonuses.</li>
 * <li>{@link AdndAttackRuleset} supplies the COAB reference values, ported
 * from COAB (https://github.com/simeonpilgrim/coab, commit 9dc46f1)
 * engine/ovr025.cs. Labeled AD&D flavor, ported from COAB, NOT Matrix Cubed
 * evidence; only appropriate for a game/ruleset profile that is actually
 * classic AD&D.</li>
 * </ul>
 */
public interface AttackRuleset {

	/**
	 * COAB {@code ovr025.strengthHitBonus} (uses {@code ovr025.player_strength_group}
	 * internally to fold {@code strengthPercentile} in when {@code strengthScore == 18}).
	 */
	int strengthToHitBonus(int strengthScore, int strengthPercentile, boolean strengthBonusApplies);

	/** COAB {@code ovr025.strengthDamBonus}. */
	int strengthDamageBonus(int strengthScore, int strengthPercentile, boolean strengthBonusApplies);

	/**
	 * COAB {@code ovr025.DexAcBonus} ({@code stat_bonus}). Not consumed
	 * directly by {@link AttackResolver} -- {@link DefenderView#armorClass()}
	 * is expected to already have this folded in by the integrator's own
	 * AC-assembly pipeline (COAB {@code reclac_player_values}, out of this
	 * package's scope) -- but exposed here since it is one of the three named
	 * ovr025 tables this package ports.
	 */
	int dexterityArmorClassBonus(int dexterityScore);

	/** COAB {@code ovr025.DexReactionAdj}. */
	int dexterityReactionToHitBonus(int dexterityScore);
}
