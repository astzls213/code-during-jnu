package exp3;

@FunctionalInterface
public interface Calculator{
    double calculate(int a, int b);
    default int subtract(int a, int b){
        return a-b;
    }
    default int add(int a, int b){
        return a+b;
    }
}