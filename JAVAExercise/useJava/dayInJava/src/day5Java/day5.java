package day5Java;

import java.awt.*;
import java.util.Date;
import javax.swing.*;

public class day5 {
    public static void main(String[] args) {
        Timer t=new Timer(1000, event -> {
            System.out.println("At the tone, now time is "+new Date());
            Toolkit.getDefaultToolkit().beep();
        });
        t.start();

        JOptionPane.showMessageDialog(null,"Quit program?");
        System.exit(0);
    }
}
