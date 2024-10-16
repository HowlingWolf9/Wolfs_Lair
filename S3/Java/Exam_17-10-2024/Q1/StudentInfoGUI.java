import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.ItemEvent;
import java.awt.event.ItemListener;

public class StudentInfoGUI {
    public static void main(String[] args) {
        // Create a new JFrame
        JFrame frame = new JFrame("Student Information");
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setLayout(new FlowLayout());

        // Create labels and text fields
        JLabel nameLabel = new JLabel("Name:");
        JTextField nameField = new JTextField(20);

        JLabel branchLabel = new JLabel("Branch:");
        JTextField branchField = new JTextField(20);

        JLabel batchLabel = new JLabel("Batch:");
        JTextField batchField = new JTextField(20);

        // Create checkboxes
        JCheckBox isKasargod = new JCheckBox("Kasargod");
        JCheckBox isKannur = new JCheckBox("Kannur");

        // Create buttons
        JButton saveButton = new JButton("Save");
        JButton cancelButton = new JButton("Cancel");

        // Add checkboxes to the frame
        frame.add(nameLabel);
        frame.add(nameField);
        frame.add(branchLabel);
        frame.add(branchField);
        frame.add(batchLabel);
        frame.add(batchField);
        frame.add(isKasargod);
        frame.add(isKannur);
        frame.add(saveButton);
        frame.add(cancelButton);

        // Set the frame size and make it visible
        frame.setSize(225, 250);
        frame.setVisible(true);

        // Add item listener to checkboxes
        isKasargod.addItemListener(new ItemListener() {
            @Override
            public void itemStateChanged(ItemEvent e) {
                if (e.getStateChange() == ItemEvent.SELECTED) {
                    isKannur.setSelected(false);
                }
            }
        });

        isKannur.addItemListener(new ItemListener() {
            @Override
            public void itemStateChanged(ItemEvent e) {
                if (e.getStateChange() == ItemEvent.SELECTED) {
                    isKasargod.setSelected(false);
                }
            }
        });
        // Add action listener to buttons
        saveButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                // Get the values from the text fields and checkboxes
                String name = nameField.getText();
                String branch = branchField.getText();
                String batch = batchField.getText();
                String district = isKasargod.isSelected() ? "Kasargod" : isKannur.isSelected() ? "Kannur" : "";

                // Print the values to the console
                System.out.println("Name: " + name);
                System.out.println("Branch: " + branch);
                System.out.println("Batch: " + batch);
                System.out.println("District: " + district);

                // Clear the text fields and checkboxes
                nameField.setText("");
                branchField.setText("");
                batchField.setText("");
                isKasargod.setSelected(false);
                isKannur.setSelected(false);
            }
        });

        cancelButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                // Clear the text fields and checkboxes
                nameField.setText("");
                branchField.setText("");
                batchField.setText("");
                isKasargod.setSelected(false);
                isKannur.setSelected(false);
            }
        });
    }
}

/*
ALGORITHM: StudentInfoGUI
1. Create a new JFrame
2. Create labels and text fields
3. Create checkboxes
4. Create buttons
5. Add labels, text fields, checkboxes and buttons to the frame
6. Add item listener to checkboxes
    - If the checkbox is selected, unselect the other checkbox
7. Add action listener to buttons
    - When the save button is clicked
        - Get the values from the text fields and checkboxes
        - Print the values to the console
        - Clear the text fields and checkboxes
    - When the cancel button is clicked
        - Clear the text fields and checkboxes
 8. Set the frame size and make it visible
 */
