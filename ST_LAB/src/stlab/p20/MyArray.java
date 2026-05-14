package stlab.p20;

public class MyArray {
    public int findLargest(int[] values) {
        if (values == null || values.length == 0) {
            throw new IllegalArgumentException("Array must not be empty");
        }
        int max = values[0];
        for (int i = 1; i < values.length; i++) {
            if (values[i] > max) {
                max = values[i];
            }
        }
        return max;
    }
}
