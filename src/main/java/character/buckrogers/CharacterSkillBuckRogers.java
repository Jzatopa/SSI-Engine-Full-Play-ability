package character.buckrogers;

import character.CharacterSkill;
import shared.CustomGoldboxString;
import shared.GoldboxString;

public enum CharacterSkillBuckRogers implements CharacterSkill {
	PILOT_ROCKET("PILOT ROCKET");

	private final GoldboxString name;

	private CharacterSkillBuckRogers(String name) {
		this.name = new CustomGoldboxString(name);
	}

	@Override
	public GoldboxString getName() {
		return name;
	}
}
