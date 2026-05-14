package stlab.p10;

import java.util.HashMap;
import java.util.Map;

public class LoginValidator {
    private final Map<String, String> users = new HashMap<>();

    public LoginValidator() {
        users.put("user@example.com", "pass123");
    }

    public boolean validate(String username, String password) {
        if (username == null || password == null) {
            return false;
        }
        String stored = users.get(username);
        return stored != null && stored.equals(password);
    }
}
