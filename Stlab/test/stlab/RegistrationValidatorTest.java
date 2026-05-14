/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/UnitTests/JUnit4TestClass.java to edit this template
 */
package stlab;

// test/RegistrationValidatorTest.java
import org.junit.Test;
import static org.junit.Assert.*;

public class RegistrationValidatorTest {

    private final RegistrationValidator obj = new RegistrationValidator();

    @Test
    public void testPageLoads() {
        assertTrue(obj.isPageLoaded(true));
    }

    @Test
    public void testMandatoryFieldsMarked() {
        assertTrue(obj.areMandatoryFieldsMarked(true));
    }

    @Test
    public void testButtonsPresent() {
        assertTrue(obj.hasButtons(true, true));
    }

    @Test
    public void testSuccessfulSubmission() {
        assertTrue(obj.submitForm("user", "pass", "email@test.com"));
    }

    @Test
    public void testResetFunction() {
        assertTrue(obj.resetForm());
    }

    @Test
    public void testMissingMandatoryFields() {
        assertFalse(obj.submitForm("", "pass", "email@test.com"));
    }
}