package stlab.p10;

import org.junit.Test;

import static org.junit.Assert.assertFalse;
import static org.junit.Assert.assertTrue;

public class LoginValidatorTest {
    private final LoginValidator validator = new LoginValidator();

    @Test
    public void acceptsValidCredentials() {
        assertTrue(validator.validate("user@example.com", "pass123"));
    }

    @Test
    public void rejectsInvalidCredentials() {
        assertFalse(validator.validate("user@example.com", "wrong"));
        assertFalse(validator.validate("unknown@example.com", "pass123"));
    }
}
