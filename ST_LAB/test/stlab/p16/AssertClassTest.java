package stlab.p16;

import org.junit.Test;

import static org.junit.Assert.assertEquals;
import static org.junit.Assert.assertFalse;
import static org.junit.Assert.assertNotNull;
import static org.junit.Assert.assertTrue;

public class AssertClassTest {
    @Test
    public void demonstratesAssertMethods() {
        MessageUtil util = new MessageUtil("Welcome");
        String message = util.printMessage();

        assertNotNull(message);
        assertTrue(message.startsWith("Wel"));
        assertFalse(message.isEmpty());
        assertEquals("Welcome", message);
    }
}
