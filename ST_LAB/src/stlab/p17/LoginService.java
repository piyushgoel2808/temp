package stlab.p17;

import java.util.HashMap;
import java.util.Map;

public class LoginService {
    private final Map<String, String> users = new HashMap<>();

    public LoginService() {
        users.put("alice@xyz.com", "pass1");
        users.put("bob@xyz.com", "pass2");
    }

    public LoginStatus login(String email, String password, boolean blocked) {
        if (blocked) {
            return LoginStatus.BLOCKED;
        }
        if (!isValidEmail(email)) {
            return LoginStatus.INVALID_EMAIL;
        }
        String stored = users.get(email);
        if (stored == null) {
            return LoginStatus.NOT_FOUND;
        }
        if (!stored.equals(password)) {
            return LoginStatus.INVALID_PASSWORD;
        }
        return LoginStatus.SUCCESS;
    }

    private boolean isValidEmail(String email) {
        return email != null && email.contains("@") && email.contains(".");
    }
}
