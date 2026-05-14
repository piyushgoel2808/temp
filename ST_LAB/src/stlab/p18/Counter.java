package stlab.p18;

public class Counter {
    private int value;

    public Counter() {
        value = 0;
    }

    public int increment() {
        value += 1;
        return value;
    }

    public int decrement() {
        value -= 1;
        return value;
    }
}
