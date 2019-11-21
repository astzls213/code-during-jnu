package exp3;

public class WildDuck extends animal implements Swimmable,Flyable {
    public static void main(String[] args) {
        WildDuck aDuck=new WildDuck();
        aDuck.eat();
        aDuck.fly();
        aDuck.swim();

        /*Swimmable swimDuck=aDuck;
        Flyable flyDuck=aDuck;
        animal unknown=aDuck;
        swimDuck.swim();
        swimDuck.eat();
        swimDuck.fly();
         */
    }
    public void swim(){
        System.out.println("Swimming");
    }
    public void fly(){
        System.out.println("Flying");
    }
    public void eat(){
        System.out.println("Eating");
    }
}
