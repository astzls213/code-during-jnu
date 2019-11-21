package exp3;

import java.time.DayOfWeek;
import java.time.LocalDate;

public class friday {
    public static void main(String[] args) {
        for(int i=2000;i<2100;i++)
        {
            LocalDate day=LocalDate.of(i,1,13);
            if(day.getDayOfWeek()== DayOfWeek.FRIDAY)
                System.out.println(day);
        }
    }
}
