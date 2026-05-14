/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package stlab;

// src/Counter.java
public class Counter {

    private int count;

    // constructor → initializes to 0
    public Counter() {
        this.count = 0;
    }

    // increment → +1 and return new value
    public int increment() {
        count++;
        return count;
    }

    // decrement → -1 and return new value
    public int decrement() {
        count--;
        return count;
    }

    // helper (useful for testing state)
    public int getValue() {
        return count;
    }
}