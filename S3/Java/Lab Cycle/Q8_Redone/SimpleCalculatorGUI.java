import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

class Calc implements ActionListener {
    JFrame frame;
    JTextField prevField, currentField;
    JPanel buttonPanel;
    String operator;
    double num1, num2, result;

    Calc() {
        frame = new JFrame("CALCULATOR");
        prevField = new JTextField(15);
        prevField.setEditable(false);
        currentField = new JTextField(15);

        buttonPanel = new JPanel();
        String[] buttons = {
                "7", "8", "9", "/",
                "4", "5", "6", "*",
                "1", "2", "3", "-",
                "0", "C", "=", "+"
        };
        buttonPanel.setLayout(new GridLayout(4, 4));
        for (String b : buttons) {
            JButton buttonText = new JButton(b);
            buttonText.addActionListener(this);
            buttonPanel.add(buttonText);
        }

        frame.setLayout(new FlowLayout());
        frame.add(prevField);
        frame.add(currentField);
        frame.add(buttonPanel);

        frame.setSize(300, 300);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setVisible(true);

    }

    public void actionPerformed(ActionEvent e) {
        if (currentField.getText().equals("Error") || equals("Cannot divide by zero")) {
            currentField.setText(null);
            result = 0;
        }
        String command = e.getActionCommand();
        System.out.println(command);
        try {
            if (command.equals("C")) {
                currentField.setText(null);
                prevField.setText(null);
                num1 = num2 = result = 0;
                operator = null;
            } else if (command.equals("=")) {
                if (prevField.getText().contains("=")) {
                    prevField.setText(null);
                }
                prevField.setText(prevField.getText() + currentField.getText() + "=");
                num2 = Double.parseDouble(currentField.getText());
                calculate(num1, num2, operator);
                currentField.setText(String.valueOf(result));
                operator = null;
            } else if ("+-*/".contains(command)) {
                num1 = Double.parseDouble(currentField.getText());
                operator = command;
                if (prevField.getText().contains(command) && !currentField.getText().equals(null)) {
                    num2 = Double.parseDouble(currentField.getText());
                    calculate(num1, num2, operator);
                    currentField.setText(String.valueOf(result));
                } else if (prevField.getText().contains(command) && !prevField.getText().contains("=")) {
                    prevField.setText(prevField.getText());
                } else {
                    prevField.setText(currentField.getText() + command);
                    currentField.setText(null);
                }
            } else {
                if (prevField.getText().contains("=") && !prevField.getText().contains(command)) {
                    currentField.setText(null);
                }
                currentField.setText(currentField.getText() + command);
            }
        } catch (Exception ex) {
        }
    }

    public void calculate(double num1, double num2, String operator) {
        switch (operator) {
            case "+":
                result = num1 + num2;
                break;
            case "-":
                result = num1 - num2;
                break;
            case "*":
                result = num1 * num2;
                break;
            case "/":
                if (num2 == 0) {
                    currentField.setText("Cannot divide by zero");
                    return;
                }
                result = num1 / num2;
                break;
            default:
                if (num2 == 0) {
                    currentField.setText(prevField.getText());
                    return;
                }
                break;
        }
    }
}

public class SimpleCalculatorGUI {
    public static void main(String[] args) {
        Calc calc = new Calc();
    }
}