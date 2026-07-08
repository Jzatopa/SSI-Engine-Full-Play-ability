package engine.party;

import java.util.ArrayList;
import java.util.List;

/**
 * The after-combat NPC treasure split.
 *
 * <p>Ported from COAB (https://github.com/simeonpilgrim/coab, commit 9dc46f1),
 * {@code ovr006.distributeNpcTreasure} (sub_2E50E), which runs inside
 * {@code AfterCombatExpAndTreasure} before the party's own treasure menu:
 * every healthy NPC-controlled member contributes
 * {@code npcTreasureShareCount & 7} parts to both the NPC total and the grand
 * total; every other member (player characters, and downed NPCs) counts as
 * exactly 1 part of the grand total. If the NPCs hold any parts, the pooled
 * money is scaled by {@code npcParts / totalParts}.</p>
 *
 * <p>Faithful quirk, ported deliberately: the C# computes
 * {@code npcParts / totalParts} in <em>integer</em> division before passing it
 * to {@code MoneySet.ScaleAll(double)}. Whenever the NPCs hold fewer parts
 * than the whole party (the normal case) the scale is 0 and the entire pool
 * is zeroed -- the on-screen fiction being that each NPC "takes and hides"
 * its share. This port reproduces that arithmetic exactly; do not "fix" it to
 * floating point without independent evidence from an original binary.</p>
 *
 * <p>The share-count value itself (COAB seeds {@code npcTreasureShareCount = 1}
 * for created characters and loads it from byte 0x85 of imported records) is
 * data, not logic; nothing AD&amp;D-specific is hardcoded here.</p>
 */
public final class NpcTreasureShare {

	/** Low-3-bit mask applied to each share count, as in the C# ({@code & 7}). */
	public static final int SHARE_COUNT_MASK = 7;

	/**
	 * The coin pool being divided. Ported interface of COAB
	 * {@code Classes/MoneySet.cs.ScaleAll}: multiplies every plain coin type
	 * (COAB scales Copper..Platinum, leaving gems/jewelry alone -- an
	 * implementation choice the integrator's pool must mirror) by
	 * {@code scale}, truncating to int, and returns whether any scaled coin
	 * type held a nonzero amount beforehand.
	 */
	public interface MoneyPool {
		boolean scaleAll(double scale);
	}

	/**
	 * What the split did.
	 *
	 * @param npcParts total parts held by healthy NPC members ({@code & 7} each)
	 * @param totalParts npcParts plus 1 per remaining member
	 * @param treasureTaken {@code ScaleAll}'s return: the pool was scaled and held money
	 * @param takers healthy NPC members with a nonzero share count -- the ones COAB
	 *   names in its "takes and hides his/her share" messages; empty unless
	 *   {@code treasureTaken}
	 */
	public record Result(int npcParts, int totalParts, boolean treasureTaken, List<NpcCharacter> takers) {
	}

	private NpcTreasureShare() {
	}

	/**
	 * Runs the split over the current members against the pooled money.
	 * See the class javadoc for the exact COAB arithmetic.
	 */
	public static Result distribute(List<? extends NpcCharacter> members, MoneyPool pool) {
		int npcParts = 0;
		int totalParts = 0;

		for (NpcCharacter member : members) {
			if (member.isNpc() && member.isHealthy()) {
				npcParts += member.npcTreasureShareCount() & SHARE_COUNT_MASK;
				totalParts += member.npcTreasureShareCount() & SHARE_COUNT_MASK;
			} else {
				totalParts += 1;
			}
		}

		boolean treasureTaken = false;
		if (npcParts > 0) {
			// Integer division before the double conversion -- faithful to the C#.
			treasureTaken = pool.scaleAll(npcParts / totalParts);
		}

		List<NpcCharacter> takers = new ArrayList<>();
		if (treasureTaken) {
			for (NpcCharacter member : members) {
				if (member.isNpc() && member.isHealthy() && member.npcTreasureShareCount() > 0) {
					takers.add(member);
				}
			}
		}
		return new Result(npcParts, totalParts, treasureTaken, takers);
	}
}
