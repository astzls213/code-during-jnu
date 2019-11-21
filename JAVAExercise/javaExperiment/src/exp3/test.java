package exp3;

public class test {
    public static void main(String[] args) {
        Calculator aCalculator=(a,b) ->( a*a)+(b*b);
        System.out.print(aCalculator.calculate(3,3));
    }
}
