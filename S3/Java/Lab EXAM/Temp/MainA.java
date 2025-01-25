import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

class GUI {
    JFrame frame;
    JLabel cLabel, fLabel;
    JTextField cField, fField;
    JButton ctofButton, ftocButton;

    GUI(){
        frame = new JFrame("Temperature Converter");
        cLabel = new JLabel("Celsius:");
        fLabel = new JLabel("Fahrenheit:");
        cField = new JTextField();
        fField = new JTextField();
        ctofButton = new JButton("Convert to Fahrenheit");
        ftocButton = new JButton("Convert to Celsius");

        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setSize(600, 150);
        frame.setLayout(new GridLayout(2,3));
        frame.setVisible(true);
    
        frame.add(cLabel);
        frame.add(cField);
        frame.add(ctofButton);
        frame.add(fLabel);
        frame.add(fField);
        frame.add(ftocButton);

        /*
        ctofButton.addActionListener(ActionListener e{
            convertToF();
        });

        ftocButton.addActionListener(ActionListener e{
            convertToC();
        });
        */
    }

    public void convertToF() {
        double cel = Double.parseDouble(cField.getText());
        double fahr = (cel * 9 / 5) + 32;
        fField.setText("" + fahr);
    }

    public void convertToC() {
        double fahr = Double.parseDouble(fField.getText());
        double cel = (fahr - 32) * 5 / 9;
        cField.setText("" + cel);
    }
}

public class MainA {
    public static void main(String[] args) {
        GUI gui = new GUI();
    }

}
