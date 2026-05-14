package stlab.p18;

import org.junit.Test;

import static org.junit.Assert.assertEquals;

public class CounterTest {
    @Test
    public void incrementIncreasesValue() {
        Counter counter = new Counter();
        assertEquals(1, counter.increment());
    }

    @Test
    public void decrementDecreasesValue() {
        Counter counter = new Counter();
        assertEquals(-1, counter.decrement());
    }
}
