package exp4;

import java.util.*;

public class E13 {
    public static void main(String[] args) {
        Random random=new Random();
        Set<Integer> hash=new HashSet<>(10);
        for(int i=0;i<10;i++)
            hash.add(10+random.nextInt(89));
        SortedSet<Integer> tree=new TreeSet<>();
        for(int i=0;i<10;i++)
            tree.add(10+random.nextInt(89));
        System.out.println("Hash:");
        Iterator<Integer> iter=hash.iterator();
        for(int i=1;i<=10&&iter.hasNext();i++)
            System.out.print(iter.next()+" ");
        System.out.println("\nTree:");
        System.out.println(tree);
    }
}
