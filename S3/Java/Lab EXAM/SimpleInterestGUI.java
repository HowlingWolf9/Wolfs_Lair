import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

public class SimpleInterestGUI {
    JFrame frame;
    JButton calcButton;
    JTextField amountField, interestField, yearsField, resultField;

    public SimpleInterestGUI() {
        frame = new JFrame("Simple Interest Calculator");
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setSize(400, 200);
        frame.setLayout(new GridLayout(5, 1));

        amountField = new JTextField(10);
        interestField = new JTextField(10);
        yearsField = new JTextField(10);
        resultField = new JTextField(10);
        resultField.setEditable(false);

        calcButton = new JButton("Calculate");
        calcButton.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                calculateInterest();
            }
        });

        frame.add(new JLabel("Amount:"));
        frame.add(amountField);
        frame.add(new JLabel("Interest:"));
        frame.add(interestField);
        frame.add(new JLabel("Years:"));
        frame.add(yearsField);
        frame.add(new JLabel("Result:"));
        frame.add(resultField);
        frame.add(calcButton);
        frame.setVisible(true);
    }

    public void calculateInterest() {
        double amount = Double.parseDouble(amountField.getText());
        double interest = Double.parseDouble(interestField.getText());
        int years = Integer.parseInt(yearsField.getText());
        double result = amount * (1 + interest / 100 * years);
        resultField.setText(String.format("%.2f", result));
    }

    public static void main(String[] args) {
        SimpleInterestGUI gui = new SimpleInterestGUI();
    }

}