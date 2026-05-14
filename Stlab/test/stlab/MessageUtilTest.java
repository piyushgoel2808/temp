/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/UnitTests/JUnit4TestClass.java to edit this template
 */
package stlab;

// test/MessageUtilTest.java
import org.junit.Test;
import static org.junit.Assert.*;

public class MessageUtilTest {

    String message = "Hello World";
    MessageUtil util = new MessageUtil(message);

    @Test
    public void testPrintMessage() {
        assertEquals(message, util.printMessage());
    }

    @Test
    public void testUpdateMessage() {
        String newMsg = "Updated Message";
        assertEquals(newMsg, util.updateMessage(newMsg));
    }
}