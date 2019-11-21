package day4Java;

import java.util.Arrays;
import java.util.Date;

public class LearnComparator {
    public static void main(String[] args) {
        String[] nameSet={"zls","zhenluosheng","fuck","z"};
        Arrays.sort(nameSet,new LengthComparator());
        for (String name:nameSet)
            System.out.println(name);
        System.out.println(new Date());
    }
}
