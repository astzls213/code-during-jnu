package chap9;
import java.util.*;

public class Question7 {
    public static void main(String[] args) {
        Deck deck=new Deck();
        Card[] myCards=deck.getCards();
        System.out.print(myCards[4].toString());
    }
}
enum Suit{
    DIAMONDS,CLUBS,HEARTS,SPADES
}
enum Rank{
    DEUCE,THREE,FOUR,FIVE,SIX,SEVEN,EIGHT,NINE,TEN,JACK,QUEEN,KING,ACE
}
class Card{
    //Definition of card.
    private Suit attr1;
    private Rank attr2;
    public Card(Suit attr1,Rank attr2){
        this.attr1=attr1;
        this.attr2=attr2;
    }
    public Suit getAttr1(){
        return attr1;
    }
    public Rank getAttr2(){
        return attr2;
    }
    @Override
    public String toString(){
        return attr1.toString()+" "+attr2.toString();
    }
}
class Deck{
    //Definition of a piece of cards.
    private Card[] cards=new Card[52];
    public Deck(){
        int i=0;
        for(Suit suit:Suit.values()){
            for(Rank rank:Rank.values()){
                cards[i++]=new Card(suit,rank);
            }
        }
    }
    public Card[] getCards(){
        return cards;
    }
}
