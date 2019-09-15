package chap3;

public class Q18 {
    public static void main(String[] args) {
        //find all Complete numbers on range 1~1000
        System.out.println("All Complete numbers:");
        for(int num=1;num<1001;num++){
            int factors=num/2;
            int count=1,sum;
            for(sum=0;count<=factors;count++){
                if(num%count==0){
                    sum+=count;
                }
                if(sum==num&&count==factors){
                    System.out.println(num);
                    break;
                }
            }
        }
    }
}
