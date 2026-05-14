/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/UnitTests/JUnit4TestClass.java to edit this template
 */
package stlab;

// test/LoginValidatorTest.java
import org.junit.Test;
import static org.junit.Assert.*;

public class LoginValidatorTest {

    private final LoginValidator obj = new LoginValidator();

    @Test
    public void testValidCredentials() {
        assertTrue(obj.validate("admin", "1234"));
    }

    @Test
    public void testInvalidUsername() {
        assertFalse(obj.validate("user", "1234"));
    }

    @Test
    public void testInvalidPassword() {
        assertFalse(obj.validate("admin", "wrong"));
    }

    @Test
    public void testBothInvalid() {
        assertFalse(obj.validate("user", "wrong"));
    }

    @Test
    public void testEmptyUsername() {
        assertFalse(obj.validate("", "1234"));
    }

    @Test
    public void testEmptyPassword() {
        assertFalse(obj.validate("admin", ""));
    }

    @Test
    public void testNullUsername() {
        assertFalse(obj.validate(null, "1234"));
    }

    @Test
    public void testNullPassword() {
        assertFalse(obj.validate("admin", null));
    }
}