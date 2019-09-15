package day2Java;
import java.util.*;
public class polymorphismTest {
    public static void main(String[] args) {
        Student[] students=new Student[3];
        Scanner scan=new Scanner(System.in);
        for(int i=0;i<students.length;i++){

            System.out.println("Please enter student's name:");
            students[i]=new Student(scan.next());
            System.out.println("Enter income, salary and state special allowance in order:");
            students[i].setIncomes(scan.nextDouble());
            students[i].setSalary(scan.nextDouble());
            students[i].setStateSpecialAllowance(scan.nextDouble());
        }
        System.out.println("Now i will give the tax for each student:");
        for(int i=0;i<students.length;i++)
        {
            System.out.println(students[i].name+" : "+totalTax(students[i]));
        }
    }
    private static double totalTax(Student student){
        double total=0;
        for(int i=0;i<3;i++)
            total+=student.getIncomes()[i].getTax();
        return total;
    }
}
class Person{
    protected String name;
    public Person(String name){//Overload test.
        this.name=name;
    }

    public Person(){
        this("Unnamed");
    }
    public void setName(String name){
        this.name=name;
    }
    public String getName(){
        return name;
    }
}
class Student extends Person{
    protected Income[] incomes=new Income[3];
    public Student(String name){
        super(name);
    }

    public Student(){
    }

    public void setIncomes(double income){
        incomes[0]=new Income(income);
    }
    public void setSalary(double income){
        incomes[1]=new Salary(income);
    }
    public void setStateSpecialAllowance(double income){
        incomes[2]=new StateSpecialAllowance(income);
    }
    public Income[] getIncomes(){
        return incomes;
    }
    public String getName(){
        return super.name;
    }
}
class Income{
    protected double income;
    public Income(double income){
        this.income=income;
    }
    public void setIncome(double income){
        this.income=income;
    }
    public double getTax(){
        return income*0.1;
    }
}
class Salary extends Income{
    public Salary(double income){
        super(income);
    }
    @Override
    public double getTax(){
        if(income<3500)
            return  0;
        else
            return (income-3500)*0.15;
    }
}
class StateSpecialAllowance extends Income{
    public StateSpecialAllowance(double income){
        super(income);
    }
    @Override
    public double getTax(){
        return 0;
    }
}

