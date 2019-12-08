package chap13;

import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.util.Scanner;

public class Question7 {
    public static void main(String[] args) {
        Path path= Paths.get("./hh.dat");
        boolean fileExists= Files.exists(path);

        if(fileExists){
            try {
                System.out.println("New name:");
                Scanner in = new Scanner(System.in);
                String tmp = in.nextLine();
                String suffix=path.getFileName().toString().split("\\.")[1];
                String fileName=String.join(".",tmp,suffix);
                Files.move(path, Paths.get(path.getParent() + "/" +fileName));
            }
            catch (IOException e){
                e.printStackTrace();
            }
        }
        else{
            System.out.println("File not existed!");
        }
    }
}
