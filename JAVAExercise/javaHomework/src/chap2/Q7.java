package chap2;

import java.math.*;
import java.util.Scanner;
public class Q7 {
    public static void main(String[] args) {
        Scanner scan=new Scanner(System.in);
        int years=scan.nextInt();
        double paymentPerMonth=payment.perMonth(scan.nextDouble(),
                scan.nextInt(),years);
        System.out.println("Payment per month: "+paymentPerMonth);
        System.out.println("Total payment: "+(years*12*paymentPerMonth));
    }
}
class payment{
    public static double perMonth(double annualInterestRate,int money,int years){
        double monthInterestRate=annualInterestRate/12;
        return (money*monthInterestRate)/(1-(1/Math.pow(1+monthInterestRate,years*12)));
    }
}
