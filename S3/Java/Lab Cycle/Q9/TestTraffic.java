/*
Experiment: 9

AIM: Write a Java program that simulates a traffic light. The program lets the user select one of three lights: red, yellow, or green. When a radio button is selected, the light is turned on, and only one light can be on at a time. No light is on when the program starts

ALGORITHM:
Select color of the traffic light using radio buttons
A class TrafficLight is defined.
It extends JPanel and implements ActionListener
Define variables for colors, Red,Green,Orange
Three radio buttons usd to select color
At a time only one radio button should be activated. So group them using Button Group of javax.swing package
Radio button corresponding to red color is selected for initial screen.
When click on a radio button, for example green, make color of red and orange traffic lights to background color of JPanel.
red_c = getBackground ();
orange_c = getBackground();
green_c = Color.green;
Repaint all lights by using repaint() method.
The TrafficLight object is added to a JFrame in main() mathod
*/
//CODE:
import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

class TrafficLight extends JPanel implements ActionListener {
    private JRadioButton r1;
    private JRadioButton r2;
    private JRadioButton r3;
    private Color red_c;
    private Color green_c;
    private Color orange_c;

    public TrafficLight() {
        setBounds(0, 0, 600, 480);
        r1 = new JRadioButton("Red");
        r2 = new JRadioButton("Green");
        r3 = new JRadioButton("Orange");
        ButtonGroup group = new ButtonGroup();// javax.swing package
        r1.setSelected(true);
        group.add(r1);// Add radio button to group
        group.add(r2);
        group.add(r3); // Only one radio button selected at a time
        add(r1);
        add(r2);
        add(r3);// Added to JPanel
        red_c = Color.red; // In initial screen Light will be red
        green_c = getBackground();// returns background of JPanel
        // in RGB constraints.
        orange_c = getBackground();
        r1.addActionListener(this); // This class implements
        r2.addActionListener(this); // ActionListener
        r3.addActionListener(this);
    }

    public void actionPerformed(ActionEvent e) {
        if (r1.isSelected() == true) {
            red_c = Color.red;
            green_c = getBackground();
            orange_c = getBackground();
        } else if (r2.isSelected() == true) {
            red_c = getBackground();
            green_c = Color.green;
            orange_c = getBackground();
        } else if (r3.isSelected() == true) {
            red_c = getBackground();
            green_c = getBackground();
            orange_c = Color.orange;
        }
        repaint();
    }

    public void paintComponent(Graphics g)// Called by repaint()
    {
        super.paintComponent(g);// Do this befor going for custom painting
        // super class is JPanel
        g.drawOval(50, 50, 50, 50);
        g.drawOval(50, 110, 50, 50);
        g.drawOval(50, 170, 50, 50);
        g.setColor(red_c);
        g.fillOval(50, 50, 50, 50);
        g.setColor(orange_c);
        g.fillOval(50, 110, 50, 50);
        g.setColor(green_c);
        g.fillOval(50, 170, 50, 50); // At a time one color
    }
}

class TestTraffic {
    public static void main(String args[]) {
        JFrame f1 = new JFrame();
        f1.setVisible(true);
        f1.setSize(600, 480);
        f1.setLayout(null);
        TrafficLight t = new TrafficLight();
        f1.add(t);
    }
}