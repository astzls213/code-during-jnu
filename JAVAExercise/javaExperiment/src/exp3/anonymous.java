package exp3;
import java.util.*;
public class anonymous {

        public static void main(String[] args){
            String[] sa = {"east", "west", "south", "north"};
            Comparator<String> s = new Comparator<String>() {
                @Override
                public int compare(String a, String b) {
                    return b.compareTo(a);
                }
            };
            for(String s2: sa) System.out.print(s2 + " ");
            Arrays.sort(sa,s);
            System.out.println();
            for(String s2: sa) System.out.print(s2 + " ");
        }
}
