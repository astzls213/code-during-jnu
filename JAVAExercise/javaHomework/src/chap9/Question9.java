package chap9;


public class Question9 {
    public static void main(String[] args) {

    }
}
@interface Author{
    String firstName() default "";
    String lastName() default "";
    boolean internalEmployee() default false;
}
@Author(firstName = "ZEGANG",lastName = "SHEN",internalEmployee = true)
class Employee{
    //...
}
