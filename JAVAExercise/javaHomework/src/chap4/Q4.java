package chap4;
import java.util.Scanner;
public class Q4 {
    public static void main(String[] args) {
        double a,b,c;
        Triangle noneParameter=new Triangle();
        System.out.println("noneParameter area: "+noneParameter.area());

        Scanner input=new Scanner(System.in);
        a=input.nextDouble();
        b=input.nextDouble();
        c=input.nextDouble();
        double tmp;
        if(a<b){
            if(c<b){
                tmp=c;
                c=b;
                b=tmp;
            }
        }
        else{
            if(c<a){
                tmp=c;
                c=a;
                a=tmp;
            }
        }
        while(a+b<=c){
            System.out.println(a+" "+b+" "+c+" can't be a triangle.");
            a=input.nextDouble();
            b=input.nextDouble();
            c=input.nextDouble();
            if(a<b){
                if(c<b){
                    tmp=c;
                    c=b;
                    b=tmp;
                }
            }
            else{
                if(c<a){
                    tmp=c;
                    c=a;
                    a=tmp;
                }
            }
        }
        Triangle onParameter=new Triangle(a,b,c);
        System.out.println(a+" "+b+" "+c+" area: "+onParameter.area());
    }
}
class Triangle{
    private double a,b,c;
    Triangle(){
        this.a=0;
        this.b=0;
        this.c=0;
    }
    Triangle(double a,double b,double c){
        this.a=a;
        this.b=b;
        this.c=c;
    }
    double area(){
        double s=(a+b+c)/2;
        return Math.sqrt(s*(s-a)*(s-b)*(s-c));
    }
}
