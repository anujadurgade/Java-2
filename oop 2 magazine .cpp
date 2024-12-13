// Base Class: Publication
class Publication {
    String title;
    double price;
    int copies;

    // Constructor
    public Publication(String title, double price, int copies) {
        this.title = title;
        this.price = price;
        this.copies = copies;
    }

    // Method to calculate sale of copies
    public double saleCopy(int copiesSold) {
        return copiesSold * price;
    }
}

// Subclass: Book
class Book extends Publication {
    String author;

    // Constructor
    public Book(String title, double price, int copies, String author) {
        super(title, price, copies);
        this.author = author;
    }

    // Method to order copies of books
    public void orderCopies(int orderCount) {
        this.copies += orderCount;
        System.out.println(orderCount + " copies of the book \"" + title + "\" ordered.");
    }
}

// Subclass: Magazine
class Magazine extends Publication {
    int orderQty;
    String currentIssue;

    // Constructor
    public Magazine(String title, double price, int copies, int orderQty, String currentIssue) {
        super(title, price, copies);
        this.orderQty = orderQty;
        this.currentIssue = currentIssue;
    }

    // Method to receive the issue of magazine
    public void receiveIssue(String issue) {
        this.currentIssue = issue;
        System.out.println("Magazine \"" + title + "\" updated to issue: " + currentIssue);
    }
}

public class PublicationTest {
    public static void main(String[] args) {
        // Create Book and Magazine objects
        Book book1 = new Book("Java Programming", 450, 100, "John Doe");
        Magazine mag1 = new Magazine("Tech World", 50, 200, 100, "December 2024");

        // Order copies of the book
        book1.orderCopies(20);

        // Receive new issue of the magazine
        mag1.receiveIssue("January 2025");

        // Calculate and display sales
        int booksSold = 30; // Assume 30 books sold
        int magazinesSold = 50; // Assume 50 magazines sold

        double totalSales = book1.saleCopy(booksSold) + mag1.saleCopy(magazinesSold);
        System.out.println("Total sales from books and magazines: " + totalSales);
    }
}
