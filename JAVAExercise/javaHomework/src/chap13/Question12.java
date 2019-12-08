package chap13;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.HashSet;
import java.util.Iterator;
import java.util.Set;

public class Question12 {
    public static void main(String[] args) {
        try {
            BufferedReader bf = new BufferedReader(new FileReader("novel"));

            String text="";
            String tmp=bf.readLine();
            while(tmp!=null){
                text=text.concat(tmp);
                tmp=bf.readLine();
            }

            String[] words=text.split(" ");//get words in text
            Set<String> redundancy=new HashSet<>();
            Set<String> not_repeated=new HashSet<>();
            for(String word:words){
                if(!not_repeated.contains(word)){
                    not_repeated.add(word);
                }
                else{
                    not_repeated.remove(word);
                    redundancy.add(word);
                }
            }

            for (String s : not_repeated) {
                System.out.println(s);
            }
        }
        catch (IOException e){
            e.printStackTrace();
        }
    }
}
