package stlab.p06;

import org.junit.Test;

import static org.junit.Assert.assertEquals;

public class MaxOfTwoTest {
    private final MaxOfTwo target = new MaxOfTwo();

    @Test
    public void returnsLargerNumber() {
        assertEquals(9, target.max(9, 3));
        assertEquals(7, target.max(2, 7));
    }

    @Test
    public void returnsEqualNumberWhenSame() {
        assertEquals(5, target.max(5, 5));
    }
}
