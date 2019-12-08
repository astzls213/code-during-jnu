package chap11;

import java.math.BigInteger;
import java.time.Duration;
import java.time.Instant;
import java.util.Arrays;
import java.util.stream.Stream;

public class Question11 {
    public static void main(String[] args) {
        BigInteger[] ar=new BigInteger[40];
        for(int i=0;i!=ar.length;i++)
            ar[i]=BigInteger.valueOf(i+1);

        Stream<BigInteger> integers= Arrays.stream(ar,0,10);
        Instant start=Instant.now();
        integers.reduce(BigInteger.valueOf(1L), BigInteger::multiply);
        System.out.println("顺序流exec时间："+ Duration.between(start,Instant.now()));

        integers= Arrays.stream(ar,0,10);
        start=Instant.now();
        integers.parallel().reduce(BigInteger.valueOf(1L), BigInteger::multiply);
        System.out.println("并行流exec时间："+ Duration.between(start,Instant.now()));
    }
}
