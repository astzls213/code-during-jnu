package chap12;

import java.io.IOException;

public class Question5 {
    /*
        if IOException not be added at the end of methodB, compiler will throws a error.
     */
    public static void main(String[] args) {

    }
    public static void methodA() throws IOException{

    }
    public static void methodB() throws IOException {
        methodA();
    }
}
