/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/UnitTests/JUnit4TestClass.java to edit this template
 */
package stlab;

// test/EvenOddTest.java
import org.junit.Test;
import static org.junit.Assert.*;

public class EvenOddTest {

    private final EvenOdd obj = new EvenOdd();

    @Test
    public void testEvenNumber() {
        assertEquals("Even", obj.checkEvenOdd(4));
    }

    @Test
    public void testOddNumber() {
        assertEquals("Odd", obj.checkEvenOdd(5));
    }

    @Test
    public void testZero() {
        assertEquals("Even", obj.checkEvenOdd(0));
    }

    @Test
    public void testNegativeEven() {
        assertEquals("Even", obj.checkEvenOdd(-2));
    }

    @Test
    public void testNegativeOdd() {
        assertEquals("Odd", obj.checkEvenOdd(-3));
    }
}