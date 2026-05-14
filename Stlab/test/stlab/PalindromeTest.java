/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/UnitTests/JUnit4TestClass.java to edit this template
 */
package stlab;

// test/PalindromeTest.java
import org.junit.Test;
import static org.junit.Assert.*;

public class PalindromeTest {

    private final Palindrome obj = new Palindrome();

    @Test
    public void testSimplePalindrome() {
        assertTrue(obj.isPalindrome("madam"));
    }

    @Test
    public void testNotPalindrome() {
        assertFalse(obj.isPalindrome("hello"));
    }

    @Test
    public void testCaseInsensitive() {
        assertTrue(obj.isPalindrome("Madam"));
    }

    @Test
    public void testWithSpaces() {
        assertTrue(obj.isPalindrome("nurses run"));
    }

    @Test
    public void testWithSpecialCharacters() {
        assertTrue(obj.isPalindrome("A man, a plan, a canal: Panama"));
    }

    @Test
    public void testEmptyString() {
        assertTrue(obj.isPalindrome(""));
    }

    @Test
    public void testNullInput() {
        assertFalse(obj.isPalindrome(null));
    }
}