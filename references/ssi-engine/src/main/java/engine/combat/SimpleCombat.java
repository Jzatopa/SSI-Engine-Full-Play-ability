package engine.combat;

import java.util.Random;

import character.AbilityScore;
import character.CharacterClass;
import character.buckrogers.AbilityScoreBuckRogers;
import character.buckrogers.CharacterClassBuckRogers;
import data.character.AbstractCharacter;

public class SimpleCombat {
	private static final long DEFAULT_SEED = 52017L;

	public CombatResult resolve(AbstractCharacter monster) {
		return resolve(monster, DEFAULT_SEED);
	}

	public CombatResult resolve(AbstractCharacter monster, long seed) {
		Combatant hero = Combatant.hero();
		Combatant enemy = Combatant.fromMonster(monster);
		StringBuilder log = new StringBuilder();
		Random random = new Random(seed);

		log.append("COMBAT: ").append(enemy.name).append('\n');
		log.append("Enemy HP ").append(enemy.hp).append(" AC ").append(enemy.ac).append(" THAC0 ").append(enemy.thac0)
			.append(" Damage ").append(enemy.damageMin).append("-").append(enemy.damageMax).append('\n');

		int round = 0;
		while (hero.hp > 0 && enemy.hp > 0 && round < 20) {
			round++;
			log.append("Round ").append(round).append(": ");
			attack(random, hero, enemy, log);
			if (enemy.hp > 0) {
				log.append("; ");
				attack(random, enemy, hero, log);
			}
			log.append('\n');
		}

		boolean victory = hero.hp > 0 && enemy.hp <= 0;
		int combatResult = victory ? 0 : 1;
		log.append(victory ? "Victory." : "Defeat or unresolved.").append(" COMBAT_RESULT=").append(combatResult);
		return new CombatResult(combatResult, log.toString(), enemy.name);
	}

	private void attack(Random random, Combatant attacker, Combatant defender, StringBuilder log) {
		int roll = random.nextInt(20) + 1;
		int needed = Math.max(1, attacker.thac0 - defender.ac);
		if (roll >= needed) {
			int damage = attacker.damageMin + random.nextInt(attacker.damageMax - attacker.damageMin + 1);
			defender.hp = Math.max(0, defender.hp - damage);
			log.append(attacker.name).append(" hit ").append(defender.name).append(" for ").append(damage).append(" (HP ")
				.append(defender.hp).append(")");
		} else {
			log.append(attacker.name).append(" missed");
		}
	}

	public static final class CombatResult {
		public final int combatResult;
		public final String transcript;
		public final String enemyName;

		public CombatResult(int combatResult, String transcript, String enemyName) {
			this.combatResult = combatResult;
			this.transcript = transcript;
			this.enemyName = enemyName;
		}
	}

	private static final class Combatant {
		final String name;
		final int ac;
		final int thac0;
		final int damageMin;
		final int damageMax;
		int hp;

		Combatant(String name, int hp, int ac, int thac0, int damageMin, int damageMax) {
			this.name = name;
			this.hp = hp;
			this.ac = ac;
			this.thac0 = thac0;
			this.damageMin = damageMin;
			this.damageMax = damageMax;
		}

		static Combatant hero() {
			return new Combatant("Test Hero", 100, 10, 14, 8, 14);
		}

		static Combatant fromMonster(AbstractCharacter monster) {
			String name = monster.getName().trim();
			if (name.isEmpty()) {
				name = "Monster";
			}
			int hp = Math.max(1, monster.getNaturalHP());
			int dex = stat(monster, AbilityScoreBuckRogers.DEXTERITY);
			int str = stat(monster, AbilityScoreBuckRogers.STRENGTH);
			int level = Math.max(1, level(monster));
			int ac = Math.max(0, Math.min(20, 10 - ((dex - 10) / 2)));
			int thac0 = Math.max(5, 21 - level);
			int damageMin = Math.max(1, str / 6);
			int damageMax = Math.max(damageMin, damageMin + Math.max(1, str / 3));
			return new Combatant(name, hp, ac, thac0, damageMin, damageMax);
		}

		private static int stat(AbstractCharacter monster, AbilityScore stat) {
			return Math.max(1, monster.getCurrentStatValue(stat));
		}

		private static int level(AbstractCharacter monster) {
			CharacterClass charClass = monster.getClassSelection().getClass(CharacterClassBuckRogers.class, 0);
			if (charClass == null) {
				charClass = CharacterClassBuckRogers.WARRIOR;
			}
			try {
				return monster.getLevel(charClass);
			} catch (IllegalArgumentException e) {
				return 1;
			}
		}
	}
}
