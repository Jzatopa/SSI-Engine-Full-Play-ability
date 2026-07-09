package engine.combat.ai;

import static org.junit.Assert.assertEquals;
import static org.junit.Assert.assertFalse;
import static org.junit.Assert.assertTrue;

import java.util.List;

import org.junit.Test;

import engine.combat.CombatState;
import engine.combat.Combatant;

public class CombatStateQuickFightViewTest {
	@Test
	public void exposesLivingCombatantsAndMeleeGeometry() {
		CombatState state = CombatState.ratwurstVerticalSlice();
		CombatStateQuickFightView view = new CombatStateQuickFightView(state);
		Combatant party = state.livingParty().get(0);
		Combatant monster = state.livingMonsters().get(0);

		QuickFightCombatantView partyView = view.viewFor(party).orElseThrow();
		QuickFightCombatantView monsterView = view.viewFor(monster).orElseThrow();

		assertEquals(party.id(), partyView.id());
		assertEquals(QuickFightTeam.OURS, partyView.team());
		assertEquals(QuickFightTeam.ENEMY, monsterView.team());
		assertTrue(view.canSee(partyView, monsterView));
		assertTrue(view.pathStepsTo(partyView, monsterView).isPresent());
		assertEquals(view.pathStepsTo(partyView, monsterView).orElseThrow() / 2,
			view.distanceTo(partyView, monsterView));
	}

	@Test
	public void filtersAndSortsEnemiesForThePlanner() {
		CombatState state = CombatState.ratwurstVerticalSlice();
		CombatStateQuickFightView view = new CombatStateQuickFightView(state);
		Combatant monster = state.livingMonsters().get(0);
		monster.moveTo(state.livingParty().get(0).position().translate(1, 0));
		QuickFightCombatantView monsterView = view.viewFor(monster).orElseThrow();

		List<QuickFightCombatantView> adjacent = view.enemiesWithin(monsterView, 1, false);
		assertFalse(adjacent.isEmpty());
		assertTrue(adjacent.stream().allMatch(enemy -> enemy.team() == QuickFightTeam.OURS));
		assertEquals(state.livingParty().get(0).id(), adjacent.get(0).id());
	}

	@Test
	public void keepsUnsupportedCapabilitiesNeutral() {
		CombatState state = CombatState.ratwurstVerticalSlice();
		CombatStateQuickFightView view = new CombatStateQuickFightView(state);
		QuickFightCombatantView monster = view.viewFor(state.livingMonsters().get(0)).orElseThrow();

		assertFalse(monster.canCastSpells());
		assertFalse(monster.canUseItems());
		assertFalse(monster.npcControlled());
		assertFalse(monster.hasRangedWeapon());
		assertEquals(0, monster.primaryWeaponRawRange());
		assertFalse(view.areaForbidsSpells());
		assertFalse(view.autoPartyCastsMagic());
	}
}
