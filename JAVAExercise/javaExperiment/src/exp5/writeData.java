package exp5;

import java.io.*;

public class writeData {
    public static void main(String[] args) throws IOException {
        int i=6324;
        long l=6324*6324;
        short s=258;
        char c='s';
        boolean b=true;
        byte _byte=(byte)s;
        float f=3.14f;
        double d=3.1415926;
        String str="nmsl";

        File file=new File("out.dat");
        try{
            //create this file.
            file.createNewFile();
        }
        catch (IOException e){
            e.printStackTrace();
        }
        FileOutputStream fis=new FileOutputStream(file);
        DataOutputStream dis=new DataOutputStream(fis);
        dis.writeBoolean(b);
        dis.writeInt(i);
        dis.writeFloat(f);
        dis.writeDouble(d);
        dis.writeShort(s);
        dis.writeLong(l);
        dis.writeChars(str);
        dis.writeByte(_byte);
        dis.close();
        fis.close();
    }
}
