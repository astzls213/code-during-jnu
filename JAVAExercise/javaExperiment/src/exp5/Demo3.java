package exp5;

import java.io.*;
import java.util.zip.*;

public class Demo3 {
    //zipOutputStream
    public static void main(String[] args) throws Exception {
        operationForDemo3 demo=new operationForDemo3("mydoc","zipFile.zip");
        File zip=new File("zipFile.zip");
        demo.zip();
        demo.unzip(zip,"./my");
    }
}
