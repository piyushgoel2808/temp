/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/UnitTests/JUnit4TestClass.java to edit this template
 */
package stlab;
// test/FactorialTest.java
import org.junit.Test;
import static org.junit.Assert.*;

public class FactorialTest {

    private final Factorial obj = new Factorial();

    @Test
    public void testFactorialOfZero() {
        assertEquals(1, obj.factorial(0));
    }

    @Test
    public void testFactorialOfOne() {
        assertEquals(1, obj.factorial(1));
    }

    @Test
    public void testFactorialOfFive() {
        assertEquals(120, obj.factorial(5));
    }

    @Test
    public void testFactorialOfTen() {
        assertEquals(3628800, obj.factorial(10));
    }

    @Test(expected = IllegalArgumentException.class)
    public void testNegativeInput() {
        obj.factorial(-3);
    }
}