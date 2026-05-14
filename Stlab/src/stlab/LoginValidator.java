/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package stlab;

// src/LoginValidator.java
public class LoginValidator {

    public boolean validate(String username, String password) {
        if (username == null || password == null) return false;

        if (username.isEmpty() || password.isEmpty()) return false;

        return username.equals("admin") && password.equals("1234");
    }
}