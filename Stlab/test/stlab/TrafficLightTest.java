/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/UnitTests/JUnit4TestClass.java to edit this template
 */
package stlab;




import org.junit.Test;
import static org.junit.Assert.*;

public class TrafficLightTest {

    private final TrafficLight tl = new TrafficLight();

    @Test
    public void testRed() {
        assertEquals("STOP", tl.getMessage("red"));
    }

    @Test
    public void testYellow() {
        assertEquals("READY", tl.getMessage("yellow"));
    }

    @Test
    public void testGreen() {
        assertEquals("GO", tl.getMessage("green"));
    }

    @Test
    public void testInvalidColor() {
        assertEquals("", tl.getMessage("blue"));
    }

    @Test
    public void testNullInput() {
        assertEquals("", tl.getMessage(null));
    }

    @Test
    public void testCaseInsensitive() {
        assertEquals("STOP", tl.getMessage("RED"));
    }
}