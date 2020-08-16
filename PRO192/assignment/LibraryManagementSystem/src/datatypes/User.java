package datatypes;

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
import java.util.Scanner;

/**
 *
 * @author phuong
 */
public class User {

    private Account account;
    private UserDetail userDetail;

    public User(Account account, UserDetail userDetail) {
        this.account = account;
        this.userDetail = userDetail;
    }

    public Account getAccount() {
        return account;
    }

    public void setAccount(Account account) {
        this.account = account;
    }

    public UserDetail getUserDetail() {
        return userDetail;
    }

    public void setUserDetail(UserDetail userDetail) {
        this.userDetail = userDetail;
    }

    public void resetPW() {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter your phone number: ");
        String phone = scanner.nextLine().trim();

        if (userDetail.getPhoneNumber().equals(phone)) {
            System.out.println("Your username: " + account.getUsername());
            System.out.print("Enter new password: ");
            String newpw = scanner.nextLine().trim();
            account.setPassword(newpw);
        } else {
            System.err.println("Invalid phone number.");
        }
    }

    @Override
    public String toString() {
        return account.toString() + ";" + userDetail.toString();
    }
}
