/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package bo;

import dal.DBContext;
import entity.book.Book;
import entity.book.aBook;
import datatypes.BookStatus;
import java.util.ArrayList;
import java.util.Map;
import java.util.Scanner;
import java.util.TreeMap;

/**
 *
 * @author phuong
 */
public class LibrarianBO implements MyLibrarianBO {

    private DBContext db;
    private Scanner scanner = new Scanner(System.in);

    public LibrarianBO(DBContext db) {
        this.db = db;
    }

    @Override
    public void addaBook() {
        String id;
        String name;
        String author;
        double price;
        int quantity;
        System.out.println("_____Add new book_____");
        System.out.print("Book id: ");
        id = scanner.nextLine();
        System.out.print("Book name: ");
        name = scanner.nextLine();
        System.out.print("Author: ");
        author = scanner.nextLine();
        System.out.print("Book price: ");
        price = Double.parseDouble(scanner.nextLine());
        System.out.print("Quantity: ");
        quantity = Integer.parseInt(scanner.nextLine());
        Book book = new Book(id, name, author, price);
        db.addBook(book);
        for (int i = 0; i < quantity; i++) {
            aBook ab = new aBook(book, i + 1);
            db.addAbook(ab);
        }
        System.out.println("Add book successful.");
    }

    @Override
    public void displaySummary() {
        System.out.println("ID\tName\tPrice\tQuantity\tAvailable\tBorrowed\tLost");
        int availableSum = 0;
        int borrowedSum = 0;
        int lostSum = 0;
        TreeMap<Book, ArrayList<aBook>> booklist = db.getBooklist();
        for (Map.Entry<Book, ArrayList<aBook>> entry : booklist.entrySet()) {
            Book key = entry.getKey();
            ArrayList<aBook> value = entry.getValue();
            int available = 0;
            int borrowed = 0;
            int lost = 0;
            for (aBook ab : value) {
                BookStatus status = ab.getStatus();
                switch (status) {
                    case AVAILABLE:
                        available++;
                        break;
                    case BORROWED:
                        borrowed++;
                        break;
                    case LOST:
                        lost++;
                        break;
                }
            }
            System.out.println(key.getId()
                    + "\t" + key.getName()
                    + "\t" + key.getPrice()
                    + "\t" + (available + borrowed + lost)
                    + "\t" + available
                    + "\t" + borrowed
                    + "\t" + lost
            );
            availableSum += available;
            borrowedSum += borrowed;
            lostSum += lost;
        }
        int total = availableSum + borrowedSum + lostSum;
        System.out.println("\nTotal: " + total);
        System.out.println("   Available: " + availableSum);
        System.out.println("   Borrowed: " + borrowedSum);
        System.out.println("   Lost: " + lostSum);
    }
}
