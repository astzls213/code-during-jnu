package chap8;

import java.time.LocalDate;

public class Question6 {
    public static void main(String[] args) {
        //programmer's day is the 256th of a year.
        LocalDate day=LocalDate.of(2017,1,1);
        System.out.println("Programmer's day in 2017: "+day.plusDays(255));
    }
}
