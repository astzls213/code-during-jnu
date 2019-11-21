package day5Java;

public class InnerClassTest {
    public static Pair minmax(int[] array){
        int min,max;
        {
            min=Integer.MAX_VALUE;
            max=Integer.MIN_VALUE;
        }
        for (int n:array){
            if(min>n)
                min=n;
            if(max<n)
                max=n;
        }
        return new Pair(min,max);
    }
    public static class Pair{
        private int first,second;
        public Pair(int f,int s){
            first=f;
            second=s;
        }

        public int getFirst() {
            return first;
        }
        public int getSecond(){
            return second;
        }
    }
}
