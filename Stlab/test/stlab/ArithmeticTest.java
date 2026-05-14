/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/UnitTests/JUnit4TestClass.java to edit this template
 */
package stlab;

// test/ArithmeticTest.java
import org.junit.Test;
import static org.junit.Assert.*;

public class ArithmeticTest {

    Arithmetic obj = new Arithmetic();

    // PASS CASES
    @Test
    public void testSumTwoNumbers() {
        assertEquals(5, obj.sum(2, 3));
    }

    @Test
    public void testSumThreeNumbers() {
        assertEquals(10, obj.sum(2, 3, 5));
    }

    // FAIL CASE (intentional)
    @Test
    public void testFailCase() {
        assertEquals(6, obj.sum(2, 3)); // actual = 5 → FAIL
    }
}