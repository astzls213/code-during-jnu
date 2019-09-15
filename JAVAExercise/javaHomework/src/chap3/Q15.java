package chap3;
public class Q15 {
    public static void main(String[] args) {
        //Chicken and rabbit in the same cage.
        int chicken=0,rabbit=40;
        for(;2*chicken+4*rabbit!=100;chicken++,rabbit--){
        }
        System.out.println("Chicken: "+chicken+" Rabbit: "+rabbit);
    }
}
