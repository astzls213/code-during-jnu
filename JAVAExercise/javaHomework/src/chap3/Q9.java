package chap3;
import java.util.Scanner;
import java.util.Random;
public class Q9 {
    public static void main(String[] args) {
        Random random=new Random();
        Scanner scan=new Scanner(System.in);
        System.out.println("你出什么？（石头（2）剪子（1）布（0））： ");
        int playerJudge;
        int computerJudge;
        boolean judge=true;
        while(judge){
            playerJudge=scan.nextInt();
            computerJudge=random.nextInt(3);
            if(playerJudge==computerJudge)
            {
                System.out.println("平局，再来一次！");
                continue;
            }
            switch(playerJudge){
                case 0:
                    if(computerJudge==1)
                        System.out.println("计算机出的是：剪刀，你出布，你输了。");
                    else
                        System.out.println("计算机出的是：石头，你出布，你赢了。");
                    judge=false;
                    break;
                case 1:
                    if(computerJudge==0)
                        System.out.println("计算机出的是：布，你出剪刀，你赢了。");
                    else
                        System.out.println("计算机出的是：石头，你出剪刀，你输了。");
                    judge=false;
                    break;
                case 2:
                    if(computerJudge==0)
                        System.out.println("计算机出的是：布，你出石头，你输了。");
                    else
                        System.out.println("计算机出的是：剪刀，你出石头，你赢了。");
                    judge=false;
                    break;
                default:
                    System.out.println("Invalid Input, program terminated!");
                    judge=false;
            }
        }
    }
}
