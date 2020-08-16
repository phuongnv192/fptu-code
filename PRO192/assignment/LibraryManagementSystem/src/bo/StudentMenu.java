/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package bo;

import dal.DBContext;
import datatypes.Account;
import datatypes.UserDetail;
import entity.user.Student;
import java.util.ArrayList;
import java.util.Scanner;

/**
 *
 * @author phuon
 */
public class StudentMenu {

    private DBContext db;
    private StudentBO studentBO;
    private Scanner scanner = new Scanner(System.in);

    public StudentMenu(DBContext db) {
        this.db = db;
        studentBO = new StudentBO(db);
    }

    public void loginMenu() {
        Boolean exit = false;
        while (!exit) {
            System.out.println("_____Student Login_____");
            System.out.println("1. Login to an existing account");
            System.out.println("2. Register a new account");
            System.out.println("3. Reset password");
            System.out.println("0. Back");
            System.out.print("Your choice: ");
            String choice = scanner.nextLine();
            switch (choice) {
                case "1": {
                    login();
                    break;
                }
                case "2": {
                    register();
                    break;
                }
                case "3": {
                    resetPassword();
                    break;
                }
                case "0": {
                    exit = true;
                    break;
                }
                default: {
                    System.err.println("Enter again.");
                }
            }
            System.out.println();
        }
    }


    private void login() {
        ArrayList<Student> students = db.getStudents();
        if (students.isEmpty()) {
            System.err.println("No account found, create a new one.");
        } else {
            int failCount = 0;
            Boolean valid = false;
            while (failCount < 3 && !valid) {
                System.out.print("Username: ");
                String username = scanner.nextLine().trim().toLowerCase();
                System.out.print("Password: ");
                String password = scanner.nextLine().trim();
                for (Student s : students) {
                    Account acc = s.getAccount();
                    if (acc.getUsername().equals(username) && acc.getPassword().equals(password)) {
                        valid = true;
                        studentBO.setStudent(s);
                        break;
                    }
                }
                if (!valid) {
                    System.err.println("Invalid account information.");
                    failCount++;
                }
            }
            if (!valid) {
                System.out.print("Reset password? y/n ");
                String choice = scanner.nextLine().toLowerCase();
                if (choice.equals("y")) {
                    resetPassword();
                }
            } else {
                switch (studentBO.getStudent().getStatus()) {
                    case ACTIVE: {
                        activeMenu();
                        break;
                    }
                    case WARNING: {
                        warningMenu();
                        break;
                    }
                    case BLACKLISTED: {
                        blacklistedMenu();
                        break;
                    }
                }
            }
        }
    }

    private void register() {
        System.out.print("Student ID: ");
        String lid = scanner.nextLine().toLowerCase();
        System.out.print("First name: ");
        String firstName = scanner.nextLine();
        System.out.print("Last name: ");
        String lastName = scanner.nextLine();
        String phoneNumber;
        do {
            System.out.print("Phone number: ");
            phoneNumber = scanner.nextLine();
            if (!isValidPhonenumber(phoneNumber)) {
                System.err.println("Invalid phone number.");
            }
        } while (!isValidPhonenumber(phoneNumber));
        String username = firstName;
        String[] last = lastName.split(" ");
        for (String string : last) {
            username += string.charAt(0);
        }
        username += lid;
        username = username.toLowerCase();
        System.out.println("Your username: " + username);
        String password;
        do {
            System.out.print("Password: ");
            password = scanner.nextLine().trim();
            if (password.isEmpty()) {
                System.err.println("Password can not e empty.");
            }
        } while (password.isEmpty());
        Account account = new Account(username, password);
        UserDetail userDetail = new UserDetail(lid, firstName, lastName, phoneNumber);
        Student student = new Student(account, userDetail);
        db.addStudent(student);
    }

    private void resetPassword() {
        System.out.print("Student id: ");
        String sid = scanner.nextLine();
        Student s = db.getStudent(sid);
        if (s != null) {
            s.resetPW();
            db.exportStudents();
        } else {
            System.err.println("Invalid id");
        }
    }

    private void activeMenu() {
        Boolean exit = false;
        while (!exit) {
            System.out.println("_____Student Menu_____");
            System.out.println("1. Show book catalogue");
            System.out.println("2. Display all books your are borrowing");
            System.out.println("3. Borrow a book");
            System.out.println("4. Return a book");
            System.out.println("5. Renew a book");
            System.out.println("0. Logout");
            System.out.print("Your choice: ");
            String choice = scanner.nextLine();
            switch (choice) {
                case "1": {
                    studentBO.showCatalogue();
                    break;
                }
                case "2": {
                    studentBO.displayBorrowing();
                    break;
                }
                case "3": {
                    studentBO.borrowBook();
                    break;
                }
                case "4": {
                    studentBO.returnBook();
                    break;
                }
                case "5": {
                    studentBO.renewBook();
                    break;
                }
                case "0": {
                    exit = true;
                    break;
                }
                default: {
                    System.err.println("Enter again.");
                }
            }
            System.out.println();
        }
    }

    private void warningMenu() {
        Boolean exit = false;
        while (!exit) {
            System.out.println("_____Student Menu_____");
            System.err.println("WARNING: You must pay fine for overdue/ lost books before borrow new book");
            System.out.println("   If you already finish pay fine, please login again).");
            System.out.println("1. Display all books your are borrowing");
            System.out.println("2. Return a book");
            System.out.println("3. Pay fine for lost books");
            System.out.println("0. Logout");
            System.out.print("Your choice: ");
            String choice = scanner.nextLine();
            switch (choice) {
                case "1": {
                    studentBO.displayBorrowing();
                    break;
                }
                case "2": {
                    studentBO.returnBook();
                    break;
                }
                case "3": {
                    studentBO.payFineLost();
                }
                case "0": {
                    exit = true;
                    break;
                }
                default: {
                    System.err.println("Enter again.");
                }
            }
            System.out.println();
        }
    }

    private void blacklistedMenu() {
        Boolean exit = false;
        while (!exit) {
            System.out.println("_____Student Menu_____");
            System.err.println("WARNING: You must pay fine for lost books before borrow new book");
            System.out.println("(If you already finish pay fine, please login again).");
            System.out.println("1. Pay fine for lost books");
            System.out.println("0. Logout");
            System.out.print("Your choice: ");
            String choice = scanner.nextLine();
            switch (choice) {
                case "1": {
                    studentBO.payFineLost();
                    break;
                }
                case "0": {
                    exit = true;
                    break;
                }
                default: {
                    System.err.println("Enter again.");
                }
            }
            System.out.println();
        }
    }

    private Boolean isValidPhonenumber(String phoneNumber) {
        if (phoneNumber.length() != 10 && !phoneNumber.startsWith("0")) {
            return false;
        } else {
            for (int i = 1; i < phoneNumber.length(); i++) {
                if (!Character.isDigit(phoneNumber.charAt(i))) {
                    return false;
                }
            }
            return true;
        }
    }
}
