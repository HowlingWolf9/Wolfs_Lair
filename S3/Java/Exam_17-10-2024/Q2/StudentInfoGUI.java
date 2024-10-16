import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class StudentInfoGUI {
    public static void main(String[] args) {
        // Create a new JFrame
        JFrame frame = new JFrame("Student Information");
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setLayout(new FlowLayout());

        // Create labels and text fields
        JLabel nameLabel = new JLabel("Name:");
        JTextField nameField = new JTextField(20);

        JLabel classLabel = new JLabel("Class:");
        JTextField classField = new JTextField(20);

        JLabel rollLabel = new JLabel("Roll:");
        JTextField rollField = new JTextField(20);

        JLabel mobileLabel = new JLabel("Mobile:");
        JTextField mobileField = new JTextField(20);

        JLabel lbsLabel = new JLabel("LBS College of Engineering");
        lbsLabel.setFont(new Font("Verdana", Font.PLAIN, 15));

        // Create buttons
        JButton registerButton = new JButton("Register");
        JButton clearButton = new JButton("Clear");
        JButton askButton = new JButton("Ask");

        // Add checkboxes to the frame
        frame.add(nameLabel);
        frame.add(nameField);
        frame.add(classLabel);
        frame.add(classField);
        frame.add(rollLabel);
        frame.add(rollField);
        frame.add(mobileLabel);
        frame.add(mobileField);
        frame.add(registerButton);
        frame.add(clearButton);
        frame.add(askButton);
        frame.add(lbsLabel);

        // Set the frame size and make it visible
        frame.setSize(225, 350);
        frame.setVisible(true);

        // Add action listener to buttons
        registerButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                // Get the values from the text fields and checkboxes
                String name = nameField.getText();
                String clas = classField.getText();
                String roll = rollField.getText();
                String mobile = mobileField.getText();

                // Print the values to the console
                System.out.println("Name: " + name);
                System.out.println("Class: " + clas);
                System.out.println("Roll: " + roll);
                System.out.println("Mobile: " + mobile);

                // Clear the text fields and checkboxes
                nameField.setText("");
                classField.setText("");
                rollField.setText("");
                mobileField.setText("");
            }
        });

        clearButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                // Clear the text fields and checkboxes
                nameField.setText("");
                classField.setText("");
                rollField.setText("");
                mobileField.setText("");
            }
        });
    }
}