package exp5;

public class TicketsTest {
    public static void main(String[] args){
        Tickets tickets=new Tickets();
        Thread win1=new WinThread(tickets, "窗口1");
        Thread win2=new WinThread(tickets, "窗口2");
        win1.start();
        win2.start();
    }
}
