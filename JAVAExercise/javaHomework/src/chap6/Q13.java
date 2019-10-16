package chap6;
import javax.management.remote.JMXServerErrorException;
import java.time.LocalDate;

public class Q13 {
    public static void main(String[] args) {
        LocalDate nowTime=LocalDate.now();
        int years=nowTime.getYear();
        int months=nowTime.getMonthValue();
        int days=nowTime.getDayOfMonth();
        String message=String.format("Now date: %d, %d, %d",years,months,days);
        System.out.println(message);
    }
}
