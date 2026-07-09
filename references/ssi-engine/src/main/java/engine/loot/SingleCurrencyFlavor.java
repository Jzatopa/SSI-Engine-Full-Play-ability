package engine.loot;

/**
 * Candidate single-denomination {@link CurrencyFlavor} for Buck Rogers'
 * "credits" currency.
 *
 * <p>This is NOT a COAB port. Buck Rogers: Matrix Cubed uses a single credits
 * currency rather than AD&amp;D's 7-coin set, but the credits' internal
 * representation, conversion behavior, and any denomination breakdown have not
 * been independently recovered from the Matrix Cubed binary or captures. This
 * class exists so the universal loot services in this package (built against
 * {@link CurrencyFlavor}/{@link MoneyPool}) can operate for Buck Rogers without
 * hard-coding the AD&amp;D coin set — treat every detail here as a
 * placeholder/candidate pending confirmation against Matrix evidence, not as
 * Matrix Cubed evidence itself.</p>
 */
public final class SingleCurrencyFlavor implements CurrencyFlavor {

	/** Sole denomination index. */
	public static final int CREDITS = 0;

	public static final SingleCurrencyFlavor INSTANCE = new SingleCurrencyFlavor();

	private SingleCurrencyFlavor() {
	}

	@Override
	public int denominationCount() {
		return 1;
	}

	@Override
	public String denominationName(int index) {
		return "Credits";
	}
}
