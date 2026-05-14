/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package stlab;

// src/TrafficLight.java
public class TrafficLight {

    public String getMessage(String color) {
        if (color == null) return "";

        switch (color.toLowerCase()) {
            case "red":
                return "STOP";
            case "yellow":
                return "READY";
            case "green":
                return "GO";
            default:
                return "";
        }
    }
}