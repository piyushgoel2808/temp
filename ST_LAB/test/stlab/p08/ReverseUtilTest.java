package stlab.p08;

import org.junit.Test;

import static org.junit.Assert.assertEquals;

public class ReverseUtilTest {
    private final ReverseUtil util = new ReverseUtil();

    @Test
    public void reversesString() {
        assertEquals("cba", util.reverse("abc"));
    }
}
