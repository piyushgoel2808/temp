/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/UnitTests/JUnit4TestClass.java to edit this template
 */
package stlab;

// test/SimpleInterestTest.java
import org.junit.Test;
import static org.junit.Assert.*;

public class SimpleInterestTest {

    private final SimpleInterest obj = new SimpleInterest();

    @Test
    public void testNormalValues() {
        assertEquals(500.0, obj.calculateSI(1000, 5, 10), 0.001);
    }

    @Test
    public void testZeroPrincipal() {
        assertEquals(0.0, obj.calculateSI(0, 5, 10), 0.001);
    }

    @Test
    public void testZeroRate() {
        assertEquals(0.0, obj.calculateSI(1000, 0, 10), 0.001);
    }

    @Test
    public void testZeroTime() {
        assertEquals(0.0, obj.calculateSI(1000, 5, 0), 0.001);
    }

    @Test(expected = IllegalArgumentException.class)
    public void testNegativeInput() {
        obj.calculateSI(-1000, 5, 10);
    }
}