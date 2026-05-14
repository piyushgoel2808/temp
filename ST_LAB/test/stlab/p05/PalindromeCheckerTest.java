package stlab.p05;

import org.junit.Test;

import static org.junit.Assert.assertFalse;
import static org.junit.Assert.assertTrue;

public class PalindromeCheckerTest {
    private final PalindromeChecker checker = new PalindromeChecker();

    @Test
    public void detectsPalindrome() {
        assertTrue(checker.isPalindrome("level"));
        assertTrue(checker.isPalindrome("Never odd or even"));
    }

    @Test
    public void detectsNonPalindrome() {
        assertFalse(checker.isPalindrome("hello"));
    }
}
