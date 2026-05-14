/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package stlab;

// test/AdditionParameterizedTest.java
import org.junit.Test;
import org.junit.runner.RunWith;
import org.junit.runners.Parameterized;
import static org.junit.Assert.*;
import java.util.*;

@RunWith(Parameterized.class)
public class AdditionParameterizedTest {

    private int a;
    private int b;
    private int expected;

    private Addition obj = new Addition();

    public AdditionParameterizedTest(int a, int b, int expected) {
        this.a = a;
        this.b = b;
        this.expected = expected;
    }

    @Parameterized.Parameters
    public static Collection<Object[]> data() {
        return Arrays.asList(new Object[][] {
            {1, 11, 12},
            {2, 12, 14},
            {9, 19, 28},
            {10, 20, 30}
        });
    }

    @Test
    public void testAddition() {
        assertEquals(expected, obj.add(a, b));
    }
}