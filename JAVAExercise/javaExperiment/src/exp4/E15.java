package exp4;

import java.util.Scanner;

public class E15 {
    public static void main(String[] args) {
        boolean isError=true;
        int a,b;
        Scanner in=new Scanner(System.in);
        System.out.println("Please enter two numbers:");
        while(isError)
        try{
            a=in.nextInt();
            b=in.nextInt();
            System.out.println("a + b = "+(a+b));
            isError=false;
        }
        catch(Exception e){
            System.out.println("Invalid input, again!");
            in.nextLine();
        }
    }
}
