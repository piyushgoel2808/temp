package stlab.p02;

public class Overloading {
    public int add(int a, int b) {
        return a + b;
    }

    public int add(int a, int b, int c) {
        return a + b + c;
    }

    public double add(double a, double b) {
        return a + b;
    }

    public String add(String a, String b) {
        if (a == null || b == null) {
            throw new IllegalArgumentException("Strings cannot be null");
        }
        return a + b;
    }
}
