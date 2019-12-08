package chap11;

import java.util.PriorityQueue;

public class Question9 {
    public static void main(String[] args) {
        int[] ar={1,5,3,7,6,9,8};
        PriorityQueue<Integer> q=new PriorityQueue<>();
        for(int i:ar){
            q.add(i);
        }
        q.forEach(System.out::println);
    }
}
