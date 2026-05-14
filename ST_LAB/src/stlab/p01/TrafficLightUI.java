package stlab.p01;

import javax.swing.ButtonGroup;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JPanel;
import javax.swing.JRadioButton;
import javax.swing.SwingConstants;
import javax.swing.SwingUtilities;
import java.awt.BorderLayout;
import java.awt.Color;
import java.awt.Font;

public class TrafficLightUI extends JFrame {
    private final TrafficLightLogic logic = new TrafficLightLogic();
    private final JLabel messageLabel = new JLabel("Select a light", SwingConstants.CENTER);

    public TrafficLightUI() {
        setTitle("Traffic Light System");
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setSize(380, 200);
        setLocationRelativeTo(null);

        JPanel radioPanel = new JPanel();
        JRadioButton redButton = new JRadioButton("Red");
        JRadioButton yellowButton = new JRadioButton("Yellow");
        JRadioButton greenButton = new JRadioButton("Green");

        ButtonGroup group = new ButtonGroup();
        group.add(redButton);
        group.add(yellowButton);
        group.add(greenButton);

        radioPanel.add(redButton);
        radioPanel.add(yellowButton);
        radioPanel.add(greenButton);

        messageLabel.setFont(new Font("SansSerif", Font.BOLD, 24));

        redButton.addActionListener(e -> updateMessage("Red"));
        yellowButton.addActionListener(e -> updateMessage("Yellow"));
        greenButton.addActionListener(e -> updateMessage("Green"));

        setLayout(new BorderLayout());
        add(radioPanel, BorderLayout.NORTH);
        add(messageLabel, BorderLayout.CENTER);
    }

    private void updateMessage(String colorName) {
        messageLabel.setText(logic.getMessage(colorName));
        messageLabel.setForeground(toAwtColor(logic.getDisplayColor(colorName)));
    }

    private Color toAwtColor(String colorName) {
        if ("red".equalsIgnoreCase(colorName)) {
            return Color.RED;
        }
        if ("yellow".equalsIgnoreCase(colorName)) {
            return Color.YELLOW;
        }
        if ("green".equalsIgnoreCase(colorName)) {
            return Color.GREEN;
        }
        return Color.BLACK;
    }

    public static void main(String[] args) {
        SwingUtilities.invokeLater(() -> new TrafficLightUI().setVisible(true));
    }
}
