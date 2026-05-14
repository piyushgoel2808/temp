/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/UnitTests/JUnit4TestClass.java to edit this template
 */
package stlab;

// src/Overloading.java
// test/OverloadingTest.java
import org.junit.Test;
import static org.junit.Assert.*;

public class OverloadingTest {

    private final Overloading obj = new Overloading();

    @Test
    public void testAddTwoIntegers() {
        assertEquals(5, obj.add(2, 3));
    }

    @Test
    public void testAddThreeIntegers() {
        assertEquals(10, obj.add(2, 3, 5));
    }

    @Test
    public void testAddDoubles() {
        assertEquals(5.5, obj.add(2.5, 3.0), 0.001);
    }

    @Test
    public void testAddStrings() {
        assertEquals("HelloWorld", obj.add("Hello", "World"));
    }

    @Test
    public void testAddNegativeNumbers() {
        assertEquals(-5, obj.add(-2, -3));
    }

    @Test
    public void testAddWithZero() {
        assertEquals(3, obj.add(3, 0));
    }
}