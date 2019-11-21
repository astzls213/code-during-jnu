package chap10;

import java.util.Scanner;

public class Question12 {
    public static void main(String[] args) {
        Calculator calculator=(int a,int b)->{return Math.pow(a,2)+Math.pow(b,2);};
        if(args.length==2){
            System.out.println(calculator.calculate(Integer.parseInt(args[0]),Integer.parseInt(args[1])));
        }
        if(args.length==0){
            Scanner in=new Scanner(System.in);
            System.out.println(calculator.calculate(in.nextInt(),in.nextInt()));
        }
        else{
            System.out.println("Too many or too little arguments!");
        }
    }
}
