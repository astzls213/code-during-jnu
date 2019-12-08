package chap12;

public class Question6 {
    public static void main(String[] args) {
        try{
            throw new MyException("GG, Your computer broken.");
        }
        catch(MyException e){
            e.printErrorMessage();
        }
    }
}
class MyException extends Exception{
    private String msg;
    public MyException(String msg){
        this.msg=msg;
    }
    public void printErrorMessage(){
        System.out.println(msg);
    }
}