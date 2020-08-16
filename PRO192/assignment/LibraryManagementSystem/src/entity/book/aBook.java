/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package entity.book;

import datatypes.BookStatus;
import java.util.ArrayList;

/**
 *
 * @author phuong
 */
public class aBook {

    private Book book;
    private int bookNumber;
    private ArrayList<BookLending> lendings = new ArrayList<>();
    private BookStatus status;

    public aBook() {
    }

    public aBook(Book book, int bookNumber) {
        this.book = book;
        this.bookNumber = bookNumber;
        this.status = BookStatus.AVAILABLE;
    }

    public aBook(Book book, int bookNumber, BookStatus status) {
        this.book = book;
        this.bookNumber = bookNumber;
        this.status = status;
    }

    public Book getBook() {
        return book;
    }

    public void setBook(Book book) {
        this.book = book;
    }

    public int getBookNumber() {
        return bookNumber;
    }

    public void setBookNumber(int bookNumber) {
        this.bookNumber = bookNumber;
    }

    public ArrayList<BookLending> getLendings() {
        return lendings;
    }

    public void setLendings(ArrayList<BookLending> lendings) {
        this.lendings = lendings;
    }

    public BookStatus getStatus() {
        return status;
    }

    public void setStatus(BookStatus status) {
        this.status = status;
    }

    @Override
    public String toString() {
        return book.getId() + ";" + bookNumber + ";" + status.toString() + "\n";
    }
}
