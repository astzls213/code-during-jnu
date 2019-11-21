package day4Java;

import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.util.Date;

public class op implements ActionListener {
    public void actionPerformed(ActionEvent event){
        System.out.println("Time now is: "+new Date());
        Toolkit.getDefaultToolkit().beep();
    }
}
