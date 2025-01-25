/*
Experiment: 8

AIM: Write a Java program that works as a simple calculator. Arrange Buttons for digits and the + - * % operations properly. Add a text field to display the result. Handle any possible exceptions like divide by zero. Use Java Swing. 

ALGORITHM:
Create class CalculatorGUI
calculationField , a JTextField is the screen of calculator.

When the user click number buttons, they should append to the text incalculationField(a text field). For this, a class NumberButtonListener created and this implemnts ActionListener.Overridden actionPrformed(). While adding the action listener on these buttons, an instance of NumberButtonListener is passed as argument. The constructor of NumberButtonListener receives an instance of CalculatorGUI as parameter.

When user click operator button, an operator is appended to the text in calculationField.For this, a class OperatorButtonListener used, which implements ActionListener. Overridden actionPrformed(). While adding the action listener on these buttons, an instance of OperatorButtonListener is passed as argument.
The constructor of OperatorButtonListener receives an instance of CalculatorGUI as parameter.

When user click = button, The text from calculationField is taken and separate, operand1 , operand2 and operator using String.split(); This function returns an array of string. If its length !=3 , display an error message in calculationField. The result of operation is displayed oherwise.A class ButtonEquals assigned for this, which implements ActionListener.

When user click CLEAR button,the result screen is cleared. A class ButtonClear is there for this activity, which implements ActionListener
*/
//CODE:
import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

class NumberButtonListener implements ActionListener {
    CalculatorGUI c;

    NumberButtonListener(CalculatorGUI c) {
        this.c = c;
    }

    public void actionPerformed(ActionEvent e) {
        JButton button = (JButton) e.getSource();

        c.calculationField.setText(c.calculationField.getText() + button.getText());
    }
}

class OperatorButtonListener implements ActionListener {
    CalculatorGUI c;

    OperatorButtonListener(CalculatorGUI c) {
        this.c = c;
    }

    public void actionPerformed(ActionEvent e) {
        JButton button = (JButton) e.getSource();
        c.calculationField.setText(c.calculationField.getText() + " " + button.getText() + " ");
    }
}

class ButtonClear implements ActionListener {
    CalculatorGUI c;

    ButtonClear(CalculatorGUI c) {
        this.c = c;
    }

    public void actionPerformed(ActionEvent e) {
        c.calculationField.setText("");
    }
}

class ButtonEquals implements ActionListener {
    CalculatorGUI c;

    ButtonEquals(CalculatorGUI c) {
        this.c = c;
    }

    public void actionPerformed(ActionEvent e) {
        String input = c.calculationField.getText();
        String[] tokens = input.split(" ");
        if (tokens.length != 3) {
            c.calculationField.setText("Error: Invalid input");
            return;
        }
        try {
            float operand1 = Integer.parseInt(tokens[0]);
            float operand2 = Integer.parseInt(tokens[2]);

            String operator = tokens[1];
            float result = 0;
            switch (operator) {
                case "+":
                    result = operand1 + operand2;
                    break;
                case "-":
                    result = operand1 - operand2;
                    break;
                case "*":
                    result = operand1 * operand2;
                    break;
                case "/":
                    if (operand2 == 0) {
                        c.calculationField.setText("Error: Division by zero");
                        return;
                    }
                    result = operand1 / operand2;
                    break;
                default:
                    c.calculationField.setText("Error: Invalid operator");
                    return;
            }// End switch
            c.calculationField.setText(String.valueOf(result));
        } catch (NumberFormatException ex) {
            c.calculationField.setText("Error: Invalid number format");
        } // End try-catch
    }// End actionPerformed()
}// End class

class CalculatorGUI {
    JTextField calculationField;
    JFrame frame;
    JButton button1;
    JButton button2;
    JButton button3;
    JButton button4;
    JButton button5;
    JButton button6;
    JButton button7;
    JButton button8;
    JButton button9;
    JButton button0;
    JButton buttonClear;
    JButton buttonEquals;
    JButton buttonAdd;
    JButton buttonSubtract;
    JButton buttonMultiply;
    JButton buttonDivide;

    CalculatorGUI() {
        frame = new JFrame("Calculator");
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setSize(225, 200);
        frame.setLayout(new FlowLayout());
        frame.setVisible(true);
        calculationField = new JTextField(20);
        button1 = new JButton("1");
        button2 = new JButton("2");
        button3 = new JButton("3");
        button4 = new JButton("4");
        button5 = new JButton("5");
        button6 = new JButton("6");
        button7 = new JButton("7");
        button8 = new JButton("8");
        button9 = new JButton("9");
        button0 = new JButton("0");
        buttonClear = new JButton("C");
        buttonEquals = new JButton("=");
        buttonAdd = new JButton("+");
        buttonSubtract = new JButton("-");
        buttonMultiply = new JButton("*");
        buttonDivide = new JButton("/");
        frame.add(calculationField);
        frame.add(button1);
        frame.add(button2);
        frame.add(button3);
        frame.add(buttonClear);
        frame.add(button4);
        frame.add(button5);
        frame.add(button6);
        frame.add(buttonAdd);
        frame.add(button7);
        frame.add(button8);
        frame.add(button9);
        frame.add(buttonSubtract);
        frame.add(button0);
        frame.add(buttonEquals);
        frame.add(buttonMultiply);
        frame.add(buttonDivide);
        NumberButtonListener numberButtonListener = new NumberButtonListener(this);
        button1.addActionListener(numberButtonListener);
        button2.addActionListener(numberButtonListener);
        button3.addActionListener(numberButtonListener);
        button4.addActionListener(numberButtonListener);
        button5.addActionListener(numberButtonListener);
        button6.addActionListener(numberButtonListener);
        button7.addActionListener(numberButtonListener);
        button8.addActionListener(numberButtonListener);
        button9.addActionListener(numberButtonListener);
        button0.addActionListener(numberButtonListener);
        OperatorButtonListener operatorButtonListener = new OperatorButtonListener(this);
        buttonAdd.addActionListener(operatorButtonListener);
        buttonSubtract.addActionListener(operatorButtonListener);
        buttonMultiply.addActionListener(operatorButtonListener);
        buttonDivide.addActionListener(operatorButtonListener);
        ButtonClear buttonClearObj = new ButtonClear(this);
        ButtonEquals buttonEqualsObj = new ButtonEquals(this);
        buttonClear.addActionListener(buttonClearObj);
        buttonEquals.addActionListener(buttonEqualsObj);
    }// End of constructor
}

public class SimpleCalculatorG {
    public static void main(String[] args) {
        CalculatorGUI c = new CalculatorGUI();
    }
}