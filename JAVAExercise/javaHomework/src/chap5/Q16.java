package chap5;
import java.util.Scanner;
public class Q16 {
    public static void main(String[] args) {
        int r,c;
        System.out.println("Row and Column: ");
        Scanner input=new Scanner(System.in);
        r=input.nextInt();
        c=input.nextInt();
        double max=0;
        int pos=-1;
        for(int i=0;i<r*c;i++){
            double tmp=input.nextDouble();
            if(tmp>max)
            {
                max=tmp;
                pos=i;
            }
        }
        System.out.println("("+pos/c+","+pos%c+")");
    }
}
