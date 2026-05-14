package stlab.p04;

import org.junit.Test;

import static org.junit.Assert.assertFalse;
import static org.junit.Assert.assertTrue;

public class EvenOddCheckerTest {
    private final EvenOddChecker checker = new EvenOddChecker();

    @Test
    public void evenNumberReturnsTrue() {
        assertTrue(checker.isEven(10));
    }

    @Test
    public void oddNumberReturnsFalse() {
        assertFalse(checker.isEven(7));
    }
}
