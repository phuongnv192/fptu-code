
import java.util.Scanner;

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
/**
 *
 * @author phuon
 */
public class DataInput {

    public String inputStr(String mode) {
        Scanner scanner = new Scanner(System.in);
        String str;

        // loop until have valid str were inputted
        while (true) {
            System.out.print(mode + ": ");
            str = scanner.nextLine().trim();
            if (!str.isEmpty()) { // not empty string ~> check next condition
                if (isValidName(str)) { // valid name ~> finish
                    return str;
                } else { // not valid name ~> display error & re-enter
                    System.out.println(mode + " can not contain special characters"
                            + ", enter again.");
                }
            } else { // empty string ~> display error & re-enter
                System.out.println(mode + " can not be empty, enter again.");
            }
        }
    }

    private boolean isValidName(String name) {
        // loop from begin to the first non-letter & non-digit char in name
        for (int i = 0; i < name.length(); i++) {
            char c = name.charAt(i);
            // non-letter & non-digit && no-space ~> not valid name
            if (!Character.isLetter(c) && !Character.isDigit(c) && c != ' ') {
                return false;
            }
        }
        return true;
    }

    public double inputMark(String subject) {
        Scanner scanner = new Scanner(System.in);
        String raw;

        // loop until have valid mark were inputted
        while (true) {
            System.out.print(subject + ": ");
            raw = scanner.nextLine().trim();
            if (!raw.isEmpty()) { // not empty string ~> check next condition
                try {
                    double mark = Double.parseDouble(raw);
                    if (mark <= 10) { // mark <= 10 ~> check next condition
                        if (mark >= 0) { // mark >= 0 ~> finish
                            return mark;
                        } else { // mark < 0 ~> display error & re-enter
                            System.out.println(subject + " is greater than equal zero");
                        }
                    } else { // mark > 10 ~> display error & re-enter
                        System.out.println(subject + " is less than equal ten");
                    }
                } catch (NumberFormatException e) {
                    System.out.println(subject + " is digit");
                }
            } else { // empty string ~> display error & re-enter
                System.out.println(subject + " can not be empty");
            }
        }
    }

    public boolean isYesOrNo() {
        Scanner scanner = new Scanner(System.in);
        String str;

        // loop until user choose 'Y' or 'N'
        while (true) {
            str = scanner.nextLine().trim();
            if (!str.isEmpty()) { // not empty string ~> check next condition
                if (str.equals("Y")) { // "Y" ~> return answer true
                    return true;
                } else if (str.equals("N")) { // "N" ~> return answer false
                    return false;
                } else { // not "Y" or "N" ~> display error & re-enter
                    System.out.print("Please only enter \"Y\" or \"N\", enter again: ");
                }
            } else { // empty string ~> display error & re-enter
                System.out.print("Choice can not be empty, enter again: ");
            }
        }
    }
}
