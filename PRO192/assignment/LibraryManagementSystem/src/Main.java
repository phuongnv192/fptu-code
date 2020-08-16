
import bo.LibrarianMenu;
import bo.StudentMenu;
import dal.DBContext;
import java.util.Scanner;

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
/**
 *
 * @author phuong
 */
public class Main {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        DBContext db = new DBContext();
        StudentMenu studentMenu = new StudentMenu(db);
        LibrarianMenu librarianMenu = new LibrarianMenu(db);
        Boolean exit = false;
        String choice;
        while (!exit) {
            System.out.println("_____Library Management System_____\n");
            System.out.println("Account type:");
            System.out.println("1. Student");
            System.out.println("2. Librarian");
            System.out.println("0. Exit");
            System.out.print("Your choice: ");
            choice = scanner.nextLine();
            switch (choice) {
                case "1": {
                    studentMenu.loginMenu();
                    break;
                }
                case "2": {
                    librarianMenu.loginMenu();
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
}
