/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package stlab;

// src/MessageUtil.java
public class MessageUtil {

    private String message;

    public MessageUtil(String message) {
        this.message = message;
    }

    public String printMessage() {
        return message;
    }

    public String updateMessage(String newMessage) {
        this.message = newMessage;
        return message;
    }
}