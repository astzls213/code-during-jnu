package chap6;

import java.util.Scanner;

public class Q3 {
    public static void main(String[] args) {
        String ISBN;
        Scanner input=new Scanner(System.in);
        System.out.println("Enter ISBN: ");
        ISBN=input.nextLine();
        if(judge.isISBN(ISBN))
            System.out.println("Accepted!");
        else
            System.out.println("Wrong format!");
    }
}
class judge{
    static boolean isISBN(String ISBN){
        if(ISBN.length()!=17)
            return false;
        if(ISBN.indexOf('-')==0)
            return false;
        if(ISBN.lastIndexOf('-')==ISBN.length()-1)
            return false;
        if(!ISBN.startsWith("978")&&!ISBN.startsWith("979"))
            return false;
        char[] chars=ISBN.toCharArray();
        int nums=0;
        for(int i=0;i<ISBN.length();i++){
            if(chars[i]=='-')
                nums++;
        }
        return nums == 4;
    }
}
