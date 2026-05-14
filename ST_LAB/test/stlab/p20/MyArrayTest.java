package stlab.p20;

import org.junit.Test;

import static org.junit.Assert.assertEquals;

public class MyArrayTest {
    private final MyArray array = new MyArray();

    @Test
    public void findsLargestElement() {
        int[] values = {3, 7, 2, 9, 5};
        assertEquals(9, array.findLargest(values));
    }
}
