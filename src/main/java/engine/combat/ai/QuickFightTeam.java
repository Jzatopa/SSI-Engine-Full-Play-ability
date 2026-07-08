package engine.combat.ai;

/**
 * Combat side as the quick-fight AI sees it.
 *
 * <p>Ported from COAB (https://github.com/simeonpilgrim/coab, commit 9dc46f1)
 * Classes/Enums.cs {@code CombatTeam} and Classes/Player.cs
 * {@code OppositeTeam()}. COAB's quick-fight decision code only ever asks
 * "same team or not" and "is this the party's side", so the two-value form is
 * kept; this package deliberately does not reuse
 * {@code engine.combat.Combatant.Side} so the planner stays decoupled from
 * the frozen combat scaffold.</p>
 */
public enum QuickFightTeam {
	/** COAB {@code CombatTeam.Ours}: the party's side. */
	OURS,
	/** COAB {@code CombatTeam.Enemy}: the opposing side. */
	ENEMY;

	/** COAB Player.OppositeTeam(). */
	public QuickFightTeam opposite() {
		return this == OURS ? ENEMY : OURS;
	}
}
