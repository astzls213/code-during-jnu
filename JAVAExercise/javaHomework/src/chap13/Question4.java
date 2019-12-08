package chap13;

import java.io.*;
import java.time.Instant;
import java.util.Random;

public class Question4 {
    public static void main(String[] args) {
        try{
            Random random=new Random();
            File dest=new File("data.dat");
            if(!dest.exists())
                dest.createNewFile();
            FileOutputStream out=new FileOutputStream(dest);
            DataOutputStream dos=new DataOutputStream(out);
            for(int i=0;i!=10;i++)
                dos.writeInt(1000+random.nextInt(1000));
            dos.close();
            out.close();
        }
        catch(IOException e){
            e.printStackTrace();
        }
        try(DataInputStream dis=new DataInputStream(new FileInputStream(new File("data.dat"))))
        {
            int[] ar=new int[10];
            for(int i=0;i<10;i++)
                ar[i]=dis.readInt();
            for(int i:ar)
                System.out.print(i+"\t");
        } catch (IOException e){
            e.printStackTrace();
        }
    }
}
