package chap8;

public class Square implements Cloneable{
    private int length;
    public Square(int x){
        length=x;
    }
    public Square clone() throws CloneNotSupportedException{
        return (Square)super.clone();
    }
    @Override
    public boolean equals(Object otherObject){
        if(this==otherObject)
            return true;
        if(otherObject==null)
            return false;
        if(this.getClass()!=otherObject.getClass())
            return false;

        Square other=(Square)otherObject;
        return this.length==other.length;
    }
    @Override public String toString(){
        return "Square[length="+this.length+"]";
    }
}
