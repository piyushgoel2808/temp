package stlab.p14;

import org.junit.Test;
import org.junit.runner.RunWith;
import org.junit.runners.Parameterized;

import java.util.Arrays;
import java.util.Collection;

import static org.junit.Assert.assertEquals;

@RunWith(Parameterized.class)
public class AdditionParameterizedTest {
    private final int a;
    private final int b;
    private final int expected;

    private final Addition addition = new Addition();

    public AdditionParameterizedTest(int a, int b, int expected) {
        this.a = a;
        this.b = b;
        this.expected = expected;
    }

    @Parameterized.Parameters(name = "{index}: add({0}, {1})={2}")
    public static Collection<Object[]> data() {
        return Arrays.asList(new Object[][]{
                {1, 11, 12},
                {1, 20, 21},
                {10, 11, 21},
                {10, 20, 30},
                {5, 15, 20}
        });
    }

    @Test
    public void addsNumbers() {
        assertEquals(expected, addition.add(a, b));
    }
}
