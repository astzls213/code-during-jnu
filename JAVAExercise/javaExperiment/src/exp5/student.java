package exp5;

import java.io.Serializable;
import java.time.LocalDate;

public class student implements Serializable {
    private String name;
    private LocalDate birth;
    public student(String name, int year, int month, int day){
        this.name=name;
        birth=LocalDate.of(year,month,day);
    }

    public String getName() {
        return name;
    }

    public LocalDate getBirth(){
        return birth;
    }
}
