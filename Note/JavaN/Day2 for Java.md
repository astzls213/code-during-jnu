# Day2 For Java

### 1.一个算不同收入的总Tax的程序

```java
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
    public static double totalTax(Student student){
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
```

#### 总结及遇到的问题：

1⃣️不能用for each循环对数组进行赋值或构造，否则会出现nullPointerException的报错。见下代码。

```
for(elementType element:Array)
    element=infomation;//infomations can be any kinds of input.
```

原因是foreach中的element变量是临时变量，在循环到时候只是将原数组中的元素值赋给element这一临时变量。而第二行语句只是修改element的值，而不是修改原有数组的值。

2⃣️Day1的Scanner只能在for循环声明的原因已查明：除了nextLine这个方法的所有next***()方法会在读入输入后留下一个回车符'\r'，而nextLine()会“吃”任意类型的空白符，包括'\r'。故会出现不堵塞的现象。

其实这和C语言中的scanf很像。比如：`scanf("%d",&element);`后，再调用`fgets(word,n,stdin)`，fgets会“吞掉”scanf读入element后留下的回车符。这同样导致fgets出现不堵塞现象。

3⃣️关于方法重载overload和方法覆写override:他们俩最大的区别就是方法签名是否相同，而方法签名又是什么呢？**官方定义，方法签名为方法名+形参类型。**（即：`public void name(int n)`,name和n的集合称为方法签名）**若相同，则覆写。反之，且返回类型，使用域相同，则重载。**而重载这个特性我觉得很棒，因为假如你只想多接受一个变量，然后输出另外格式的output，就没有必要有新创一个方法，只需overload就行了。最常用就是使用多构造器，以满足不同格式的初始化实例。

​	而覆写是一个非常强大的功能，多态真的惊艳到我了。它是基于继承这个特性而来的。什么意思呢？在我认为，至少我现在认为，由于继承而衍生出的各种子类，在现实生活中，它们都与其超类（或父类）也许有着相同类别的行为，但这行为的方式可以不同。

​	比如上面那个程序，父类：Income；子类：Salary，StateSpecialAllowance；子类与父类都有相同类别的行为，就是“产生税费”。但是，它们由于政策，对于税费有着不同的算法，那么，这就叫做行为的“方式”不同！而多态，就是程序在运行时会根据操作的实例属于哪种类，再对其作相应类别的行为方法。

​	比如`Income income=new Income(100);Income salary=new Salary(100);`

​	当getTax对income操作，那么就是使用income形态的getTax；而salary，getTax会使用salary形态的getTax进行相应操作。