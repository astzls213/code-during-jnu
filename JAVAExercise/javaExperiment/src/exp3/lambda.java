package exp3;
import java.util.*;

public class lambda {
    public static void main(String[] args){
        String[] sa = {"east", "west", "south", "north"};
        Comparator<String> s = (a, b) -> b.compareTo(a);
        for(String s2: sa)
            System.out.print(s2 + " ");

        Arrays.sort(sa,s);
        System.out.println();
        for(String s2: sa)
            System.out.print(s2 + " ");
    }
}

