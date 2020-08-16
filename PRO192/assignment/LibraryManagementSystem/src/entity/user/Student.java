/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package entity.user;

import datatypes.User;
import datatypes.UserDetail;
import datatypes.Account;
import datatypes.LendingStatus;
import datatypes.StudentStatus;
import entity.book.Book;
import entity.book.BookLending;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.HashMap;

/**
 *
 * @author phuong
 */
public class Student extends User {

    private ArrayList<BookLending> lendings = new ArrayList<>();
    private StudentStatus status;

    public Student(Account account, UserDetail userDetail) {
        super(account, userDetail);
        updateStatus();
    }

    public Student(Account account, UserDetail userDetail, StudentStatus status) {
        super(account, userDetail);
        this.status = status;
        updateStatus();
    }

    public void updateStatus() {
        if (lendings.isEmpty()) {
            status = StudentStatus.ACTIVE;
        } else {
            HashMap<LendingStatus, ArrayList<BookLending>> current = getCurrentLendings();
            int borrowing = current.get(LendingStatus.LENDING).size();
            int overdue = current.get(LendingStatus.OVERDUE).size();
            int lost = current.get(LendingStatus.LOST).size();
            int total = borrowing + overdue + lost;
            if (borrowing == 0 && overdue == 0 && lost > 0) {
                status = StudentStatus.BLACKLISTED;
            } else if (overdue == 0 && lost == 0) {
                status = StudentStatus.ACTIVE;
            } else {
                status = StudentStatus.WARNING;
            }
        }
    }

    public HashMap<LendingStatus, ArrayList<BookLending>> getCurrentLendings() {
        HashMap<LendingStatus, ArrayList<BookLending>> current = new HashMap<>();
        ArrayList<BookLending> borrowing = new ArrayList<>();
        ArrayList<BookLending> overdue = new ArrayList<>();
        ArrayList<BookLending> lost = new ArrayList<>();
        if (lendings.isEmpty()) {
            return null;
        }
        for (BookLending lending : lendings) {
            switch (lending.getStatus()) {
                case LENDING:
                    borrowing.add(lending);
                    break;
                case OVERDUE:
                    overdue.add(lending);
                    break;
                case LOST:
                    if (lending.getFines().isEmpty()) {
                        lost.add(lending);
                    }
                    break;
            }
        }
        Collections.sort(borrowing, new Comparator<BookLending>() {
            @Override
            public int compare(BookLending lhs, BookLending rhs) {
                return lhs.getBorrowDate().compareTo(rhs.getBorrowDate());
            }
        });
        Collections.sort(overdue, new Comparator<BookLending>() {
            @Override
            public int compare(BookLending lhs, BookLending rhs) {
                return lhs.getBorrowDate().compareTo(rhs.getBorrowDate());
            }
        });
        Collections.sort(lost, new Comparator<BookLending>() {
            @Override
            public int compare(BookLending lhs, BookLending rhs) {
                return lhs.getBorrowDate().compareTo(rhs.getBorrowDate());
            }
        });
        current.put(LendingStatus.LENDING, borrowing);
        current.put(LendingStatus.OVERDUE, overdue);
        current.put(LendingStatus.LOST, lost);
        return current;
    }

    public Boolean isBookBorrowing(Book book) {
        if (!lendings.isEmpty()) {
            for (BookLending bl : lendings) {
                if (bl.getAbook().getBook().equals(book) && !bl.getStatus().equals(LendingStatus.FINISHED)) {
                    return true;
                }
            }
        }
        return false;
    }

    public Boolean isNoBorrowing() {
        HashMap<LendingStatus, ArrayList<BookLending>> current = getCurrentLendings();
        if (current == null) {
            return true;
        } else {
            int numLending = current.get(LendingStatus.LENDING).size()
                    + current.get(LendingStatus.OVERDUE).size()
                    + current.get(LendingStatus.LOST).size();
            return numLending == 0;
        }
    }

    public ArrayList<BookLending> getLendings() {
        return lendings;
    }

    public void setLendings(ArrayList<BookLending> lendings) {
        this.lendings = lendings;
    }

    public StudentStatus getStatus() {
        return status;
    }

    public void setStatus(StudentStatus status) {
        this.status = status;
    }

    @Override
    public String toString() {
        return super.toString() + ";" + status + "\n";
    }
}
