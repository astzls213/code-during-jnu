package day1Java;

import java.time.LocalDate;
import java.util.Objects;

public class Employee{
    private String name="";
    private double salary=0;
    private LocalDate hireDay=null;

    public Employee(String name,double salary,int year,int month,int day){
        this.name=name;
        this.salary=salary;
        hireDay=LocalDate.of(year,month,day);
    }
    public Employee(){
        hireDay=LocalDate.of(1970,1,1);
    }
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

    @Override
    public boolean equals(Object otherObject) {
        if(this==otherObject)
            return true;
        if(otherObject==null)
            return false;
        if(getClass()!=otherObject.getClass())
            return false;
        Employee other=(Employee)otherObject;
        return Objects.equals(this.name,other.name)
                &&this.salary==other.salary
                &&Objects.equals(this.hireDay,other.hireDay);
    }
    @Override
    public String toString(){
        return getClass().getName()+"[name="+name+",salary:"+salary+",hireDay="+hireDay+"]";
    }
}
