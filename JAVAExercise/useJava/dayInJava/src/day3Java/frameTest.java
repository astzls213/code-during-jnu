package day3Java;

import  java.awt.*;
import javax.swing.*;

public class frameTest {
    public static void main(String[] args) {
        EventQueue.invokeLater(()->{
            JFrame frame=new SizedFrame();
            frame.setTitle("nmsl");
            frame.setDefaultCloseOperation(frame.EXIT_ON_CLOSE);
            frame.setVisible(true);
        });
    }
}
class SizedFrame extends JFrame{
    public SizedFrame(){
        Toolkit kit=Toolkit.getDefaultToolkit();
        Dimension screenSize=kit.getScreenSize();
        int screenHigh=screenSize.height;
        int screenWidth=screenSize.width;

        setSize(screenWidth/2,screenHigh/2);
        setLocationByPlatform(true);

        Image img=new ImageIcon("icon.gif").getImage();
        setIconImage(img);
    }
}
