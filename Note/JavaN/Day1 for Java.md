# Day1 for Java

### 1.Hello World程序

今天尝试着去编写一个hello world程序，但它不是一个简单的hello world程序。

```java
package day1Java;
import java.util.Scanner;
public class HelloWorld {
    public static void main(String[] args) {
        System.out.println("Enter numbers of loop:");
        Scanner scan=new Scanner(System.in);
        for(int i=scan.nextInt();i>0;i--)
            System.out.println("hello,world");
    }
}
```

#### 从这段代码中，我总结了以下几点：

1.在我看来，java最大的特点就是：类+方法（即`class.method()`）。比如那个Scanner类，类是面向对象编程的重要特点。类是对现实物质中的抽象，将其本质抽象出来。Scanner类可以将它想象成一个吸收盒，而“System.in”是一个对象（对象就是类的具体化，准确来讲是实例化），它指明了Scanner要从System.in这种对象获取输入。nextInt()是Scanner的方法之一。所谓方法，就是该类的功能（个人理解）。<u>这样就可以调整这个“吸收盒”的“吸收模式”为“Int”。</u>

2.要想在一个类中使用另外包中的一个类，就要使用import关键字。可以想像一下，在一个叫Human的class中，Human需要编程，就必须import一个Computer类，因为这个Computer类在Shop包中。

3.谈谈`public static void main(String[] args)`main前面的修饰符的作用。

1⃣️public：它说明这个main方法是公开的，任何包中的类都可以访问它，这方便了JVM找到它。

2⃣️static：这和C语言的static很像，它说明main是静态的。即在HelloWorld类实例化之前，它已经被load进内存中。如果没有static，那么要想使用main方法，还必须对HelloWorld进行实例化，如：

`HelloWorld helloworld=new HelloWorld（）；`但是，main是Java程序的首入口，又怎能在此之前实例化呢？所以static是一定要的！

3⃣️void&String[] args和C语言一样，就不谈了。

### 2.bankAccount程序

一个简单的setStaffSalary的程序

```java
package day1Java;
import java.util.Scanner;
public class bankAccount {
    public static void main(String[] args) {
        Employee[] staff=new Employee[3];//I have 3 staffs.
        for(int i=0;i<3;i++){
            staff[i]=new Employee();
        }
        for(int i=0;i<3;i++){
            Scanner input=new Scanner(System.in);
            System.out.println("Enter staff's name: ");
            staff[i].setName(input.nextLine());
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
```

#### 我在写这个程序的过程中遇到的问题：

1.起初，我把`Scanner input=new Scanner(System.in);`是放在循环外面的。可是run的时候发现，当我输入第二位员工的名字的时候，input并没有堵塞，就是说程序跳过了名字的输入，直接到薪水的输入。很奇怪，我猜是因为缓冲区残留了一些输入在里头导致的。

baidu后，解决办法说是要每次循环后重新new Scanner才行。。

2.起初是没有6/7/8这三行代码的，然后run就error了。我发现`Employee[] staff=new Employee[3];`只是为staff分配3个Employee的数组，里头元素还未实例化= =，所以添加了6/7/8行处的代码。。

