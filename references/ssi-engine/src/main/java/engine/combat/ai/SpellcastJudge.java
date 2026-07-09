package engine.combat.ai;

/**
 * Boundary interface: "would this spell be worth casting right now?".
 *
 * <p>Ported from COAB (https://github.com/simeonpilgrim/coab, commit 9dc46f1)
 * engine/ovr010.cs {@code ShouldCastSpellX} (sub_353B1) and its helper
 * {@code ShouldCastSpellX_sub1} (sub_352AF) — as an interface, not a port.
 * Those routines are spell-table and saving-throw math (spell priority
 * lookup, range, area shape, {@code RollSavingThrow} against friendlies in
 * the blast), which is attack/spell resolution rather than decision
 * structure, so it belongs to the spell/attack track. The quick-fight
 * planner only consumes the boolean and preserves COAB's calling pattern:
 * the wand scan ({@code sub_354AA}) and the known-spell scan
 * ({@code sub_3560B}) both probe candidate spells against a descending
 * minimum priority.</p>
 */
public interface SpellcastJudge {
	/** No spell is ever judged worth casting; the planner then never emits a cast intent. */
	SpellcastJudge NONE = (minPriority, spellId, caster) -> false;

	/**
	 * COAB {@code ShouldCastSpellX(minPriority, spellId, attacker)}: true when
	 * the spell's table priority meets {@code minPriority} and a worthwhile,
	 * friendly-fire-safe use exists from the caster's position.
	 */
	boolean shouldCast(int minPriority, int spellId, QuickFightCombatantView caster);
}
