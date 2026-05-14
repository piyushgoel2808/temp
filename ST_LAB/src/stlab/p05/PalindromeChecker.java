package stlab.p05;

public class PalindromeChecker {
    public boolean isPalindrome(String value) {
        if (value == null) {
            return false;
        }
        String normalized = value.replaceAll("\\s+", "").toLowerCase();
        int left = 0;
        int right = normalized.length() - 1;
        while (left < right) {
            if (normalized.charAt(left) != normalized.charAt(right)) {
                return false;
            }
            left++;
            right--;
        }
        return true;
    }
}
