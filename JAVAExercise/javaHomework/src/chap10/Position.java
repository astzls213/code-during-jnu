package chap10;


public class Position implements Comparable<Position> {
    private int x;
    private int y;
    public Position(int x,int y){
        this.x=x;
        this.y=y;
    }
    public int compareTo(Position other){
        return (int)(Math.sqrt(Math.pow(this.x,2)+Math.pow(this.y,2))-Math.sqrt(Math.pow(other.x,2)+Math.pow(other.y,2)));
    }
    public String toString(){
        return "("+this.x+","+this.y+")";
    }
}
