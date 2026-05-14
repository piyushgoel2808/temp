package stlab.p09;

import org.junit.Test;

import static org.junit.Assert.assertEquals;

public class SimpleInterestCalculatorTest {
    private final SimpleInterestCalculator calculator = new SimpleInterestCalculator();

    @Test
    public void calculatesSimpleInterest() {
        assertEquals(150.0, calculator.calculate(1000.0, 5.0, 3.0), 0.0001);
    }
}
