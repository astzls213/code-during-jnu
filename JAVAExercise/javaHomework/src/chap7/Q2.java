package chap7;
import java.math.*;
import java.util.Scanner;

public class Q2 {
    public static void main(String[] args) {
        Scanner scan=new Scanner(System.in);
        System.out.println("Enter radius and height:");
        double radius=scan.nextDouble();
        double height=scan.nextDouble();
        Cylinder shape_Circle=new Cylinder(radius,height);
        System.out.println("Enter length,width and height:");
        double length=scan.nextDouble();
        double width=scan.nextDouble();
        height=scan.nextDouble();
        Cylinder shape_Rectangle=new Cylinder(length,width,height);
        System.out.println("Enter a,b,c(Triangle's edge) and height:");
        double a=scan.nextDouble();
        double b=scan.nextDouble();
        double c=scan.nextDouble();
        height=scan.nextDouble();
        Cylinder shape_Triangle=new Cylinder(a,b,c,height);

        String message_Circle=String.format("Circle:\nArea: %f\nVolume; %f\n",shape_Circle.getArea(),
                shape_Circle.getVolume());
        String message_Rectangle=String.format("Rectangle:\nArea: %f\nVolume; %f\n",shape_Rectangle.getArea(),
                shape_Rectangle.getVolume());
        String message_Triangle=String.format("Triangle:\nArea: %f\nVolume; %f\n",shape_Triangle.getArea(),
                shape_Triangle.getVolume());
        System.out.println(message_Circle+message_Rectangle+message_Triangle);
    }
}
class Circle{
    protected double centerX;
    protected double centerY;
    protected double radius;
    Circle(double radius){
        this.radius=radius;
    }
    Circle(){
        this(1.0);
    }
    double getArea(){
        return Math.PI*radius*radius;
    }
    double getPerimeter(){
        return 2*Math.PI*radius;
    }
    double getRadius(){
        return this.radius;
    }
    void setRadius(double r){
        this.radius=r;
    }
    void setCenterX(double x){
        this.centerX=x;
    }
    void setCenterY(double y){
        this.centerY=y;
    }
}
class Cylinder extends Circle{
    double height;
    double a,b,c;

    Cylinder(double r,double h){
        super.radius=r;
        this.height=h;
        this.a=0;
        this.b=0;
        this.c=0;
    }
    Cylinder(){
        super.radius=1.0;
        this.height=1.0;
        this.a=0;
        this.b=0;
        this.c=0;
    }
    Cylinder(double a,double b,double h){
        this.a=a;
        this.b=b;
        this.height=h;
    }
    Cylinder(double a,double b,double c,double h){
        this.a=a;
        this.b=b;
        this.c=c;
        this.height=h;
    }
    @Override
    double getArea(){
        if(a!=0&&c==0)
            return 2*(a*b)+(2*(a+b)*height);
        if(a!=0&&c!=0)
        {
            double s=(a+b+c)/2;
            return 2*(Math.sqrt(s*(s-a)*(s-b)*(s-c)))+(a+b+c)*height;
        }
        return 2*Math.PI*radius*radius+(height*(2*Math.PI*radius));
    }
    double getVolume(){
        if(a!=0&&c==0)
            return (a*b)*height;
        if(a!=0&&c!=0) {
            double s=(a+b+c)/2;
            return (Math.sqrt(s * (s - a) * (s - b) * (s - c)))*height;
        }
        return Math.PI*radius*radius*height;
    }
}
