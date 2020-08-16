/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package entity;

import datatypes.UserDetail;
import entity.book.Book;
import entity.book.BookLending;
import java.text.SimpleDateFormat;
import java.util.Date;

/**
 *
 * @author phuong
 */
public class FineTransaction {

    private BookLending lending;
    private double amount;
    private Date date;

    public FineTransaction(BookLending lending, double amount, Date date) {
        this.lending = lending;
        this.amount = amount;
        this.date = date;
    }

    public BookLending getLending() {
        return lending;
    }

    public void setLending(BookLending lending) {
        this.lending = lending;
    }

    public double getAmount() {
        return amount;
    }

    public void setAmount(double amount) {
        this.amount = amount;
    }

    public Date getDate() {
        return date;
    }

    public void setDate(Date date) {
        this.date = date;
    }
    
    @Override
    public String toString() {
        SimpleDateFormat f = new SimpleDateFormat("dd-MM-yyyy");
        UserDetail u = lending.getStudent().getUserDetail();
        Book b = lending.getAbook().getBook();
        return u.getId()
                + ";" + b.getId()
                + ";" + f.format(lending.getBorrowDate())
                + ";" + amount 
                + ";" + f.format(date) 
                + "\n";
    }
}
