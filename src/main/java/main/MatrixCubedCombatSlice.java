package main;

import java.util.Random;

import character.AbilityScore;
import character.buckrogers.AbilityScoreBuckRogers;
import common.FileMap;
import data.ContentType;
import data.Resource;
import data.ResourceLoader;
import data.character.AbstractCharacter;
import data.character.CharacterBuckRogers;
import data.character.CharacterValues;
import engine.combat.SimpleCombat;
import engine.combat.SimpleCombat.CombatResult;

public class MatrixCubedCombatSlice {
	private static final String DEFAULT_GAME_DIR = "/home/jzatopa/Downloads/Buck Rogers Matrix Cubed - Source/MATRIX";
	private static final int RAM_WARRIOR_ID = 52;
	private static final long DEFAULT_SEED = 52017L;

	public static void main(String[] args) throws Exception {
		String gameDir = DEFAULT_GAME_DIR;
		long seed = DEFAULT_SEED;

		for (int i = 0; i < args.length; i++) {
			if ("--seed".equals(args[i]) && i + 1 < args.length) {
				seed = Long.parseLong(args[++i]);
			} else {
				gameDir = args[i];
			}
		}

		CombatReport report = run(gameDir, RAM_WARRIOR_ID, seed);
		System.out.print(report.render());
	}

	static CombatReport run(String gameDir, int monsterId, long seed) throws Exception {
		FileMap fileMap = new FileMap(gameDir);
		AbstractCharacter.configValues(CharacterValues.BUCK_ROGERS);
		ResourceLoader resources = new ResourceLoader(fileMap);

		Resource<CharacterBuckRogers> monsterResource = resources.find(monsterId, CharacterBuckRogers.class, ContentType.MONCHA);
		if (!monsterResource.isPresentAndSuccess()) {
			throw new IllegalStateException("Could not load MON0CHA monster id " + monsterId + " from " + gameDir);
		}

		CharacterBuckRogers monster = monsterResource.get();
		Combatant hero = Combatant.hero();
		Combatant enemy = Combatant.fromMonster(monsterId, monster);
		StringBuilder log = new StringBuilder();
		Random random = new Random(seed);

		log.append("Matrix Cubed Java combat slice\n");
		log.append("Game dir: ").append(gameDir).append('\n');
		log.append("Source: MON0CHA.DAX block ").append(monsterId).append('\n');
		log.append("Seed: ").append(seed).append('\n');
		log.append('\n');
		log.append("Enemy: ").append(enemy.name).append("  HP ").append(enemy.hp).append("  AC ").append(enemy.ac)
			.append("  THAC0 ").append(enemy.thac0).append("  Damage ").append(enemy.damageMin).append("-")
			.append(enemy.damageMax).append('\n');
		log.append("Hero: ").append(hero.name).append("  HP ").append(hero.hp).append("  AC ").append(hero.ac)
			.append("  THAC0 ").append(hero.thac0).append("  Damage ").append(hero.damageMin).append("-")
			.append(hero.damageMax).append('\n');
		log.append('\n');

		int round = 0;
		while (hero.hp > 0 && enemy.hp > 0 && round < 20) {
			round++;
			log.append("Round ").append(round).append('\n');
			attack(random, hero, enemy, log);
			if (enemy.hp > 0) {
				attack(random, enemy, hero, log);
			}
			log.append('\n');
		}

		boolean victory = hero.hp > 0 && enemy.hp <= 0;
		int combatResult = victory ? 0 : 1;
		log.append(victory ? "Victory" : "Defeat or unresolved").append('\n');
		log.append("COMBAT_RESULT would be ").append(combatResult).append('\n');
		log.append('\n');
		log.append("Boundary: monster identity/stats are read from original MON0CHA.DAX; attack formula is a visible deterministic scaffold, not yet proven original combat logic.\n");

		return new CombatReport(log.toString(), victory, combatResult, enemy.name);
	}

	static CombatReport runViaEngineCombat(String gameDir, int monsterId, long seed) throws Exception {
		FileMap fileMap = new FileMap(gameDir);
		AbstractCharacter.configValues(CharacterValues.BUCK_ROGERS);
		ResourceLoader resources = new ResourceLoader(fileMap);
		Resource<CharacterBuckRogers> monsterResource = resources.find(monsterId, CharacterBuckRogers.class, ContentType.MONCHA);
		if (!monsterResource.isPresentAndSuccess()) {
			throw new IllegalStateException("Could not load MON0CHA monster id " + monsterId + " from " + gameDir);
		}
		CombatResult result = new SimpleCombat().resolve(monsterResource.get(), seed);
		return new CombatReport(result.transcript + "\n", result.combatResult == 0, result.combatResult, result.enemyName);
	}

	private static void attack(Random random, Combatant attacker, Combatant defender, StringBuilder log) {
		int roll = random.nextInt(20) + 1;
		int needed = Math.max(1, attacker.thac0 - defender.ac);
		if (roll >= needed) {
			int damage = attacker.damageMin + random.nextInt(attacker.damageMax - attacker.damageMin + 1);
			defender.hp = Math.max(0, defender.hp - damage);
			log.append("  ").append(attacker.name).append(" rolls ").append(roll).append(" vs needed ").append(needed)
				.append(": hit for ").append(damage).append(" (").append(defender.name).append(" HP ")
				.append(defender.hp).append(")\n");
		} else {
			log.append("  ").append(attacker.name).append(" rolls ").append(roll).append(" vs needed ").append(needed)
				.append(": miss\n");
		}
	}

	static final class CombatReport {
		final String text;
		final boolean victory;
		final int combatResult;
		final String enemyName;

		CombatReport(String text, boolean victory, int combatResult, String enemyName) {
			this.text = text;
			this.victory = victory;
			this.combatResult = combatResult;
			this.enemyName = enemyName;
		}

		String render() {
			return text;
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

		static Combatant fromMonster(int id, CharacterBuckRogers monster) {
			String name = monster.getName().trim();
			if (name.isEmpty()) {
				name = "Monster " + id;
			}
			int hp = Math.max(1, monster.getNaturalHP());
			int dex = stat(monster, AbilityScoreBuckRogers.DEXTERITY);
			int str = stat(monster, AbilityScoreBuckRogers.STRENGTH);
			int level = Math.max(1, monster.getLevel(character.buckrogers.CharacterClassBuckRogers.WARRIOR));
			int ac = Math.max(0, Math.min(20, 10 - ((dex - 10) / 2)));
			int thac0 = Math.max(5, 21 - level);
			int damageMin = Math.max(1, str / 6);
			int damageMax = Math.max(damageMin, damageMin + Math.max(1, str / 3));
			return new Combatant(name, hp, ac, thac0, damageMin, damageMax);
		}

		private static int stat(CharacterBuckRogers monster, AbilityScore stat) {
			return Math.max(1, monster.getCurrentStatValue(stat));
		}
	}
}
