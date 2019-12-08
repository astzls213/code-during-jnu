package exp5;

public class threadTest {
    public static void main(String[] args) {
        Runnable a=() -> {
            for(int i=0;i!=100;i++)
                System.out.print("a"+i+" ");
        };
        Runnable b=() ->{
            for(int i=0;i!=100;i++)
                System.out.print("b"+i+" ");
        };
        Runnable number=()->{
            for(int i=0;i!=100;i++){
                System.out.print(i);
                System.out.print(' ');
            }
        };
        Thread th1=new Thread(a);
        Thread th2=new Thread(b);
        Thread th3=new Thread(number);
        th1.start();
        th2.start();
        th3.start();
    }
}
