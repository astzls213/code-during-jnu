package day1Java;

public class Manager extends Employee{
    private double bonus;

    public Manager(String name, double salary, int year, int month, int day,double bonus) {
        super(name, salary, year, month, day);
        this.bonus=bonus;
    }
    @Override
    public boolean equals(Object otherObject){
        if(!super.equals(otherObject))return false;
        Manager other=(Manager)otherObject;
        return bonus==other.bonus;
    }
    @Override
    public String toString(){
        return super.toString()+"[Bonus="+bonus+"]";
    }
}