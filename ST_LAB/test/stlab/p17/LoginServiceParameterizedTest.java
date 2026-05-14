package stlab.p17;

import org.junit.Test;
import org.junit.runner.RunWith;
import org.junit.runners.Parameterized;

import java.util.Arrays;
import java.util.Collection;

import static org.junit.Assert.assertEquals;

@RunWith(Parameterized.class)
public class LoginServiceParameterizedTest {
    private final String email;
    private final String password;
    private final boolean blocked;
    private final LoginStatus expected;

    private final LoginService service = new LoginService();

    public LoginServiceParameterizedTest(String email, String password, boolean blocked, LoginStatus expected) {
        this.email = email;
        this.password = password;
        this.blocked = blocked;
        this.expected = expected;
    }

    @Parameterized.Parameters(name = "{index}: {0}, blocked={2} => {3}")
    public static Collection<Object[]> data() {
        return Arrays.asList(new Object[][]{
                {"alice@xyz.com", "pass1", false, LoginStatus.SUCCESS},
                {"alice@xyz.com", "wrong", false, LoginStatus.INVALID_PASSWORD},
                {"unknown@xyz.com", "pass", false, LoginStatus.NOT_FOUND},
                {"invalid", "pass", false, LoginStatus.INVALID_EMAIL},
                {"bob@xyz.com", "pass2", true, LoginStatus.BLOCKED}
        });
    }

    @Test
    public void validatesLoginScenarios() {
        assertEquals(expected, service.login(email, password, blocked));
    }
}
