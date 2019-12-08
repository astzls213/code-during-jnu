package chap11;

public class Question1 {
    public static void main(String[] args) {
        Point<Integer> point1=new Point<>(1,2);
        Point<Double> point2=new Point<>(3.14,2.718);
        System.out.print("point1:"+point1.getX()+" "+point1.getY());
    }
}
class Point<T>{
    private T x;
    private T y;
    public Point(T x,T y){
        this.x=x;
        this.y=y;
    }
    public T getX(){
        return x;
    }
    public T getY(){
        return y;
    }
    public void translate(T newX,T newY){
        x=newX;
        y=newY;
    }
}
