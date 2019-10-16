package exp2;

public class Human {
    public static void main(String[] args) {
        People zls=new ChinaPeople();
        People trump=new AmericanPeople();
        People happyCat=new BeiJingPeople();
        zls.speakHello();
        trump.speakHello();
        happyCat.speakHello();
    }
}
class People{
    protected double height;
    protected double weight;
    public void speakHello(){
        System.out.println("asdasdahj");
    }
    public void averageHeight(){
        System.out.println("1213");
    }
    public void averageWeight(){
        System.out.println("121233");
    }
}
class ChinaPeople extends People{
    public void chinaGongFu(){
        System.out.println("wdnmd");
    }
    @Override
    public void speakHello(){
        System.out.println("ni hao.");
    }
    @Override
    public void averageHeight(){
        System.out.println("170");
    }
    @Override
    public void averageWeight(){
        System.out.println("60");
    }
}
class AmericanPeople extends People{
    public void americanBoxing(){
        System.out.println("shit");
    }
    @Override
    public void speakHello(){
        System.out.println("Hello.");
    }
    @Override
    public void averageHeight(){
        System.out.println("180");
    }
    @Override
    public void averageWeight(){
        System.out.println("80");
    }
}
class BeiJingPeople extends ChinaPeople{
    public void beijingOpera(){
        System.out.println("???");
    }
    @Override
    public void speakHello(){
        System.out.println("ni hao er.");
    }
    @Override
    public void averageHeight(){
        System.out.println("171");
    }
    @Override
    public void averageWeight(){
        System.out.println("61");
    }
}
