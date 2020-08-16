/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package bo;

import dal.DBContext;
import datatypes.BookStatus;
import datatypes.LendingStatus;
import entity.FineTransaction;
import entity.book.Book;
import entity.book.BookLending;
import entity.book.aBook;
import entity.user.Student;
import java.text.SimpleDateFormat;
import java.util.ArrayList;
import java.util.Calendar;
import java.util.Date;
import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;
import java.util.TreeMap;

/**
 *
 * @author phuong
 */
public class StudentBO implements MyStudentBO {

    private Scanner scanner = new Scanner(System.in);
    private DBContext db;
    private Student student;
    private HashMap<LendingStatus, ArrayList<BookLending>> currentLendings;

    public StudentBO(DBContext db) {
        this.db = db;
    }

    public Student getStudent() {
        return student;
    }

    public void setStudent(Student student) {
        this.student = student;
        currentLendings = student.getCurrentLendings();
    }

    @Override
    public void showCatalogue() {
        System.out.println("Book ID\tBook Name\tAuthor\tPrice\tAvailable");
        TreeMap<Book, ArrayList<aBook>> booklist = db.getBooklist();
        for (Map.Entry<Book, ArrayList<aBook>> entry : booklist.entrySet()) {
            Book key = entry.getKey();
            ArrayList<aBook> value = entry.getValue();
            int availableCount = 0;
            for (aBook ab : value) {
                BookStatus status = ab.getStatus();
                if (status.equals(BookStatus.AVAILABLE)) {
                    availableCount++;
                }
            }
            String isAvailable;
            if (availableCount > 0) {
                isAvailable = "YES";
            } else {
                isAvailable = "NO";
            }
            System.out.println(key.getId()
                    + "\t" + key.getName()
                    + "\t" + key.getAuthor()
                    + "\t" + key.getPrice()
                    + "\t" + isAvailable);
        }
    }

    @Override
    public void displayBorrowing() {
        if (student.isNoBorrowing()) {
            System.err.println("You are borrowing no books.");
        } else {
            System.out.println("Book ID\tBook Name\tPrice\tBorrow date\tDue date\tStatus");
            SimpleDateFormat sdf = new SimpleDateFormat("dd-MM-yyyy");
            for (Map.Entry<LendingStatus, ArrayList<BookLending>> entry : currentLendings.entrySet()) {
                ArrayList<BookLending> value = entry.getValue();
                for (BookLending bl : value) {
                    Book b = bl.getAbook().getBook();
                    System.out.println(b.getId()
                            + "\t" + b.getName()
                            + "\t" + b.getPrice()
                            + "\t" + sdf.format(bl.getBorrowDate())
                            + "\t" + sdf.format(bl.getDueDate())
                            + "\t" + bl.getStatus());
                }
            }
        }
    }

    @Override
    public void borrowBook() {
        int totalBorrowing = currentLendings.get(LendingStatus.LENDING).size();
        if (totalBorrowing >= 10) {
            System.err.println("You can only borrow 10 books at the time.");
        } else {
            SimpleDateFormat sdf = new SimpleDateFormat("dd-MM-yyyy");
            Book book = inputBookID();
            if (student.isBookBorrowing(book)) {
                System.err.println("You already borrow this book.");
            } else {
                aBook ab = db.getAvailableAbook(book);
                if (ab != null) {
                    Date borrowDate = Calendar.getInstance().getTime();
                    BookLending bl = new BookLending(student, ab, borrowDate);
                    db.addBookLending(bl);
                    db.exportaBooks(); // FILE: change from available ~> borrowed
                    System.out.println();
                    System.out.println("Borrow successful book: ");
                    System.out.println("Book ID: " + book.getId());
                    System.out.println("Book name: " + book.getName());
                    System.out.println("Author: " + book.getAuthor());
                    System.out.println("Borrow date: " + sdf.format(borrowDate));
                    System.out.println("Due date: " + sdf.format(bl.getDueDate()));
                } else {
                    System.err.println("The are no book available with id " + book.getId() + ".");
                }
            }
        }
    }

    @Override
    public void renewBook() {
        SimpleDateFormat sdf = new SimpleDateFormat("dd-MM-yyyy");
        Book book = inputBookID();
        if (student.isNoBorrowing()) {
            System.err.println("You are borrowing no books.");
        } else {
            BookLending booklending = null;
            ArrayList<BookLending> borrowing = currentLendings.get(LendingStatus.LENDING);
            for (BookLending bl : borrowing) {
                if (bl.getAbook().getBook().equals(book)) {
                    booklending = bl;
                    break;
                }
            }
            if (booklending == null) {
                System.err.println("You are not borrow any book with id: " + book.getId() + ".");
            } else {
                Date borrowDate = booklending.getBorrowDate();
                Date dueDate = booklending.getDueDate();
                Date newDue = booklending.increase7days(dueDate);
                long diff = newDue.getTime() - borrowDate.getTime(); // miliseconds
                int dateDiff = (int) diff / (24 * 60 * 60 * 1000);
                if (dateDiff <= 28) {
                    booklending.setDueDate(newDue);
                    db.exportBookLendings(); // FILE: change dueDate
                    System.out.println("Renew successful.");
                } else {
                    System.err.println("You can't borrow a book more than 4 weeks.");
                }
            }
        }
    }

