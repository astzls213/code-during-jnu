package exp4;
import java.util.ArrayList;
import java.util.List;

public class Library<T>{
    private List<T> resources = new ArrayList<>();

    public void addMedia(T x){
        resources.add(x);
    }

    public T retrieveLast(){
        int size = resources.size();
        if(size>0){
            return resources.get(size-1);
        }
        return null;
    }
}
interface Media {

}
interface Book extends Media {}
interface Video extends Media {}
interface Newspaper extends Media {}

