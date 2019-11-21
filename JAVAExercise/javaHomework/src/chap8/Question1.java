package chap8;

public class Question1 {
    public static void main(String[] args) throws CloneNotSupportedException {
        Square s1=new Square(3);
        Square s2=new Square(4);
        Square s3=new Square(3);
        System.out.println("toString testing:");
        System.out.println(s1.toString());
        System.out.println(s2.toString());
        System.out.println(s3.toString());
        System.out.println("clone testing:");
        Square cl=s1.clone();
        System.out.println(cl.toString());
        System.out.println(cl.equals(s1));
        System.out.println("equals testing:");
        if(s1.equals(s2)){
            System.out.println("s1 and s2 are the same square!");
        }
        if(s1.equals(s3)){
            System.out.println("s1 and s3 are the same square!");
        }
    }
}
