/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/UnitTests/JUnit4TestClass.java to edit this template
 */
package stlab;

// test/ReverseTest.java
import org.junit.Test;
import static org.junit.Assert.*;

public class ReverseTest {

    private final Reverse obj = new Reverse();

    @Test
    public void testNormalString() {
        assertEquals("olleh", obj.reverse("hello"));
    }

    @Test
    public void testPalindromeString() {
        assertEquals("madam", obj.reverse("madam"));
    }

    @Test
    public void testEmptyString() {
        assertEquals("", obj.reverse(""));
    }

    @Test
    public void testSingleCharacter() {
        assertEquals("a", obj.reverse("a"));
    }

    @Test
    public void testWithSpaces() {
        assertEquals("dlrow olleh", obj.reverse("hello world"));
    }

    @Test
    public void testWithSpecialCharacters() {
        assertEquals("!cba", obj.reverse("abc!"));
    }

    @Test
    public void testNullInput() {
        assertNull(obj.reverse(null));
    }
}