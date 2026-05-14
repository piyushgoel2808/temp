package stlab.p03;

import org.junit.Ignore;
import org.junit.Test;

import static org.junit.Assert.assertEquals;

public class ArithmeticTest {
    private final Arithmetic target = new Arithmetic();

    @Test
    public void sumTwoNumbers() {
        assertEquals(7, target.sum(3, 4));
    }

    @Test
    public void sumThreeNumbers() {
        assertEquals(9, target.sum(2, 3, 4));
    }

    @Ignore("Example failing test case for lab documentation")
    @Test
    public void sumFailingExample() {
        assertEquals(10, target.sum(2, 3, 4));
    }
}
