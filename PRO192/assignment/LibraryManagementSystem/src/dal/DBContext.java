/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package dal;

import datatypes.*;
import entity.*;
import entity.book.*;
import entity.user.*;
import java.io.BufferedReader;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.util.ArrayList;
import java.util.Calendar;
import java.util.Comparator;
import java.util.Date;
import java.util.TreeMap;
import java.util.logging.Level;
import java.util.logging.Logger;

/**
 *
 * @author phuong
 */
public class DBContext {

    private ArrayList<Book> books = new ArrayList<>(); // thong tin ve 1 dau sach
    private ArrayList<aBook> abooks = new ArrayList<>(); // thong tin ve 1 quyen sach
    private ArrayList<Student> students = new ArrayList<>();
    private ArrayList<Librarian> librarians = new ArrayList<>();
    private ArrayList<BookLending> booklendings = new ArrayList<>();
    private ArrayList<FineTransaction> transactions = new ArrayList<>();

    public DBContext() {
        importBook();
        importAbook();
        importStudent();
        importLibrarian();
        importBookLending();
        importFineTransaction();

    }

    public void addBook(Book book) {
        books.add(book);
        FileWriter fw = null;
        try {
            File f = new File("data\\book.dat");
            fw = new FileWriter(f, true);
            fw.write(book.toString());
        } catch (IOException ex) {
            Logger.getLogger(DBContext.class.getName()).log(Level.SEVERE, null, ex);
        } finally {
            try {
                fw.close();
            } catch (IOException ex) {
                Logger.getLogger(DBContext.class.getName()).log(Level.SEVERE, null, ex);
            }
        }
    }

    public void addAbook(aBook abook) {
        abooks.add(abook);
        FileWriter fw = null;
        try {
            File f = new File("data\\abook.dat");
            fw = new FileWriter(f, true);
            fw.write(abook.toString());
        } catch (IOException ex) {
            Logger.getLogger(DBContext.class.getName()).log(Level.SEVERE, null, ex);
        } finally {
            try {
                fw.close();
            } catch (IOException ex) {
                Logger.getLogger(DBContext.class.getName()).log(Level.SEVERE, null, ex);
            }
        }
    }

    public void addStudent(Student student) {
        students.add(student);
        FileWriter fw = null;
        try {
            File f = new File("data\\student.dat");
            fw = new FileWriter(f, true);
            fw.write(student.toString());
        } catch (IOException ex) {
            Logger.getLogger(DBContext.class.getName()).log(Level.SEVERE, null, ex);
        } finally {
            try {
                fw.close();
            } catch (IOException ex) {
                Logger.getLogger(DBContext.class.getName()).log(Level.SEVERE, null, ex);
            }
        }
    }

    public void addLibrarian(Librarian librarian) {
        librarians.add(librarian);
        FileWriter fw = null;
        try {
            File f = new File("data\\librarian.dat");
            fw = new FileWriter(f, true);
            fw.write(librarian.toString());
        } catch (IOException ex) {
            Logger.getLogger(DBContext.class.getName()).log(Level.SEVERE, null, ex);
        } finally {
            try {
                fw.close();
            } catch (IOException ex) {
                Logger.getLogger(DBContext.class.getName()).log(Level.SEVERE, null, ex);
            }
        }
    }

    public void addBookLending(BookLending bookLending) {
        booklendings.add(bookLending);
        Student s = bookLending.getStudent();
        aBook ab = bookLending.getAbook();
        s.getLendings().add(bookLending);
        ab.getLendings().add(bookLending);

        FileWriter fw = null;
        try {
            File f = new File("data\\booklending.dat");
            fw = new FileWriter(f, true);
            fw.write(bookLending.toString());
        } catch (IOException ex) {
            Logger.getLogger(DBContext.class.getName()).log(Level.SEVERE, null, ex);
        } finally {
            try {
                fw.close();
            } catch (IOException ex) {
                Logger.getLogger(DBContext.class.getName()).log(Level.SEVERE, null, ex);
            }
        }
    }

    public void addFineTransaction(FineTransaction fineTransaction) {
        transactions.add(fineTransaction);
        FileWriter fw = null;
        try {
            File f = new File("data\\transaction.dat");
            fw = new FileWriter(f, true);
            fw.write(fineTransaction.toString());
        } catch (IOException ex) {
            Logger.getLogger(DBContext.class.getName()).log(Level.SEVERE, null, ex);
        } finally {
            try {
                fw.close();
            } catch (IOException ex) {
                Logger.getLogger(DBContext.class.getName()).log(Level.SEVERE, null, ex);
            }
        }
    }

