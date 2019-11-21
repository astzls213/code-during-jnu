package day4Java;

import javax.swing.*;
import java.awt.event.*;
import java.awt.*;
import java.util.*;
import javax.swing.Timer;

public class callBack {
    public static void main(String[] args) {
        ActionListener Operation=new op();
        Timer test=new Timer(1000, Operation);
        test.start();
        JOptionPane.showMessageDialog(null,"Quit program?");
        System.exit(0);
    }
}

