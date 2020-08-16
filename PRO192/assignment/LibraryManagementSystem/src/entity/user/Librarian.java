/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package entity.user;

import datatypes.User;
import datatypes.UserDetail;
import datatypes.Account;

/**
 *
 * @author phuong
 */
public class Librarian extends User {

    public Librarian(Account account, UserDetail userDetail) {
        super(account, userDetail);
    }

    @Override
    public String toString() {
        return super.toString() + "\n";
    }
}
