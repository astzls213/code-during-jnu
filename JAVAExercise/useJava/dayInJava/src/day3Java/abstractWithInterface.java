package day3Java;

import java.util.Scanner;

public class abstractWithInterface {
    public static void main(String[] args) {
        Zed zed=new Zed(1000);
        Fizz fizz=new Fizz(950);
        Scanner scan=new Scanner(System.in);
        for(int i=0;i<2;i++){
            zed.skills[i]=new Skill(i+1,100+i*50);
            fizz.skills[i]=new Skill(i+1,110+i*30);
        }
        while (!(zed.hp<=0)&&!(fizz.hp<=0)){
            int judge=0;
            System.out.println("now is zed time!");
            judge=scan.nextInt();
            switch (judge){
                case 1:
                    zed.attack(zed,1,fizz);
                    zed.AD();
                    break;
                case 2:
                    zed.attack(zed,2,fizz);
                    zed.AD();
                    break;
            }
            if(fizz.hp<=0)
                break;
            System.out.println("now is fizz time!");
            judge=scan.nextInt();
            switch (judge){
                case 1:
                    fizz.attack(fizz,1,zed);
                    fizz.AP();
                    break;
                case 2:
                    zed.attack(fizz,2,zed);
                    fizz.AP();
                    break;
            }
            if(zed.hp<=0)
                break;
        }
        if(zed.hp<=0) {
            System.out.println("zed, died!");
        }
        else
            System.out.println("fizz, out!");
    }
}
abstract class Hero{
    Skill[] skills=new Skill[2];
    public int hp;
    public void setHp(int hp){
        this.hp=hp;
    }
    public int getHp(){
        return this.hp;
    }
    public abstract void attack(Hero attack,int skill,Hero hero);
}
interface AD{
    void AD();
}
interface AP{
    void AP();
}
class Skill{
    private int num;
    private int damage;
    public Skill(int num,int damage){
        this.num=num;this.damage=damage;
    }
    public int getDamage(){
        return this.damage;
    }
    public int getNum(){
        return this.num;
    }
}
class Zed extends Hero implements AD{
    public final String name="Zed";
    public Zed(int hp){
        super.setHp(hp);
    }
    private final int adProtect=30;
    private final int apProtect=15;
    public void attack(Hero attack,int skill,Hero under_attack){
        under_attack.hp-=attack.skills[skill-1].getDamage();
    }

    public void AD(){
        System.out.println("AD ATTACK!");
    }
}
class Fizz extends Hero implements AP{
    public final String name="Fizz";

    private final int adProtect=28;
    private final int apProtect=20;
    public Fizz(int hp){
        super.setHp(hp);
    }
    public void attack(Hero attack,int skill,Hero under_attack){
        attack.hp-=attack.skills[skill-1].getDamage();
    }


    public void AP(){
        System.out.println("AP ATTACK!");
    }
}