package exp3;

public class tlTest {
    public static void main(String[] args) {
        TrafficLight[] colors=TrafficLight.values();
        for (TrafficLight color:colors)
        System.out.println(color+" "+color.ordinal());
    }
}
