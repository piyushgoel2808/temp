/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package stlab;

// test/MessageUtilAssertTest.java
import org.junit.Test;
import static org.junit.Assert.*;

public class MessageUtilAssertTest {

    String message = "Hello";
    MessageUtil util = new MessageUtil(message);

    @Test
    public void testAssertEquals() {
        assertEquals("Hello", util.printMessage());
    }

    @Test
    public void testAssertNotEquals() {
        assertNotEquals("Hi", util.printMessage());
    }

    @Test
    public void testAssertTrue() {
        assertTrue(util.printMessage().equals("Hello"));
    }

    @Test
    public void testAssertFalse() {
        assertFalse(util.printMessage().equals("Wrong"));
    }

    @Test
    public void testAssertNull() {
        MessageUtil temp = new MessageUtil(null);
        assertNull(temp.printMessage());
    }

    @Test
    public void testAssertNotNull() {
        assertNotNull(util.printMessage());
    }

    @Test
    public void testUpdateMessage() {
        String updated = util.updateMessage("New Message");
        assertEquals("New Message", updated);
    }
}