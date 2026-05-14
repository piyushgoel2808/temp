package stlab.p08;

public class ReverseUtil {
    public String reverse(String value) {
        if (value == null) {
            return null;
        }
        return new StringBuilder(value).reverse().toString();
    }
}
