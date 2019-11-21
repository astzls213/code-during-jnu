package chap9;

import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class Question3 {
    public static void main(String[] args) {
        try
        {
            method(5,1,2,3,4);
        }
        catch (Exception e)
        {
            e.printStackTrace();
        }
    }
    public static void method(int localVariable,double... args) throws ClassNotFoundException, IllegalAccessException, InstantiationException {
        class LocalInner{
            public void methodInner(){
                System.out.println(localVariable);
                if(args.length>0)
                    for(double arg:args)
                        System.out.println(arg);
            }
        }
        new LocalInner().methodInner();
    }
}
