package engine.combat.ai;

/**
 * Read-only per-combatant facts consumed by {@link QuickFightPlanner}.
 *
 * <p>Ported from COAB (https://github.com/simeonpilgrim/coab, commit 9dc46f1)
 * engine/ovr010.cs {@code PlayerQuickFight} and helpers, which read these
 * facts off {@code Classes.Player} and {@code Classes.Combat.Action}. This
 * engine keeps {@code engine.combat.Combatant} frozen and free of
 * game-specific fields, so the integrator supplies an adapter implementing
 * this interface; the planner never mutates anything through it.</p>
 *
 * <p>Methods marked "flavor hook" wrap AD&D-specific class/level semantics
 * from COAB's Player fields. They are ruleset flavor, not Matrix Cubed
 * evidence — a Buck Rogers adapter decides what (if anything) they map to.</p>
 */
public interface QuickFightCombatantView {
	/** COAB sentinel: {@code getTargetRange} returns 0xFF when no path exists. */
	int UNREACHABLE = 0xFF;

	/** Stable identity used by the planner's remembered-target map ({@code actions.target}). */
	int id();

	/** COAB {@code Player.in_combat}. */
	boolean inCombat();

	/** COAB {@code Player.combat_team}. */
	QuickFightTeam team();

	/** COAB {@code Player.hit_point_current}. */
	int hitPointsCurrent();

	/** COAB {@code Player.hit_point_max}. */
	int hitPointsMax();

	/**
	 * Full-round movement allowance, the result of COAB
	 * {@code ovr014.CalcMoves} (sub_3E124) including movement affects. The
	 * planner treats it as a supplied fact because the affect hooks live with
	 * the movement track.
	 */
	int movementPoints();

	/** COAB {@code actions.move}: movement points left this turn. */
	int movePointsLeft();

	/** COAB {@code actions.delay}: initiative delay left this turn. */
	int delayLeft();

	/** COAB {@code actions.fleeing}: forced to flee (fear, turn undead, ...). */
	boolean forcedFleeing();

	/** COAB {@code Player.IsHeld()}. */
	boolean held();

	/** COAB {@code Player.stats2.Int.full}: drives the surrender-vs-panic split. */
	int intelligence();

	/** COAB {@code control_morale >= Control.NPC_Base} (0x80): AI morale rules apply. */
	boolean npcControlled();

	/** COAB {@code control_morale & Control.PC_Mask} (0x7F): raw morale score. */
	int moraleScore();

	/** COAB {@code activeItems.armor != null}. */
	boolean wearsArmor();

	/**
	 * Flavor hook for COAB {@code Player._class == ClassId.magic_user}: an
	 * unarmored member of this class stands and guards instead of closing in
	 * ({@code moralFailureEscape}). AD&D flavor, not Matrix Cubed evidence.
	 */
	boolean fragileCaster();

	/**
	 * Flavor hook for COAB {@code ovr010.turn_undead}'s class gate:
	 * {@code cleric_lvl > 0 || cleric_old_lvl > multiclassLevel}. AD&D flavor,
	 * not Matrix Cubed evidence; a game without turning simply returns false.
	 */
	boolean canTurnUndead();

	/** COAB {@code actions.hasTurnedUndead}: one turning attempt per combat. */
	boolean hasTurnedUndead();

	/**
	 * COAB {@code Player.field_E9}: undead turning rank, 0 for non-undead.
	 * {@code ovr014.FindLowestE9Target} treats lower positive values as easier
	 * to turn and ignores values >= 13.
	 */
	int undeadRank();

	/** COAB {@code actions.spell_id}: spell queued before this turn (0 = none). */
	int queuedSpellId();

	/** COAB {@code actions.can_cast}. */
	boolean canCastSpells();

	/** COAB {@code actions.can_use}: may activate magic items this turn. */
	boolean canUseItems();

	/** COAB {@code ovr025.is_weapon_ranged}: readied primary weapon is ranged. */
	boolean hasRangedWeapon();

	/** COAB {@code ovr025.is_weapon_ranged_melee}: ranged weapon also usable in melee. */
	boolean hasRangedMeleeWeapon();

	/**
	 * Raw item-table range of the readied primary weapon (COAB
	 * {@code ItemDataTable[primaryWeapon.type].range}); return 0 when
	 * unarmed. The planner applies {@code sub_35DB1}'s own {@code range - 1}
	 * / clamp-to-1 handling.
	 */
	int primaryWeaponRawRange();

	/**
	 * COAB {@code spellList.LearntList()}: castable memorized spell ids, or an
	 * empty array. Order matters — {@code sub_3560B} indexes it with a die roll.
	 */
	int[] learntSpellIds();

	/**
	 * Spell ids offered by readied charged items, mirroring the item filter in
	 * COAB {@code sub_354AA}: readied, not a scroll, {@code affect_3 < 0x80},
	 * {@code affect_2 > 0}, with ids above 0x38 remapped down by 0x17. The
	 * adapter applies that filter/remap (item-model detail); order matters —
	 * the wand scan takes the first judged-castable id per priority.
	 */
	int[] readiedItemSpellIds();
}
