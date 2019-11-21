package day5Java;

import day1Java.Employee;

import java.util.ArrayList;

public class test {
    public static void main(String[] args) {
        InnerClassTest.Pair p=InnerClassTest.minmax(new int[]{1,2,3,4,5,100,-1});
        System.out.print(p.getFirst()+" "+p.getSecond());
    }
}
