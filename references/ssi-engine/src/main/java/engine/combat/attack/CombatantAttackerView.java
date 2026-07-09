package engine.combat.attack;

import java.util.Objects;

import engine.combat.Combatant;

/**
 * Adapts {@code engine.combat.Combatant} onto {@link AttackerView} for
 * {@link AttackResolver}.
 *
 * <p>{@link Combatant} deliberately stays free of AD&D-specific fields (see
 * {@link AttackerView}'s class javadoc), so this adapter maps only the
 * fields Combatant genuinely supplies and returns the documented
 * neutral/no-effect value for everything else. Nothing here is a Matrix
 * Cubed / Buck Rogers assertion -- fields marked "neutral/candidate" are
 * placeholders pending decoded Combatant data (ability scores, weapon
 * tables, ranged ammo, thief levels, ...); do not treat their return values
 * as evidence.</p>
 *
 * <h2>Descending Gold Box THAC0 vs. COAB's ascending to-hit math</h2>
 *
 * <p>The ported {@link AttackResolver} is COAB-internal ASCENDING: a
 * character's {@code player.thac0} is an ascending to-hit value that is
 * ADDED to the d20 roll ({@link AttackResolver#toHitBonus}:
 * {@code hitBonus = attacker.thac0()}), and {@code target.ac} is an
 * ascending AC where a hit needs {@code roll + hitBonus >= targetAc}
 * ({@link AttackResolver#pcCanHitTarget}; the natural-20-becomes-100 quirk
 * confirms {@code targetAc} is a small ascending number, higher = harder to
 * hit). {@code engine.combat.Combatant}, by contrast, carries classic
 * DESCENDING Gold Box values: {@code thac0} (e.g. 13, higher = worse) and
 * {@code armorClass} (e.g. 4, lower = better armor), whose hit rule is
 * {@code d20 >= thac0 - armorClass}.</p>
 *
 * <p>This adapter therefore converts, so that the resolver reproduces the
 * descending rule EXACTLY. Using a shared baseline {@code B}
 * ({@link #GOLD_BOX_ASCENDING_AC_BASELINE}):</p>
 * <ul>
 * <li>attacker ascending to-hit bonus = {@code B - Combatant.thac0()}
 * (this method), and</li>
 * <li>defender ascending AC = {@code B - Combatant.armorClass()}
 * ({@link CombatantDefenderView#armorClass()}).</li>
 * </ul>
 * <p>Then the resolver's {@code roll + (B - thac0) >= (B - armorClass)}
 * reduces to {@code roll >= thac0 - armorClass}, i.e. the outcome is
 * ALGEBRAICALLY INDEPENDENT of {@code B} (it cancels). {@code B} is only a
 * representational choice, not a fabricated formula. {@code B = 20} is used
 * because that is the canonical Gold Box / AD&D THAC0 meaning ("to hit AC
 * 0"): a 20-THAC0 attacker maps to a +0 bonus and AC 0 maps to ascending
 * 20, and the resolver's natural-20-becomes-100 quirk then behaves as an
 * always-hit against any plausible ascending AC. Labeled candidate: it
 * reproduces the descending rule exactly, but COAB's own stored
 * descending-to-ascending constant was not recovered from the local Matrix
 * Cubed binary during this pass.</p>
 *
 * <p>Directly mapped from Combatant:</p>
 * <ul>
 * <li>{@link #thac0()} -- {@code Combatant.thac0()} converted to the
 * ascending to-hit bonus {@code GOLD_BOX_ASCENDING_AC_BASELINE - thac0}
 * (see above); attacker skill still fully drives the hit chance.</li>
 * <li>weapon dice ({@link #weaponDiceCountNormal()}/{@link #weaponDiceSizeNormal()})
 * and {@link #weaponBonusNormal()} -- synthesized from {@code Combatant.damageMin()}/
 * {@code damageMax()} as a single die sized to cover the combatant's
 * damage range exactly (count=1, size = max-min+1, bonus = min-1), so that
 * {@code 1dSize + bonus} spans {@code [min, max]} inclusive. This is a
 * translation of Combatant's existing evidence-backed min/max damage into
 * the resolver's dice-shaped input, not a new weapon assertion. The large
 * (two-handed) dice fields mirror the same values since Combatant has no
 * separate large-grip stat and {@link CombatantDefenderView#positionFlags()}
 * is neutral (0), so {@link AttackResolver#largeWeaponDiceApply} never
 * selects them anyway.</li>
 * </ul>
 *
 * <p>Everything else returns the neutral/no-effect value documented on each
 * method below.</p>
 */
public final class CombatantAttackerView implements AttackerView {

	/**
	 * Baseline for the descending-THAC0 -> ascending-to-hit conversion (see
	 * class javadoc). {@code 20} = the canonical Gold Box "to hit AC 0"
	 * meaning; the hit outcome is algebraically independent of this value so
	 * long as {@link CombatantDefenderView} uses the same baseline for its
	 * ascending AC. Candidate pending a decoded COAB conversion constant.
	 */
	public static final int GOLD_BOX_ASCENDING_AC_BASELINE = 20;

	private final Combatant attacker;

	public CombatantAttackerView(Combatant attacker) {
		this.attacker = Objects.requireNonNull(attacker, "attacker");
	}

