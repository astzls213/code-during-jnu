package exp4;

import java.util.*;
import java.util.stream.Stream;

public class E14 {
    public static void main(String[] args) {
        Random random=new Random();
        List<Integer> numbers=new ArrayList<>(1000);
        for(int i=0;i!=1000;i++)
            numbers.add(100+random.nextInt(899));
        Stream<Integer> work=numbers.stream()
                .filter(n->n%7==0||n/100==7||n/10%10==7||n%10==7);
        long count=numbers.stream()
                .filter(n->n%7==0||n/100==7||n/10%10==7||n%10==7)
                .count();
        System.out.println(count);
        Object[] ar=work.toArray();
        for(Object i:ar)
            System.out.print((Integer)i+" ");

    }
}
