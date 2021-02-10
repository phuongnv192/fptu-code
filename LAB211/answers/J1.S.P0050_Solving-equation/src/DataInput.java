/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

import java.util.Scanner;

/**
 *
 * @author phuon
 */
public class DataInput {

    public int inputChoice() {
        Scanner scanner = new Scanner(System.in);

        // loop until have valid choice were inputted
        while (true) {
            String raw = scanner.nextLine().trim();
            if (!raw.isEmpty()) { // not empty string ~> check next condition
                try {
                    int choice = Integer.parseInt(raw);
                    if (choice >= 1 && choice <= 3) { // 3 >= choice >= 1 ~> finish
                        return choice;
                    } else { // not in [1,3]  ~> display error & re-enter
                        System.out.print("Choice must in range "
                                + "[1-3], enter again: ");
                    }
                } catch (NumberFormatException e) {
                    System.out.print("Choice must be a number, enter again: ");
                }
            } else { // empty string ~> display error & re-enter
                System.out.print("Choice can not empty, enter again: ");
            }
        }
    }

    public float inputFloat(String name, boolean equalZero) {
        Scanner scanner = new Scanner(System.in);
        Number num = new Number();

        System.out.print("Enter " + name + ": ");
        // loop until have valid float number were inputted
        while (true) {
            String raw = scanner.nextLine().trim();
            if (!raw.isEmpty()) { // not empty string ~> check next condition
                Float number = num.checkin(raw);
                if (number != null) { // not null ~> check next condition
                    // condition != 0 & number == 0 ~> display error & re-enter
                    if (!equalZero && number == 0) {
                        System.out.print(name + " can not equal 0, enter again: ");
                    } else { // valid ~> finish
                        return number;
                    }
                } else { // null ~> not a number ~> display error & re-enter
                    System.out.print(name + " must be a numberical value, enter again: ");
                }
            } else { // empty string ~> display error & re-enter
                System.out.print(name + " can not be empty, enter again: ");
            }
        }
    }
}
