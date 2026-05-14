package stlab.p09;

public class SimpleInterestCalculator {
    public double calculate(double principal, double rate, double time) {
        return (principal * rate * time) / 100.0;
    }
}