    private void importBook() {
        FileReader fr = null;
        try {
            File f = new File("data\\book.dat");
            fr = new FileReader(f);
            BufferedReader bfr = new BufferedReader(fr);
            String raw = bfr.readLine();
            while (raw != null && raw.trim().length() > 0) {
                String[] attributes = raw.split(";");
                String id = attributes[0];
                String name = attributes[1];
                String author = attributes[2];
                double price = Double.parseDouble(attributes[3]);
                Book b = new Book(id, name, author, price);
                books.add(b);
                raw = bfr.readLine();
            }
        } catch (FileNotFoundException ex) {
            Logger.getLogger(DBContext.class.getName()).log(Level.SEVERE, null, ex);
        } catch (IOException ex) {
            Logger.getLogger(DBContext.class.getName()).log(Level.SEVERE, null, ex);
        } finally {
            try {
                fr.close();
            } catch (IOException ex) {
                Logger.getLogger(DBContext.class.getName()).log(Level.SEVERE, null, ex);
            }
        }
    }

    private void importAbook() {
        FileReader fr = null;
        try {
            File f = new File("data\\abook.dat");
            fr = new FileReader(f);
            BufferedReader bfr = new BufferedReader(fr);
            String raw = bfr.readLine();
            while (raw != null && raw.trim().length() > 0) {
                String[] attributes = raw.split(";");
                String bid = attributes[0];
                int bookNumber = Integer.parseInt(attributes[1]);
                BookStatus status = BookStatus.valueOf(attributes[2]);
                Book b = getBook(bid);
                aBook ab = new aBook(b, bookNumber, status);
                abooks.add(ab);
                raw = bfr.readLine();
            }
        } catch (FileNotFoundException ex) {
            Logger.getLogger(DBContext.class.getName()).log(Level.SEVERE, null, ex);
        } catch (IOException ex) {
            Logger.getLogger(DBContext.class.getName()).log(Level.SEVERE, null, ex);
        } finally {
            try {
                fr.close();
            } catch (IOException ex) {
                Logger.getLogger(DBContext.class.getName()).log(Level.SEVERE, null, ex);
            }
        }
    }

    private void importStudent() {
        FileReader fr = null;
        try {
            File f = new File("data\\student.dat");
            fr = new FileReader(f);
            BufferedReader bfr = new BufferedReader(fr);
            String raw = bfr.readLine();
            while (raw != null && raw.trim().length() > 0) {
                String[] attributes = raw.split(";");
                String username = attributes[0];
                String password = attributes[1];
                String sid = attributes[2];
                String fname = attributes[3];
                String lname = attributes[4];
                String phone = attributes[5];
                StudentStatus status = StudentStatus.valueOf(attributes[6]);
                Account a = new Account(username, password);
                UserDetail ud = new UserDetail(sid, fname, lname, phone);
                Student s = new Student(a, ud, status);
                students.add(s);
                raw = bfr.readLine();
            }
        } catch (FileNotFoundException ex) {
            Logger.getLogger(DBContext.class.getName()).log(Level.SEVERE, null, ex);
        } catch (IOException ex) {
            Logger.getLogger(DBContext.class.getName()).log(Level.SEVERE, null, ex);
        } finally {
            try {
                fr.close();
            } catch (IOException ex) {
                Logger.getLogger(DBContext.class.getName()).log(Level.SEVERE, null, ex);
            }
        }
    }

    private void importLibrarian() {
        FileReader fr = null;
        try {
            File f = new File("data\\librarian.dat");
            fr = new FileReader(f);
            BufferedReader bfr = new BufferedReader(fr);
            String raw = bfr.readLine();
            while (raw != null && raw.trim().length() > 0) {
                String[] attributes = raw.split(";");
                String username = attributes[0];
                String password = attributes[1];
                String sid = attributes[2];
                String fname = attributes[3];
                String lname = attributes[4];
                String phone = attributes[5];
                Account a = new Account(username, password);
                UserDetail ud = new UserDetail(sid, fname, lname, phone);
                Librarian l = new Librarian(a, ud);
                librarians.add(l);
                raw = bfr.readLine();
            }
        } catch (FileNotFoundException ex) {
            Logger.getLogger(DBContext.class.getName()).log(Level.SEVERE, null, ex);
        } catch (IOException ex) {
            Logger.getLogger(DBContext.class.getName()).log(Level.SEVERE, null, ex);
        } finally {
            try {
                fr.close();
            } catch (IOException ex) {
                Logger.getLogger(DBContext.class.getName()).log(Level.SEVERE, null, ex);
            }
        }
    }

