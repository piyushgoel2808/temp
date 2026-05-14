package stlab.p01;

public enum TrafficLightColor {
    RED("STOP", "red"),
    YELLOW("READY", "yellow"),
    GREEN("GO", "green");

    private final String message;
    private final String displayColor;

    TrafficLightColor(String message, String displayColor) {
        this.message = message;
        this.displayColor = displayColor;
    }

    public String getMessage() {
        return message;
    }

    public String getDisplayColor() {
        return displayColor;
    }

    public static TrafficLightColor fromString(String value) {
        if (value == null) {
            throw new IllegalArgumentException("Color cannot be null");
        }
        String normalized = value.trim().toUpperCase();
        for (TrafficLightColor color : values()) {
            if (color.name().equals(normalized)) {
                return color;
            }
        }
        throw new IllegalArgumentException("Unknown color: " + value);
    }
}
