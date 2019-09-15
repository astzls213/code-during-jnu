package chap2;
import java.util.*;
public class Q3 {
    public static void main(String[] args){
        double weight,height;
        double bmi;
        System.out.println("Enter your weight(kg) and height(m):");
        Scanner scan=new Scanner(System.in);
        weight=scan.nextDouble();
        height=scan.nextDouble();
        bmi=bmiCompute.bmi(weight, height);
        System.out.println("bmi : "+bmi);
    }
}
class bmiCompute{
    public static double bmi(double weight,double height){
        return weight/(height*height);
    }
}
