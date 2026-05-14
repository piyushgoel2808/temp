/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package stlab;

// test/CounterTestRunner.java
import org.junit.runner.JUnitCore;
import org.junit.runner.Result;
import org.junit.runner.notification.Failure;

public class CounterTestRunner {

    public static void main(String[] args) {
        Result result = JUnitCore.runClasses(CounterTest.class);

        for (Failure f : result.getFailures()) {
            System.out.println(f.toString());
        }

        System.out.println("All tests passed: " + result.wasSuccessful());
    }
}