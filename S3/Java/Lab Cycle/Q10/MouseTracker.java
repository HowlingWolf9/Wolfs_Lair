import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;
import javax.swing.*;

public class MouseTracker {
    public static void main(String[] args) {
        JFrame frame = new JFrame("Mouse Tracker");
        frame.setSize(400, 400);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setVisible(true);
        frame.addMouseListener(new MouseAdapter() {
            @Override
            public void mouseClicked(MouseEvent e) {
                System.out.println("Mouse clicked at: " + e.getX() + ", " + e.getY());
            }

            @Override
            public void mouseDragged(MouseEvent e) {
                System.out.println("Mouse dragged to: " + e.getX() + ", " + e.getY());// this aint working
            }
        });
    }
}