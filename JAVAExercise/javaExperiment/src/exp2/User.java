package exp2;

import java.util.Scanner;

public class User {
    public static void main(String[] args) {
        vehicle benz=new vehicle(300);
        System.out.println("Now power set to 77!");
        benz.setPower(77);
        System.out.println("Now speed up by 7!");
        benz.speedUp(7);
        System.out.println("Now speed down 7!");
        benz.speedDown(7);
        System.out.println(benz.getPower());
    }
}
class vehicle{
    private double speed;
    private int power;
    vehicle(){
        power=0;
        speed=50.0;
    }
    vehicle(double speed){
        this.speed=speed;
        power=0;
    }
    void setPower(int n){
        power=n;
    }
    int getPower(){
        return power;
    }
    void speedUp(int s){
        power+=s;
    }
    void speedDown(int s){
        power-=s;
    }
}
