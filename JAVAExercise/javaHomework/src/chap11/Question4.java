package chap11;

import java.util.ArrayList;
import java.util.Iterator;

public class Question4 {
    public static void main(String[] args) {
        ArrayList<String> ar=new ArrayList<>();
        ar.add("zls");
        ar.add("cyf");
        ar.add("zfy");

        //Method1: Loop
        for(int i=0;i!=ar.size();i++){
            String tmp=ar.get(i).toUpperCase();
            ar.set(i,tmp);
            //System.out.println(ar.get(i));
        }
        //Method2: Iterator
        Iterator<String> iter=ar.iterator();
        while(iter.hasNext()){
            String tmp=iter.next().toUpperCase();
            ar.set(ar.indexOf(tmp.toLowerCase()),tmp);
        }
        //Method3: ReplaceAll
        ar.replaceAll(String::toUpperCase);
    }
}
