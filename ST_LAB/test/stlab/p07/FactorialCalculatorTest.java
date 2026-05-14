package stlab.p07;

import org.junit.Test;

import static org.junit.Assert.assertEquals;

public class FactorialCalculatorTest {
    private final FactorialCalculator calculator = new FactorialCalculator();

    @Test
    public void factorialOfZeroIsOne() {
        assertEquals(1L, calculator.factorial(0));
    }

    @Test
    public void factorialOfFiveIs120() {
        assertEquals(120L, calculator.factorial(5));
    }
}
