package character.buckrogers;

import character.CharacterSkill;
import shared.CustomGoldboxString;
import shared.GoldboxString;

public enum CharacterSkillBuckRogers implements CharacterSkill {
	REPAIR_ELECTRICAL(0x01, "Repair Electrical"),
	REPAIR_MECHANICAL(0x02, "Repair Mechanical"),
	REPAIR_NUCLEAR_ENGINE(0x03, "Repair Nuclear Engine"),
	REPAIR_LIFE_SUPPORT(0x04, "Repair Life Support"),
	REPAIR_ROCKET_HULL(0x05, "Repair Rocket Hull"),
	JURY_RIG(0x06, "Jury Rig"),
	BYPASS_SECURITY(0x07, "Bypass Security"),
	OPEN_LOCK(0x08, "Open Lock"),
	COMMO_OPERATION(0x09, "Commo Operation"),
	SENSOR_OPERATION(0x0A, "Sensor Operation"),
	DEMOLITIONS(0x0B, "Demolitions"),
	COOK(0x0C, "Cook"),
	FIRST_AID(0x0D, "First Aid"),
	REPAIR_WEAPON(0x0E, "Repair Weapon"),
	REPAIR_COMPUTER(0x0F, "Repair Computer"),
	LIFE_SUSPENSION_TECH(0x10, "Life Suspension Tech"),
	TREAT_LIGHT_WOUNDS(0x11, "Treat Light Wounds"),
	TREAT_SERIOUS_WOUNDS(0x12, "Treat Serious Wounds"),
	TREAT_CRITICAL_WOUNDS(0x13, "Treat Critical Wounds"),
	TREAT_POISONING(0x14, "Treat Poisoning"),
	TREAT_STUN_PARALYSIS(0x15, "Treat Stun/Paralysis"),
	TREAT_DISEASE(0x16, "Treat Disease"),
	DIAGNOSE(0x17, "Diagnose"),
	GENERAL_KNOWLEDGE(0x18, "General Knowledge"),
	SHIP_LORE(0x19, "Ship Lore"),
	COMPOSITION(0x1A, "Composition"),
	MATHEMATICS(0x1B, "Mathematics"),
	PHYSICS(0x1C, "Physics"),
	GEOLOGY(0x1D, "Geology"),
	PLANETOLOGY(0x1E, "Planetology"),
	BATTLE_TACTICS(0x1F, "Battle Tactics"),
	CHEMISTRY(0x20, "Chemistry"),
	BIOLOGY(0x21, "Biology"),
	DESIGN_ENGINEERING(0x22, "Design Engineering"),
	HISTORY(0x23, "History"),
	ASTRONOMY(0x24, "Astronomy"),
	BOTANY(0x25, "Botany"),
	LITERATURE(0x26, "Literature"),
	ECONOMICS(0x27, "Economics"),
	METALLURGY(0x28, "Metallurgy"),
	SPEAK_READ_LANG(0x29, "Speak/Read Lang."),
	LAW(0x2A, "Law"),
	PROGRAMMING(0x2B, "Programming"),
	CRYTOGRAPHY(0x2C, "Crytography"),
	LIBRARY_SEARCH(0x2D, "Library Search"),
	ASTROGATION(0x2E, "Astrogation"),
	NAVIGATION(0x2F, "Navigation"),
	MIMIC(0x30, "Mimic"),
	MEMORIZE(0x31, "Memorize"),
	DISGUISE(0x32, "Disguise"),
	PILOT_ROCKET(0x33, "Pilot Rocket"),
	PILOT_FIXED_WING(0x34, "Pilot Fixed Wing"),
	DRIVE_GROUND_CAR(0x35, "Drive Ground Car"),
	PILOT_ROTOR_WING(0x36, "Pilot Rotor Wing"),
	DRIVE_MOTORCYCLE(0x37, "Drive Motorcycle"),
	USE_JETPACK(0x38, "Use Jetpack"),
	PILOT_SHIP_SUB(0x39, "Pilot Ship/Sub"),
	DRIVE_HVY_GRND_VEHC(0x3A, "Drive Hvy Grnd Vehc"),
	DRIVE_JETCAR(0x3B, "Drive Jetcar"),
	ANIMAL_RIDING(0x3C, "Animal Riding"),
	HIDE_IN_SHADOWS(0x3D, "Hide in Shadows"),
	MOVE_SILENTLY(0x3E, "Move Silently"),
	PICK_POCKETS(0x3F, "Pick Pockets"),
	ACROBATICS(0x40, "Acrobatics"),
	CLIMB(0x41, "Climb"),
	SWIMMING(0x42, "Swimming"),
	MANEUVER_IN_ZERO_G(0x43, "Maneuver in 0G"),
	PLAY_INSTRUMNT(0x44, "Play Instrumnt"),
	PAINT_DRAW(0x45, "Paint/Draw"),
	HYPNOSIS(0x46, "Hypnosis"),
	ACT(0x47, "Act"),
	INTIMIDATE(0x48, "Intimidate"),
	LEADERSHIP(0x49, "Leadership"),
	BEFRIEND_ANIMAL(0x4A, "Befriend Animal"),
	ANIMAL_TRAINING(0x4B, "Animal Training"),
	FAST_TALK_CONVINCE(0x4C, "Fast Talk/Convince"),
	SINGING(0x4D, "Singing"),
	DISTRACT(0x4E, "Distract"),
	ETIQUETTE(0x4F, "Etiquette"),
	TRACKING(0x50, "Tracking"),
	SHADOWING(0x51, "Shadowing"),
	READ_LIPS(0x52, "Read Lips"),
	NOTICE(0x53, "Notice"),
	PLANETARY_SURVIVAL(0x54, "Planetary Survival");

	private static final int WHO_SKILL_BASE = 0x4C;
	private final int skillId;
	private final GoldboxString name;

	private CharacterSkillBuckRogers(int skillId, String name) {
		this.skillId = skillId;
		this.name = new CustomGoldboxString(name);
	}

	public int getSkillId() {
		return skillId;
	}

	public int getWhoOffset() {
		return WHO_SKILL_BASE + skillId;
	}

	@Override
	public GoldboxString getName() {
		return name;
	}
}
