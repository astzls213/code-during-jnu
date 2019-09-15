package day1Java;
import java.util.Scanner;
public class bankAccount {
    public static void main(String[] args) {
        Employee[] staff=new Employee[3];//I have 3 staffs.
        for(int i=0;i<3;i++){
            staff[i]=new Employee();
        }

        Scanner input=new Scanner(System.in);

        for(int i=0;i<3;i++){
            System.out.println("Enter staff's name: ");
            staff[i].setName(input.next());
            System.out.println("Enter his/her salary per month:");
            staff[i].setSalary(input.nextDouble());
            System.out.println("Well done! Next staff coming!");
        }
        System.out.println("Now I will list information of all staffs!");
        for(int i=0;i<3;i++){
            System.out.println(staff[i].getName()+" : "+staff[i].getSalary());
        }
    }
}
class Employee{
    private String name;
    private double salary;

    public String getName(){
        return name;
    }
    public double getSalary(){
        return salary;
    }
    public void setName(String name){
        this.name=name;
    }
    public void setSalary(double salary){
        this.salary=salary;
    }
}
