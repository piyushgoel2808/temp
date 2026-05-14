/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/UnitTests/JUnit4TestClass.java to edit this template
 */
package stlab;




import org.junit.Test;
import static org.junit.Assert.*;

public class AdditionTest {

    private final Addition obj = new Addition();

    @Test
    public void testPositiveNumbers() {
        assertEquals(5, obj.add(2, 3));
    }

    @Test
    public void testNegativeNumbers() {
        assertEquals(-5, obj.add(-2, -3));
    }

    @Test
    public void testMixedNumbers() {
        assertEquals(1, obj.add(-2, 3));
    }

    @Test
    public void testWithZero() {
        assertEquals(3, obj.add(3, 0));
    }

    @Test
    public void testLargeNumbers() {
        assertEquals(2000000, obj.add(1000000, 1000000));
    }
}