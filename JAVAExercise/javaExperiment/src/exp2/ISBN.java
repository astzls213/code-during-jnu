package exp2;

import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class ISBN {
    public static void main(String[] args) {
        String regex = "^?=[0-9]{13}$|(?=(?:[0-9]+[- ]){4})[- 0-9]{17}$";

        Pattern pattern = Pattern.compile(regex);
        String isbn="978-117-112-123-5";
        Matcher matcher = pattern.matcher(isbn);
        System.out.println(matcher.matches());
    }
}
