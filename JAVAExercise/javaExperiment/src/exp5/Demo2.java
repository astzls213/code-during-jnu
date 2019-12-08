package exp5;

import java.io.File;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.ObjectOutputStream;

public class Demo2 {
    /* This is a demo.
     * Used to test objectOutputStream.
     */
    public static void main(String[] args) throws IOException{
        File file=new File("student.dat");
        try{
            //create this file.
            file.createNewFile();
        }
        catch (IOException e){
            e.printStackTrace();
        }
        ObjectOutputStream oos=new ObjectOutputStream(new FileOutputStream(file));

        student stu=new student("Jack",2000,11,5);
        String str="Hey man!";
        oos.writeObject(stu);
        oos.writeObject(str);
        oos.close();
    }
}