    @Override
    public void returnBook() {
        Book book = inputBookID();
        if (student.isNoBorrowing()) {
            System.err.println("You are borrowing no books.");
        } else {
            BookLending bookLending = null;
            for (Map.Entry<LendingStatus, ArrayList<BookLending>> entry : currentLendings.entrySet()) {
                LendingStatus key = entry.getKey();
                if (!key.equals(LendingStatus.LOST)) { // only check: LENDING, OVERDUE
                    ArrayList<BookLending> value = entry.getValue();
                    for (BookLending bl : value) {
                        if (bl.getAbook().getBook().equals(book)) {
                            bookLending = bl;
                            break;
                        }
                    }
                    if (bookLending != null) {
                        break;
                    }
                }
            }
            if (bookLending == null) {
                System.err.println("You are not borrow any book with id: " + book.getId() + ".");
            } else {
                if (bookLending.getStatus().equals(LendingStatus.LENDING)) {
                    Date returnDate = Calendar.getInstance().getTime();
                    bookLending.setReturnDate(returnDate);
                    db.exportBookLendings(); // FILE: add returnDate, change status ~> FINISH
                    db.exportaBooks(); // FILE: change status BORROWED ~> AVAILABLE
                    currentLendings.get(LendingStatus.LENDING).remove(bookLending);
                    System.out.println("Return book successful.");
                } else { // OVERDUE
                    payFineOverdue(bookLending);
                }
            }
        }
    }

    private void payFineOverdue(BookLending bl) {
        Date returnDate = Calendar.getInstance().getTime();
        SimpleDateFormat sdf = new SimpleDateFormat("dd-MM-yyyy");
        long diff = returnDate.getTime() - bl.getDueDate().getTime(); // miliseconds
        int dateDiff = (int) (diff / (24 * 60 * 60 * 1000));
        double amount = dateDiff * 5;
        System.out.println();
        System.out.println("Your are overdue " + dateDiff + " days.");
        System.out.println("Amount your must pay is: 5 * " + dateDiff + " = " + amount + " thousands VND");
        Boolean exit = false;
        while (!exit) {
            System.out.print("Confirm pay? y/n ");
            String choice = scanner.nextLine().toLowerCase();
            switch (choice) {
                case "y": {
                    bl.setReturnDate(returnDate);
                    FineTransaction transaction = new FineTransaction(bl, amount, returnDate);
                    db.addFineTransaction(transaction);
                    bl.getFines().add(transaction);
                    db.exportBookLendings(); // FILE: add returnDate, change status ~> FINISH
                    db.exportaBooks(); // FILE: change status BORROWED ~> AVAILABLE
                    currentLendings.get(LendingStatus.OVERDUE).remove(bl);
                    System.out.println("Return book successful.");
                    exit = true;
                    break;
                }
                case "n": {
                    exit = true;
                    break;
                }
                default: {
                    System.err.println("Enter again.");
                }
            }
        }
    }

    @Override
    public void payFineLost() {
        ArrayList<BookLending> lost = currentLendings.get(LendingStatus.LOST);
        System.out.println("Replacement fine = book price + overdue fine");
        System.out.println("   Overdue fine: 5000 VND/day (Maximum = book price)");
        System.out.println("Book ID\tBook name\tPrice\tBorrow date\tDue date\tDays overdue\tTotal fine");
        HashMap<BookLending, Double> finelist = new HashMap<>();
        Date now = Calendar.getInstance().getTime();
        SimpleDateFormat sdf = new SimpleDateFormat("dd-MM-yyyy");
        double totalFine = 0;
        for (BookLending bl : lost) {
            Book b = bl.getAbook().getBook();
            double bookPrice = b.getPrice();
            long diff = now.getTime() - bl.getDueDate().getTime(); // miliseconds
            int dateDiff = (int) (diff / (24 * 60 * 60 * 1000));
            double overDueFine = dateDiff * 5;
            if (overDueFine > bookPrice) {
                overDueFine = bookPrice;
            }
            double fine = bookPrice + overDueFine;
            finelist.put(bl, fine);
            System.out.println(b.getId()
                    + "\t" + b.getName()
                    + "\t" + bookPrice
                    + "\t" + sdf.format(bl.getBorrowDate())
                    + "\t" + sdf.format(bl.getDueDate())
                    + "\t" + dateDiff
                    + "\t" + fine);
            totalFine += fine;
        }
        System.out.println("Total amount: " + totalFine + " thousands VND.");
        Boolean exit = false;
        while (!exit) {
            System.out.print("Confirm pay? y/n ");
            switch (scanner.nextLine().toLowerCase()) {
                case "y": {
                    for (BookLending bl : lost) { // add fine transaction to file & database
                        double fine = finelist.get(bl);
                        FineTransaction transaction = new FineTransaction(bl, fine, now);
                        db.addFineTransaction(transaction);
                        bl.getFines().add(transaction);
                        currentLendings.get(LendingStatus.LOST).remove(bl);
                    }
                    System.out.println("Pay fine successful, please login again to borrow new book.");
                    break;
                }
                case "n": {
                    exit = true;
                    break;
                }
                default: {
                    System.err.println("Enter again.");
                }
            }
        }
    }

    private Book inputBookID() {
        Book book;
        do {
            System.out.print("Book ID: ");
            String bid = scanner.nextLine();
            book = db.getBook(bid);
            if (book != null) {
                return book;
            } else {
                System.err.println("Book id is not exists.");
            }
        } while (true);
    }
}
