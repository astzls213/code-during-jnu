package chap10;


import java.util.Arrays;

public class Question9 {
    public static void main(String[] args) {
        String[] names={"zls","adasda","yass","bsadasd"};
        System.out.print("names: ");
        for(String n:names)
            System.out.print(n+" ");
        System.out.println();

        Arrays.sort(names,(String f,String t)->{
            return -f.toLowerCase().charAt(0)+t.toLowerCase().charAt(0);
        });
        System.out.println("Initial letter by descending order names:");
        for(String n:names)
            System.out.print(n+" ");
        System.out.println();

        Arrays.sort(names,(String f,String t)->{
            return -f.length()+t.length();
        });
        System.out.println("By length descending order names:");
        for(String n:names)
            System.out.print(n+" ");
        System.out.println();
    }
}
