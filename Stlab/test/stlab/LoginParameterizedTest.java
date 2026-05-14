/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/UnitTests/JUnit4TestClass.java to edit this template
 */
package stlab;

// test/LoginParameterizedTest.java
import org.junit.Test;
import org.junit.runner.RunWith;
import org.junit.runners.Parameterized;
import static org.junit.Assert.*;
import java.util.*;

@RunWith(Parameterized.class)
public class LoginParameterizedTest {

    private String email;
    private boolean exists;
    private boolean password;
    private boolean blocked;
    private String expected;

    private LoginService service = new LoginService();

    public LoginParameterizedTest(String email, boolean exists,
                                  boolean password, boolean blocked,
                                  String expected) {
        this.email = email;
        this.exists = exists;
        this.password = password;
        this.blocked = blocked;
        this.expected = expected;
    }

    @Parameterized.Parameters
    public static Collection<Object[]> data() {
        return Arrays.asList(new Object[][] {

            // SUCCESS CASE
            {"user@xyz.com", true, true, false, "Login Success"},

            // INVALID EMAIL
            {"invalidemail", false, false, false, "Invalid Email"},

            // USER NOT FOUND
            {"user@xyz.com", false, false, false, "User Not Found"},

            // WRONG PASSWORD
            {"user@xyz.com", true, false, false, "Wrong Password"},

            // BLOCKED USER
            {"user@xyz.com", true, true, true, "Account Blocked"},

            // BLOCKED + WRONG PASSWORD
            {"user@xyz.com", true, false, true, "Account Blocked"}
        });
    }

    @Test
    public void testLogin() {
        assertEquals(expected,
            service.login(email, exists, password, blocked));
    }
}