    private void importBookLending() {
        FileReader fr = null;
        try {
            File f = new File("data\\booklending.dat");
            fr = new FileReader(f);
            BufferedReader bfr = new BufferedReader(fr);
            String raw = bfr.readLine();
            while (raw != null && raw.trim().length() > 0) {
                String[] attributes = raw.split(";");
                String sid = attributes[0];
                String bid = attributes[1];
                int bookNumber = Integer.parseInt(attributes[2]);
                SimpleDateFormat sdf = new SimpleDateFormat("dd-MM-yyyy");
                Date borrowDate = sdf.parse(attributes[3]);
                Date dueDate = sdf.parse(attributes[4]);
                Date returnDate = null;
                if (!attributes[5].equals("NULL")) {
                    returnDate = sdf.parse(attributes[5]);
                }
                LendingStatus status;
                Student s = getStudent(sid);
                aBook ab = getAbook(bid, bookNumber);
                if (returnDate == null) {  // chua tra sach
                    long now = Calendar.getInstance().getTimeInMillis();
                    long diff = now - dueDate.getTime(); // miliseconds
                    int diffDays = (int) (diff / (24 * 60 * 60 * 1000));
                    if (diffDays > 0) {
                        if (diffDays <= 30) {
                            status = LendingStatus.OVERDUE;
                            ab.setStatus(BookStatus.BORROWED);
                        } else { // overdue > 30 days ~> lost
                            status = LendingStatus.LOST;
                            ab.setStatus(BookStatus.LOST);
                        }
                    } else {
                        status = LendingStatus.LENDING;
                        ab.setStatus(BookStatus.BORROWED);
                    }
                } else {
                    status = LendingStatus.FINISHED;
                    ab.setStatus(BookStatus.AVAILABLE);
                }
                BookLending bl = new BookLending(s, ab, borrowDate, dueDate, returnDate, status); // neu ko co returnDate ~> null
                booklendings.add(bl);
                s.getLendings().add(bl);
                ab.getLendings().add(bl);
                exportBookLendings();
                exportaBooks();
                raw = bfr.readLine();
            }
        } catch (FileNotFoundException ex) {
            Logger.getLogger(DBContext.class.getName()).log(Level.SEVERE, null, ex);
        } catch (IOException | ParseException ex) {
            Logger.getLogger(DBContext.class.getName()).log(Level.SEVERE, null, ex);
        } finally {
            try {
                fr.close();
            } catch (IOException ex) {
                Logger.getLogger(DBContext.class.getName()).log(Level.SEVERE, null, ex);
            }
        }
    }

    private void importFineTransaction() {
        FileReader fr = null;
        try {
            File f = new File("data\\transaction.dat");
            fr = new FileReader(f);
            BufferedReader bfr = new BufferedReader(fr);
            String raw = bfr.readLine();
            while (raw != null && raw.trim().length() > 0) {
                String[] attributes = raw.split(";");
                String sid = attributes[0];
                String bid = attributes[1];
                SimpleDateFormat sdf = new SimpleDateFormat("dd-MM-yyyy");
                Date borrowDate = sdf.parse(attributes[2]);
                double amount = Double.parseDouble(attributes[3]);
                Date date = sdf.parse(attributes[4]);
                BookLending lending = getBookLending(sid, bid, borrowDate);
                FineTransaction ftrs = new FineTransaction(lending, amount, date);
                transactions.add(ftrs);
                lending.getFines().add(ftrs);
                raw = bfr.readLine();
            }
        } catch (FileNotFoundException ex) {
            Logger.getLogger(DBContext.class.getName()).log(Level.SEVERE, null, ex);
        } catch (IOException | ParseException ex) {
            Logger.getLogger(DBContext.class.getName()).log(Level.SEVERE, null, ex);
        } finally {
            try {
                fr.close();
            } catch (IOException ex) {
                Logger.getLogger(DBContext.class.getName()).log(Level.SEVERE, null, ex);
            }
        }
    }

    public Book getBook(String bid) {
        for (Book b : books) {
            if (b.getId().equalsIgnoreCase(bid)) {
                return b;
            }
        }
        return null;
    }

    public aBook getAbook(String bid, int bookNumber) {
        for (aBook ab : abooks) {
            String bookid = ab.getBook().getId();
            if (bookid.equalsIgnoreCase(bid) && ab.getBookNumber() == bookNumber) {
                return ab;
            }
        }
        return null;
    }

    public aBook getAvailableAbook(Book book) {
        for (aBook ab : abooks) {
            if (ab.getBook().equals(book) && ab.getStatus().equals(BookStatus.AVAILABLE)) {
                return ab;
            }
        }
        return null;
    }

