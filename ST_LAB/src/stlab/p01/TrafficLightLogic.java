package stlab.p01;

public class TrafficLightLogic {
    public String getMessage(String color) {
        return TrafficLightColor.fromString(color).getMessage();
    }

    public String getDisplayColor(String color) {
        return TrafficLightColor.fromString(color).getDisplayColor();
    }
}
