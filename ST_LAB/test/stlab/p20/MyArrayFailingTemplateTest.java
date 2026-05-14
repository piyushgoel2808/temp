package stlab.p20;

import org.junit.Ignore;
import org.junit.Test;

import static org.junit.Assert.assertEquals;

public class MyArrayFailingTemplateTest {
    private final MyArray array = new MyArray();

    @Ignore("Intentional failing example for lab test-case template")
    @Test
    public void failingExampleLargestElement() {
        int[] values = {3, 7, 2, 9, 5};
        assertEquals(8, array.findLargest(values));
    }
}
