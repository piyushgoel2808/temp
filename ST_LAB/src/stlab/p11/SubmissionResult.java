package stlab.p11;

public class SubmissionResult {
    private final boolean success;
    private final String message;

    public SubmissionResult(boolean success, String message) {
        this.success = success;
        this.message = message;
    }

    public boolean isSuccess() {
        return success;
    }

    public String getMessage() {
        return message;
    }
}
