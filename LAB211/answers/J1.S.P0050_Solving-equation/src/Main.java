/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author phuon
 */
public class Main {

    public static void main(String[] args) {
        EquationProgram eq = new EquationProgram();
        DataInput in = new DataInput();

        boolean isExit = false;
        // loop until user choose stop the program
        while (!isExit) {
            eq.displayMenu();
            int choice = in.inputChoice();
            switch (choice) {
                case 1: { // choose 1: calculate superlative equation
                    eq.calSuperlativeEq();
                    break;
                }
                case 2: { // choose 2: calculate quadratic equation
                    eq.calQuadraticEq();
                    break;
                }
                case 3: { // choose 3: exit program
                    isExit = true;
                    break;
                }
            }
        }
    }
}
