package day5Java;
import javax.print.attribute.standard.JobKOctetsProcessed;
import javax.swing.Timer;
import java.util.*;
import javax.swing.*;
public class methodReference {
    public static void main(String[] args) {
        Timer t=new Timer(1000,System.out::println);
        t.start();
        JOptionPane .showMessageDialog(null,"Quit?");
        System.exit(0);
    }
}

