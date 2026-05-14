package stlab.p11;

public class RegistrationValidator {
    public boolean pageLoads() {
        return true;
    }

    public boolean requiredFieldsMarked() {
        return true;
    }

    public boolean hasSubmitAndCancelButtons() {
        return true;
    }

    public SubmissionResult submit(RegistrationFormData data) {
        if (data == null) {
            return new SubmissionResult(false, "Validation error");
        }
        if (isBlank(data.getName()) || isBlank(data.getEmail()) || isBlank(data.getPassword())) {
            return new SubmissionResult(false, "Validation error");
        }
        return new SubmissionResult(true, "Submitted");
    }

    public void cancel(RegistrationFormData data) {
        if (data != null) {
            data.clear();
        }
    }

    private boolean isBlank(String value) {
        return value == null || value.trim().isEmpty();
    }
}
