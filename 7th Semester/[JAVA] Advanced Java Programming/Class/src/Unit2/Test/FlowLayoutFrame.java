package LAB3;


import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class FlowLayoutFrame extends JFrame {
    private JButton button1, button2, button3;
    private FlowLayout layout;
    private Container container;

    public FlowLayoutFrame(){
        super("Testing FlowLayout");
        layout = new FlowLayout();
        setLayout(layout);
        container = getContentPane();

        button1 = new JButton("Left");
        button2 = new JButton("Center");
        button3 = new JButton("Right");

        add(button1);
        add(button2);
        add(button3);

        button1.addActionListener(
                new ActionListener() {
                    @Override
                    public void actionPerformed(ActionEvent actionEvent) {
                        layout.setAlignment(FlowLayout.LEFT);
                        layout.layoutContainer(container);
                    }
                }
        );

        button2.addActionListener(
                new ActionListener() {
                    @Override
                    public void actionPerformed(ActionEvent actionEvent) {
                        layout.setAlignment(FlowLayout.CENTER);
                        layout.layoutContainer(container);
                    }
                }
        );

        button3.addActionListener(
                new ActionListener() {
                    @Override
                    public void actionPerformed(ActionEvent actionEvent) {
                        layout.setAlignment(FlowLayout.RIGHT);
                        layout.layoutContainer(container);
                    }
                }
        );
    }
}
