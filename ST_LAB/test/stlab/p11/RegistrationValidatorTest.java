package stlab.p11;

import org.junit.Test;

import static org.junit.Assert.assertEquals;
import static org.junit.Assert.assertFalse;
import static org.junit.Assert.assertTrue;

public class RegistrationValidatorTest {
    private final RegistrationValidator validator = new RegistrationValidator();

    @Test
    public void pageLoadsSuccessfully() {
        assertTrue(validator.pageLoads());
    }

    @Test
    public void requiredFieldsMarkedWithStar() {
        assertTrue(validator.requiredFieldsMarked());
    }

    @Test
    public void pageHasSubmitAndCancelButtons() {
        assertTrue(validator.hasSubmitAndCancelButtons());
    }

    @Test
    public void submitWithRequiredFieldsSucceeds() {
        RegistrationFormData data = new RegistrationFormData("Aman", "aman@example.com", "pass123");
        SubmissionResult result = validator.submit(data);
        assertTrue(result.isSuccess());
        assertEquals("Submitted", result.getMessage());
    }

    @Test
    public void cancelResetsFields() {
        RegistrationFormData data = new RegistrationFormData("Aman", "aman@example.com", "pass123");
        validator.cancel(data);
        assertEquals("", data.getName());
        assertEquals("", data.getEmail());
        assertEquals("", data.getPassword());
    }

    @Test
    public void submitWithoutMandatoryFieldsFails() {
        RegistrationFormData data = new RegistrationFormData("", "", "");
        SubmissionResult result = validator.submit(data);
        assertFalse(result.isSuccess());
        assertEquals("Validation error", result.getMessage());
    }
}
