package chap10;

public class Question7 {
    public static void main(String[] args) {
        Position point1=new Position(4,3);
        Position point2=new Position(6,8);
        System.out.print("Distance:"+point1.toString()+" -> (0,0) subtract ");
        System.out.println(point2.toString()+" -> (0,0):");
        System.out.print(point1.compareTo(point2));
    }
}
