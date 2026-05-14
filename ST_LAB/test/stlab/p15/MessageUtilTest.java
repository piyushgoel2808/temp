package stlab.p15;

import org.junit.Test;

import static org.junit.Assert.assertEquals;

public class MessageUtilTest {
    @Test
    public void printsMessage() {
        MessageUtil util = new MessageUtil("Hello");
        assertEquals("Hello", util.printMessage());
    }
}
