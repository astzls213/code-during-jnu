package exp5;

public class WinThread  extends Thread{
    private Tickets tickets=null;
    private int n=0;
    public WinThread(Tickets tickets, String name){
        super(name);
        this.tickets=tickets;
    }
    @Override
    public void run(){
        while (true){
            if(tickets.getAmount()>0){
                tickets.saleOne();
                n= n+1;
                System.out.println(getName()+":"+n);
                try{
                    Thread.sleep(50);
                }
                catch (InterruptedException e){

                }
            }else {
                System.out.println(getName()+"已无票");
                break;
            }
        }
    }
}
