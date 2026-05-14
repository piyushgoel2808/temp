/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package stlab;

// src/LoginService.java
public class LoginService {

    public String login(String email, boolean exists, boolean correctPassword, boolean blocked) {

        if (email == null || !email.contains("@")) {
            return "Invalid Email";
        }

        if (!exists) {
            return "User Not Found";
        }

        if (blocked) {
            return "Account Blocked";
        }

        if (!correctPassword) {
            return "Wrong Password";
        }

        return "Login Success";
    }
}
