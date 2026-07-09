package engine.combat.attack;

/**
 * Read-only attacker-side facts needed by {@link AttackResolver}, {@link AttackTargetingRules}
 * and {@link AttacksPerRoundCalculator}.
 *
 * <p>Ported from COAB (https://github.com/simeonpilgrim/coab, commit 9dc46f1)
 * engine/ovr014.cs ({@code AttackTarget}/{@code AttackTarget01}, sub_3F9DB /
 * sub_3F4EB) and engine/ovr025.cs ({@code CalculateAttackValues}, sub_66023),
 * which read these facts off {@code Classes.Player}. This engine keeps
 * {@code engine.combat.Combatant} frozen and free of AD&D-specific fields
 * (strength/dexterity scores, weapon dice, thief level, ...), so the
 * integrator supplies a small adapter implementing this interface rather than
 * this package reaching into Combatant directly.</p>
 *
 * <p>Some COAB fields consumed by the ported control flow (notably
 * {@code field_125} and {@code field_DE}) never had their real meaning
 * recovered from decompilation. Where this interface exposes such a field, the
 * javadoc says so explicitly; the corresponding getter is named for its COAB
 * role, not asserted semantics.</p>
 */
public interface AttackerView {

	/** COAB {@code player.thac0}: base to-hit value before any bonuses. */
	int thac0();

	/**
	 * COAB {@code player.stats2.Str.full} (1-25), the AD&D flavor's raw
	 * strength score. Feeds {@link AttackRuleset#strengthToHitBonus} /
	 * {@link AttackRuleset#strengthDamageBonus} via {@code ovr025.player_strength_group}.
	 */
	int strengthScore();

	/**
	 * COAB {@code player.stats2.Str00.cur} (0-100), the exceptional-strength
	 * percentile used only when {@link #strengthScore()} is 18.
	 */
	int strengthPercentile();

	/** COAB {@code player.stats2.Dex.full} (0-25). */
	int dexterityScore();

	/**
	 * COAB {@code player.field_125 != 0}: an unlabeled per-attacker flag that
	 * gates whether {@code strengthHitBonus}/{@code strengthDamBonus} return a
	 * nonzero value at all (both tables zero out their result when this is
	 * false). Meaning not recovered; treat as true for an ordinary attack
	 * unless local evidence says otherwise.
	 */
	boolean strengthBonusApplies();

	/**
	 * COAB {@code attacker.SkillLevel(SkillType.Thief)}, or 0 if the attacker
	 * has no thief levels. Used only for the backstab damage multiplier
	 * {@code ((thiefSkillLevel - 1) / 4) + 2}.
	 */
	int thiefSkillLevel();

	/**
	 * COAB {@code (ItemDataTable[item_type].field_E & ItemDataFlags.melee) != 0}
	 * for the attacker's equipped weapon: gates whether strength to-hit/damage
	 * bonuses apply to this attack at all.
	 */
	boolean weaponIsMelee();

	/**
	 * COAB {@code (ItemDataTable[item_type].field_E & ItemDataFlags.flag_02) != 0}:
	 * an unlabeled item-data flag that gates whether
	 * {@code ovr025.DexReactionAdj} is folded into the to-hit bonus. Observed
	 * on some (not all) weapons; likely a finesse/missile marker, not
	 * confirmed.
	 */
	boolean weaponAppliesDexterityToHit();

	/** COAB {@code attacker.activeItems.primaryWeapon != null}. */
	boolean hasEquippedWeapon();

	/**
	 * Pre-resolved COAB {@code ovr014.CanBackStabTarget} (sub_408D7) weapon
	 * gate: {@code attacker.SkillLevel(Thief) > 0} AND the equipped weapon is
	 * null (unarmed) or one of DrowLongSword/Club/Dagger/BroadSword/LongSword/
	 * ShortSword. The integrator resolves the weapon-type check; this
	 * interface only exposes the combined boolean to avoid depending on a
	 * COAB-specific item-type enum.
	 */
	boolean canBackstabWithCurrentWeapon();

	/** COAB {@code ItemDataTable[item_type].bonusNormal}: flat weapon damage bonus, normal (one-handed) grip. */
	int weaponBonusNormal();

	/** COAB {@code ItemDataTable[item_type].bonusLarge}: flat weapon damage bonus, large (two-handed/roomy) grip. */
	int weaponBonusLarge();

	/** COAB {@code ItemDataTable[item_type].diceCountNormal}. */
	int weaponDiceCountNormal();

	/** COAB {@code ItemDataTable[item_type].diceSizeNormal}. */
	int weaponDiceSizeNormal();

	/** COAB {@code ItemDataTable[item_type].diceCountLarge}. */
	int weaponDiceCountLarge();

	/** COAB {@code ItemDataTable[item_type].diceSizeLarge}. */
	int weaponDiceSizeLarge();

	/**
	 * COAB {@code item.plus} plus any equipped quarrels'/arrows' {@code plus},
	 * pre-summed by the integrator (COAB {@code CalculateAttackValues} local
	 * variable {@code bonus} before the elvish +1 is folded in). Applied to
	 * both the to-hit bonus and the damage bonus.
	 */
	int weaponMagicPlus();

	/**
	 * COAB elvish weapon bonus: {@code player.race == Race.elf} and the
	 * equipped weapon is a composite/long/short bow or long/short sword.
	 * Deliberately asymmetric in the original: this adds +1 to the to-hit
	 * bonus only, never to the damage bonus (the elvish increment happens
	 * after {@code attack1_DamageBonus} is already assigned).
	 */
	boolean racialWeaponToHitBonus();

	/**
	 * COAB {@code area2_ptr.field_6E2} (attacker on {@code CombatTeam.Ours})
	 * or {@code area2_ptr.field_6E0} (otherwise): a combat-wide to-hit bonus
	 * pool. The integrator picks the value for the attacker's side.
	 */
	int teamToHitBonus();

	/** COAB {@code ovr025.is_weapon_ranged(attacker)}. */
	boolean isRangedWeapon();

	/**
	 * COAB {@code ItemDataTable[primaryWeapon.type].range}, meaningful only
	 * when {@link #isRangedWeapon()} is true.
	 */
	int rangedWeaponRange();

	// -- reclac_attacks (sub_3EDD4) inputs --

	/** COAB {@code player.attacksCount}: base attacks-per-round before ranged/round adjustments. */
	int attacksCount();

	/**
	 * COAB {@code ovr025.is_weapon_ranged(player) && ovr025.GetCurrentAttackItem(out rangedItem, player)}:
	 * true when the attacker is wielding a ranged weapon AND has ammunition
	 * resolvable this round.
	 */
	boolean rangedAttackItemResolved();

	/** COAB {@code ItemDataTable[primaryWeapon.type].numberAttacks}, meaningful only when {@link #rangedAttackItemResolved()}. */
	int rangedWeaponNumberAttacks();

	/** COAB {@code rangedItem.count}, meaningful only when {@link #rangedAttackItemResolved()}. */
	int rangedAmmoCount();

	/**
	 * COAB {@code player.actions.field_8}: an unlabeled per-round flag read by
	 * {@code reclac_attacks}. Set true elsewhere once an attacker has already
	 * acted once this action-phase; meaning not independently confirmed.
	 */
	boolean actionsField8();
}
