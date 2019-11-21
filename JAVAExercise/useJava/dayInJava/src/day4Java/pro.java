package day4Java;
import day1Java.*;
public class pro {
    public static void main(String[] args) {
        Employee e=new Employee("cyf",1,2000,11,5);
        Employee e1=new Employee("cyf",2,2000,11,5);
        System.out.println(e.equals(e1));

        student test=new student();
        System.out.print(test.getName());
    }
}
//a test for default methods in interface.
interface Named {
    String getName();
}
interface Person{
    default String getName(){
        return "person";
    }
}
class student implements Person,Named{
    public String getName(){
        return "ss";
    }
}