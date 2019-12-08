package exp5;

public class Tickets {
    private int amount=100;
    public int getAmount(){
        return amount;
    }
    public synchronized void saleOne(){
        amount = amount -1;
    }
}
