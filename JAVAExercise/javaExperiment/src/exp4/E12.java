package exp4;

public class E12 {
    public static void main(String[] args) {
        Media media=new Media() {
            private int id=123;
        };
        Book book=new Book() {
            int id=12312;
            public int getId(){
                return id;
            }
        };
        Library<Media> library=new Library<>();
        library.addMedia(media);
        library.addMedia(book);
        System.out.println(library.retrieveLast());
    }
}
