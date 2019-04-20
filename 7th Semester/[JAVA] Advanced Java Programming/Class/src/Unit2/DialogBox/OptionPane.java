package Unit2.DialogBox;

import javax.swing.*;

public class InputDialogBox {
    public static void main(String[] args) {
        int a = Integer.parseInt(JOptionPane.showInputDialog("Enter first number"));
        int b = Integer.parseInt(JOptionPane.showInputDialog("Enter second number"));

        int sum = a + b;

        JOptionPane.showMessageDialog(null, "The sum is " + sum, "Result", JOptionPane.ERROR_MESSAGE);
        JOptionPane.showMessageDialog(null, "The sum is " + sum, "Result", JOptionPane.PLAIN_MESSAGE);
        JOptionPane.showMessageDialog(null, "The sum is " + sum, "Result", JOptionPane.INFORMATION_MESSAGE);
        JOptionPane.showMessageDialog(null, "The sum is " + sum, "Result", JOptionPane.QUESTION_MESSAGE);
        JOptionPane.showMessageDialog(null, "The sum is " + sum, "Result", JOptionPane.WARNING_MESSAGE);

    }
}
