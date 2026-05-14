package stlab.p01;

import org.junit.Test;

import static org.junit.Assert.assertEquals;

public class TrafficLightLogicTest {
    private final TrafficLightLogic logic = new TrafficLightLogic();

    @Test
    public void redShowsStop() {
        assertEquals("STOP", logic.getMessage("Red"));
        assertEquals("red", logic.getDisplayColor("Red"));
    }

    @Test
    public void yellowShowsReady() {
        assertEquals("READY", logic.getMessage("Yellow"));
        assertEquals("yellow", logic.getDisplayColor("Yellow"));
    }

    @Test
    public void greenShowsGo() {
        assertEquals("GO", logic.getMessage("Green"));
        assertEquals("green", logic.getDisplayColor("Green"));
    }
}
