package chap9;

import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class Question3 {
    private int group=1;
    public static void main(String[] args) {
        try
        {
            method(5,1,2,3,4);

            Question3 test=new Question3();
            Question3.ic test1=test.new ic();
            test1.ic_fun();
        }
        catch (Exception e)
        {
            e.printStackTrace();
        }
    }

    public static void method(final int localVariable,final double... args) {
        //If LocalInner access method's args and temp variable, they all must be final.
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
    //Inner Class
    public class ic{
        public void ic_fun(){
            //access outer class field: group
            System.out.print(group);
        }
    }
}