	/**
	 * Combatant's descending Gold Box THAC0 converted to COAB's ascending
	 * to-hit bonus form: {@code GOLD_BOX_ASCENDING_AC_BASELINE - thac0}. See
	 * class javadoc for why this reproduces {@code d20 >= thac0 - armorClass}
	 * exactly.
	 */
	@Override
	public int thac0() {
		return GOLD_BOX_ASCENDING_AC_BASELINE - attacker.thac0();
	}

	/** Neutral/candidate pending decoded Combatant ability scores: no strength score is modeled. */
	@Override
	public int strengthScore() {
		return 0;
	}

	/** Neutral/candidate pending decoded Combatant ability scores: no exceptional-strength percentile is modeled. */
	@Override
	public int strengthPercentile() {
		return 0;
	}

	/** Neutral/candidate pending decoded Combatant ability scores: no dexterity score is modeled. */
	@Override
	public int dexterityScore() {
		return 0;
	}

	/**
	 * Neutral: false, so {@link AttackRuleset#strengthToHitBonus}/{@link
	 * AttackRuleset#strengthDamageBonus} are never invoked with a nonzero
	 * result even under a future non-neutral ruleset. Candidate pending
	 * decoded Combatant field_125-equivalent data.
	 */
	@Override
	public boolean strengthBonusApplies() {
		return false;
	}

	/** Neutral/candidate pending decoded thief/skill-level data on Combatant: no backstab modeling yet. */
	@Override
	public int thiefSkillLevel() {
		return 0;
	}

	/**
	 * Neutral-true: Combatant's damage range is treated as an ordinary melee
	 * weapon (see class javadoc). Under {@link NeutralAttackRuleset} this has
	 * no numeric effect since the strength bonus methods return 0 regardless.
	 */
	@Override
	public boolean weaponIsMelee() {
		return true;
	}

	/** Neutral/candidate: no per-weapon finesse/missile flag is modeled on Combatant. */
	@Override
	public boolean weaponAppliesDexterityToHit() {
		return false;
	}

	/**
	 * Neutral-true: every Combatant carries a synthesized basic melee weapon
	 * (see class javadoc), so it is always treated as equipped.
	 */
	@Override
	public boolean hasEquippedWeapon() {
		return true;
	}

	/** Neutral/candidate pending decoded thief/weapon-type data: backstab is never available. */
	@Override
	public boolean canBackstabWithCurrentWeapon() {
		return false;
	}

	/** Synthesized weapon bonus; see class javadoc. */
	@Override
	public int weaponBonusNormal() {
		return attacker.damageMin() - 1;
	}

	/** Mirrors {@link #weaponBonusNormal()}; see class javadoc. */
	@Override
	public int weaponBonusLarge() {
		return attacker.damageMin() - 1;
	}

	/** Synthesized single-die weapon shape; see class javadoc. */
	@Override
	public int weaponDiceCountNormal() {
		return 1;
	}

	/** Synthesized weapon die size spanning the combatant's damage range; see class javadoc. */
	@Override
	public int weaponDiceSizeNormal() {
		return attacker.damageMax() - attacker.damageMin() + 1;
	}

	/** Mirrors {@link #weaponDiceCountNormal()}; see class javadoc. */
	@Override
	public int weaponDiceCountLarge() {
		return 1;
	}

	/** Mirrors {@link #weaponDiceSizeNormal()}; see class javadoc. */
	@Override
	public int weaponDiceSizeLarge() {
		return attacker.damageMax() - attacker.damageMin() + 1;
	}

	/** Neutral/candidate pending decoded magic-item data on Combatant: no enchantment bonus is modeled. */
	@Override
	public int weaponMagicPlus() {
		return 0;
	}

	/** Neutral/candidate pending decoded race/weapon-type data on Combatant: no elvish weapon bonus is modeled. */
	@Override
	public boolean racialWeaponToHitBonus() {
		return false;
	}

	/** Neutral/candidate pending a decoded combat-wide team-bonus pool: no team to-hit bonus is modeled. */
	@Override
	public int teamToHitBonus() {
		return 0;
	}

	/** Neutral/candidate pending decoded weapon-type data on Combatant: no ranged weapons are modeled yet. */
	@Override
	public boolean isRangedWeapon() {
		return false;
	}

	/** Neutral/candidate: meaningless while {@link #isRangedWeapon()} is false. */
	@Override
	public int rangedWeaponRange() {
		return 0;
	}

	/** Neutral: a single attack per round, matching the old scaffold's one-swing-per-attack() call contract. */
	@Override
	public int attacksCount() {
		return 1;
	}

	/** Neutral/candidate pending decoded ranged-ammo data on Combatant: no ranged attack item is modeled. */
	@Override
	public boolean rangedAttackItemResolved() {
		return false;
	}

	/** Neutral/candidate: meaningless while {@link #rangedAttackItemResolved()} is false. */
	@Override
	public int rangedWeaponNumberAttacks() {
		return 0;
	}

	/** Neutral/candidate: meaningless while {@link #rangedAttackItemResolved()} is false. */
	@Override
	public int rangedAmmoCount() {
		return 0;
	}

	/** Neutral/candidate pending decoded per-round action-state data on Combatant: unrecovered COAB field, left false. */
	@Override
	public boolean actionsField8() {
		return false;
	}
}
