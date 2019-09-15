package day1Java;
import java.util.Scanner;
public class HelloWorld {
    public static void main(String[] args) {
        System.out.println("Enter numbers of loop:");
        Scanner scan=new Scanner(System.in);
        for(int i=scan.nextInt();i>0;i--)
            System.out.println("hello,world");
    }
}
