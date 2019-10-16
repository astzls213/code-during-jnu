package chap4;
import java.util.Scanner;
public class Q5 {
    public static void main(String[] args) {
        double cp;
        Scanner input = new Scanner(System.in);
        Stock aStock = new Stock(input.nextLine(), input.nextLine());
        aStock.setPreviousPrice(input.nextDouble());
        aStock.setCurrentPrice(input.nextDouble());
        cp=aStock.getChangePercent();
        System.out.println("Change percent is "+String.format("%.2f",cp)+"%");
    }
}
class Stock{
    private String symbol;
    private String name;
    private double previousPrice;
    private double currentPrice;
    Stock(String symbol, String name){
        this.symbol=symbol;
        this.name=name;
    }
    void setPreviousPrice(double prePrice){
        this.previousPrice=prePrice;
    }
    void setCurrentPrice(double curPrice){
        this.currentPrice=curPrice;
    }
    private double getPreviousPrice(){
        return this.previousPrice;
    }
    private double getCurrentPrice(){
        return this.currentPrice;
    }
    double getChangePercent(){
        return Math.abs(getCurrentPrice()-getPreviousPrice())*100/getPreviousPrice();
    }
}