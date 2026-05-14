/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/UnitTests/JUnit4TestClass.java to edit this template
 */
package stlab;

// test/CounterTest.java
import org.junit.Test;
import static org.junit.Assert.*;

public class CounterTest {

    @Test
    public void testInitialValue() {
        Counter c = new Counter();
        assertEquals(0, c.getValue());
    }

    @Test
    public void testIncrement() {
        Counter c = new Counter();
        assertEquals(1, c.increment());
    }

    @Test
    public void testMultipleIncrement() {
        Counter c = new Counter();
        c.increment();
        c.increment();
        assertEquals(2, c.getValue());
    }

    @Test
    public void testDecrement() {
        Counter c = new Counter();
        assertEquals(-1, c.decrement());
    }

    @Test
    public void testIncrementThenDecrement() {
        Counter c = new Counter();
        c.increment();   // 1
        c.decrement();   // 0
        assertEquals(0, c.getValue());
    }
}