/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/UnitTests/JUnit4TestClass.java to edit this template
 */
package stlab;

// test/MaxNumberTest.java
import org.junit.Test;
import static org.junit.Assert.*;

public class MaxNumberTest {

    private final MaxNumber obj = new MaxNumber();

    @Test
    public void testFirstGreater() {
        assertEquals(10, obj.findMax(10, 5));
    }

    @Test
    public void testSecondGreater() {
        assertEquals(8, obj.findMax(3, 8));
    }

    @Test
    public void testBothEqual() {
        assertEquals(5, obj.findMax(5, 5));
    }

    @Test
    public void testNegativeNumbers() {
        assertEquals(-2, obj.findMax(-2, -5));
    }

    @Test
    public void testMixedNumbers() {
        assertEquals(3, obj.findMax(-1, 3));
    }
}