/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package entity.book;

import datatypes.BookStatus;
import datatypes.LendingStatus;
import entity.FineTransaction;
import entity.user.Student;
import java.text.SimpleDateFormat;
import java.util.ArrayList;
import java.util.Calendar;
import java.util.Date;

/**
 *
 * @author phuong
 */
public class BookLending {

    private Student student;
    private aBook abook;
    private Date borrowDate;
    private Date dueDate;
    private Date returnDate = null;
    private LendingStatus status;
    private ArrayList<FineTransaction> fines = new ArrayList<>();

    public BookLending() {
    }

    public BookLending(Student student, aBook abook, Date borrowDate) {
        this.student = student;
        this.abook = abook;
        this.borrowDate = borrowDate;
        this.abook.setStatus(BookStatus.BORROWED);
        dueDate = increase7days(borrowDate);
        status = LendingStatus.LENDING;
    }

    public BookLending(Student student, aBook abook, Date borrowDate, Date dueDate, Date returnDate, LendingStatus status) {
        this.student = student;
        this.abook = abook;
        this.borrowDate = borrowDate;
        this.dueDate = dueDate;
        this.returnDate = returnDate;
        this.status = status;
    }

    public Date increase7days(Date date) {
        Calendar c = Calendar.getInstance();
        c.setTime(date);
        c.add(Calendar.DATE, 7);
        return c.getTime();
    }

    public Student getStudent() {
        return student;
    }

    public void setStudent(Student student) {
        this.student = student;
    }

    public aBook getAbook() {
        return abook;
    }

    public void setAbook(aBook abook) {
        this.abook = abook;
    }

    public Date getBorrowDate() {
        return borrowDate;
    }

    public void setBorrowDate(Date borrowDate) {
        this.borrowDate = borrowDate;
    }

    public Date getDueDate() {
        return dueDate;
    }

    public void setDueDate(Date dueDate) {
        this.dueDate = dueDate;
    }

    public Date getReturnDate() {
        return returnDate;
    }

    public void setReturnDate(Date returnDate) {
        this.returnDate = returnDate;
        status = LendingStatus.FINISHED;
        abook.setStatus(BookStatus.AVAILABLE);
    }

    public LendingStatus getStatus() {
        return status;
    }

    public void setStatus(LendingStatus status) {
        this.status = status;
    }

    public ArrayList<FineTransaction> getFines() {
        return fines;
    }

    public void setFines(ArrayList<FineTransaction> fines) {
        this.fines = fines;
    }

    @Override
    public String toString() {
        SimpleDateFormat f = new SimpleDateFormat("dd-MM-yyyy");
        String rd;
        if (returnDate == null) {
            rd = "NULL";
        } else {
            rd = f.format(returnDate);
        }
        return student.getUserDetail().getId()
                + ";" + abook.getBook().getId()
                + ";" + abook.getBookNumber()
                + ";" + f.format(borrowDate)
                + ";" + f.format(dueDate)
                + ";" + rd
                + ";" + status
                + "\n";
    }
}