    public Student getStudent(String sid) {
        for (Student s : students) {
            String id = s.getUserDetail().getId();
            if (id.equalsIgnoreCase(sid)) {
                return s;
            }
        }
        return null;
    }

    public Librarian getLibrarian(String lid) {
        for (Librarian l : librarians) {
            String id = l.getUserDetail().getId();
            if (id.equalsIgnoreCase(lid)) {
                return l;
            }
        }
        return null;
    }

    public BookLending getBookLending(String sid, String bid, Date borrowDate) {
        for (BookLending bl : booklendings) {
            String studentID = bl.getStudent().getUserDetail().getId();
            String bookID = bl.getAbook().getBook().getId();
            if (studentID.equalsIgnoreCase(sid) && bookID.equalsIgnoreCase(bid) && bl.getBorrowDate().equals(borrowDate)) {
                return bl;
            }
        }
        return null;
    }

    public TreeMap<Book, ArrayList<aBook>> getBooklist() {
        TreeMap<Book, ArrayList<aBook>> booklist = new TreeMap<>(new Comparator<Book>() {
            @Override
            public int compare(Book o1, Book o2) {
                return o1.getId().compareTo(o2.getId());
            }
        });
        for (Book b : getBooks()) {
            ArrayList<aBook> ablist = new ArrayList<>();
            for (aBook ab : getAbooks()) {
                if (ab.getBook().equals(b)) {
                    ablist.add(ab);
                }
            }
            booklist.put(b, ablist);
        }
        return booklist;
    }

    public ArrayList<Book> getBooks() {
        return books;
    }

    public void setBooks(ArrayList<Book> books) {
        this.books = books;
    }

    public ArrayList<aBook> getAbooks() {
        return abooks;
    }

    public void setAbooks(ArrayList<aBook> abooks) {
        this.abooks = abooks;
    }

    public ArrayList<Student> getStudents() {
        return students;
    }

    public void setStudents(ArrayList<Student> students) {
        this.students = students;
    }

    public ArrayList<Librarian> getLibrarians() {
        return librarians;
    }

    public void setLibrarians(ArrayList<Librarian> librarians) {
        this.librarians = librarians;
    }

    public ArrayList<BookLending> getBooklendings() {
        return booklendings;
    }

    public void setBooklendings(ArrayList<BookLending> booklendings) {
        this.booklendings = booklendings;
    }

    public ArrayList<FineTransaction> getTransactions() {
        return transactions;
    }

    public void setTransactions(ArrayList<FineTransaction> transactions) {
        this.transactions = transactions;
    }

    public void exportaBooks() {
        FileWriter fw = null;
        try {
            File f = new File("data\\abook.dat");
            fw = new FileWriter(f);
            for (aBook abook : abooks) {
                fw.write(abook.toString());
            }

        } catch (IOException ex) {
            Logger.getLogger(DBContext.class.getName()).log(Level.SEVERE, null, ex);
        } finally {
            try {
                fw.close();
            } catch (IOException ex) {
                Logger.getLogger(DBContext.class.getName()).log(Level.SEVERE, null, ex);
            }
        }
    }

    public void exportBookLendings() {
        FileWriter fw = null;
        try {
            File f = new File("data\\booklending.dat");
            fw = new FileWriter(f);
            for (BookLending bl : booklendings) {
                fw.write(bl.toString());
            }

        } catch (IOException ex) {
            Logger.getLogger(DBContext.class.getName()).log(Level.SEVERE, null, ex);
        } finally {
            try {
                fw.close();
            } catch (IOException ex) {
                Logger.getLogger(DBContext.class.getName()).log(Level.SEVERE, null, ex);
            }
        }
    }

    public void exportStudents() {
        FileWriter fw = null;
        try {
            File f = new File("data\\student.dat");
            fw = new FileWriter(f);
            for (Student student : students) {
                fw.write(student.toString());
            }

        } catch (IOException ex) {
            Logger.getLogger(DBContext.class.getName()).log(Level.SEVERE, null, ex);
        } finally {
            try {
                fw.close();
            } catch (IOException ex) {
                Logger.getLogger(DBContext.class.getName()).log(Level.SEVERE, null, ex);
            }
        }
    }

    public void exportLibrarians() {
        FileWriter fw = null;
        try {
            File f = new File("data\\librarian.dat");
            fw = new FileWriter(f);
            for (Librarian librarian : librarians) {
                fw.write(librarian.toString());
            }

        } catch (IOException ex) {
            Logger.getLogger(DBContext.class.getName()).log(Level.SEVERE, null, ex);
        } finally {
            try {
                fw.close();
            } catch (IOException ex) {
                Logger.getLogger(DBContext.class.getName()).log(Level.SEVERE, null, ex);
            }
        }
    }
}
