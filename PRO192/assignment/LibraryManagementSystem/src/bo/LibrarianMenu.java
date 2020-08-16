/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package bo;

import dal.DBContext;
import datatypes.Account;
import datatypes.UserDetail;
import entity.user.Librarian;
import java.util.ArrayList;
import java.util.Scanner;

/**
 *
 * @author phuon
 */
public class LibrarianMenu {

    private DBContext db;
    private LibrarianBO librarianBO;
    private Scanner scanner = new Scanner(System.in);

    public LibrarianMenu(DBContext db) {
        this.db = db;
        librarianBO = new LibrarianBO(db);
    }

    public void loginMenu() {
        Boolean exit = false;
        System.out.println();
        while (!exit) {
            System.out.println("_____Librarian Login_____");
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
                    System.out.println("Enter again.");
                }
            }
            if (!exit) {
                System.out.println();
            }
        }
    }

    private void login() {
        System.out.println();
        ArrayList<Librarian> librarians = db.getLibrarians();
        if (librarians.isEmpty()) {
            System.out.println("No account found, create a new one.");
        } else {
            int failCount = 0;
            Boolean valid = false;
            while (failCount < 3 && !valid) {
                System.out.print("Username: ");
                String username = scanner.nextLine().trim().toLowerCase();
                System.out.print("Password: ");
                String password = scanner.nextLine().trim();
                for (Librarian l : librarians) {
                    Account acc = l.getAccount();
                    if (acc.getUsername().equals(username) && acc.getPassword().equals(password)) {
                        valid = true;
                        break;
                    }
                }
                if (!valid) {
                    System.out.println("Invalid account information.");
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
                mainMenu();
            }
        }
    }

    private void register() {
        System.out.print("\nLibrarian ID: ");
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
                System.out.println("Invalid phone number.");
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
                System.out.println("Password can not e empty.");
            }
        } while (password.isEmpty());
        Account account = new Account(username, password);
        UserDetail userDetail = new UserDetail(lid, firstName, lastName, phoneNumber);
        Librarian librarian = new Librarian(account, userDetail);
        db.addLibrarian(librarian);
    }

    private void resetPassword() {
        System.out.print("\nLibrarian id: ");
        String lid = scanner.nextLine();
        Librarian l = db.getLibrarian(lid);
        if (l != null) {
            l.resetPW();
            db.exportLibrarians();
        } else {
            System.out.println("Invalid id");
        }
    }

    private void mainMenu() {
        Boolean exit = false;
        System.out.println();
        while (!exit) {
            System.out.println("_____Librarian Menu_____");
            System.out.println("1. Add book to storage");
            System.out.println("2. Display book summary");
            System.out.println("0. Logout");
            System.out.print("Your choice: ");
            String choice = scanner.nextLine();
            switch (choice) {
                case "1": {
                    librarianBO.addaBook();
                    break;
                }
                case "2": {
                    librarianBO.displaySummary();
                    break;
                }
                case "0": {
                    exit = true;
                    break;
                }
                default: {
                    System.out.println("Enter again.");
                }
            }
            if (!exit) {
                System.out.println();
            }
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
