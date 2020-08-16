/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package bo;

/**
 *
 * @author phuon
 */
public interface MyStudentBO {
    
    public void showCatalogue();
    public void displayBorrowing();
    public void borrowBook();
    public void renewBook();
    public void returnBook();
    public void payFineLost();
}
