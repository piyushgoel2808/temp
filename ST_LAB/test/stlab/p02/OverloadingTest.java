package stlab.p02;

import org.junit.Test;

import static org.junit.Assert.assertEquals;

public class OverloadingTest {
    private final Overloading target = new Overloading();

    @Test
    public void addsTwoInts() {
        assertEquals(7, target.add(3, 4));
    }

    @Test
    public void addsThreeInts() {
        assertEquals(9, target.add(2, 3, 4));
    }

    @Test
    public void addsDoubles() {
        assertEquals(5.5, target.add(2.0, 3.5), 0.0001);
    }

    @Test
    public void addsStrings() {
        assertEquals("HelloWorld", target.add("Hello", "World"));
    }
}
