/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package stlab;

// src/SimpleInterest.java
public class SimpleInterest {

    public double calculateSI(double principal, double rate, double time) {
        if (principal < 0 || rate < 0 || time < 0) {
            throw new IllegalArgumentException("Values cannot be negative");
        }

        return (principal * rate * time) / 100;
    }
}