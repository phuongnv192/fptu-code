
import entity.Doctor;
import java.util.List;
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

    public int inputInt(String name, int min, int max, boolean isUpdate) {
        Scanner scanner = new Scanner(System.in);

        // loop until have valid choice were inputted
        while (true) {
            String raw = scanner.nextLine().trim();
            if (!raw.isEmpty()) { // not empty string ~> check next condition
                try {
                    int number = Integer.parseInt(raw);
                    if (number >= min) { // number >= min ~> check next condition
                        if (number <= max) { // number <= max ~> finish
                            return number;
                        } else { // number > max ~> display error & re-enter
                            System.out.print(name + " must not more than "
                                    + max + ", enter again: ");
                        }
                    } else { // number < min ~> display error & re-enter
                        System.out.print(name + " must more than equal "
                                + min + ", enter again: ");
                    }
                } catch (NumberFormatException e) {
                    System.out.print(name + " must be a number, enter again: ");
                }
            } else { // empty string
                if (isUpdate) { // update process: return error code
                    return min - 1;
                } else { // not in update process ~> display error & re-enter
                    System.out.print(name + " can not empty, enter again: ");
                }
            }
        }
    }

    public String inputNewID(List<Doctor> doctors, boolean isUpdate) {
        Scanner scanner = new Scanner(System.in);
        String code;

        // loop until have valid str were inputted
        while (true) {
            System.out.print("Enter Code: ");
            code = scanner.nextLine().trim();
            if (!code.isEmpty()) { // not empty string ~> check next condition
                if (getDoctorByID(doctors, code) == null) { // valid code ~> finish
                    return code;
                } else { // duplicated code
                    if (isUpdate) { // update process: accept duplicated code
                        return code;
                    }
                    System.out.println("The code \"" + code + "\""
                            + " is already existed, enter again.");
                }
            } else { // empty string ~> display error & re-enter
                if (isUpdate) { // update process: return null
                    return null;
                } else { // not in update process ~> display error & re-enter
                    System.out.println("Code can not be empty, enter again.");
                }
            }
        }
    }

    public String inputExistedID(List<Doctor> doctors) {
        Scanner scanner = new Scanner(System.in);
        String code;

        // loop until have valid str were inputted
        while (true) {
            System.out.print("Enter Code: ");
            code = scanner.nextLine().trim();
            if (!code.isEmpty()) { // not empty string ~> check next condition
                if (getDoctorByID(doctors, code) != null) { // valid code ~> finish
                    return code;
                } else { // can not code ~> display error & re-enter
                    System.out.println("The code \"" + code + "\""
                            + " is not existed, enter again.");
                }
            } else { // not in update process ~> display error & re-enter
                System.out.println("Code can not be empty, enter again.");
            }
        }
    }

    public String inputStr(String mode, boolean isUpdate) {
        Scanner scanner = new Scanner(System.in);
        String str;

        // loop until have valid str were inputted
        while (true) {
            System.out.print("Enter " + mode + ": ");
            str = scanner.nextLine().trim();
            if (!str.isEmpty()) { // not empty string ~> check next condition
                if (isValidName(str)) { // valid name ~> finish
                    return str;
                } else { // not valid name ~> display error & re-enter
                    System.out.println(mode + " can not contain special characters"
                            + ", enter again.");
                }
            } else { // empty string ~> display error & re-enter
                if (isUpdate) { // update process: return null
                    return null;
                } else { // not in update process ~> display error & re-enter
                    System.out.println(mode + " can not be empty, enter again.");
                }
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

    public Doctor getDoctorByID(List<Doctor> doctors, String id) {
        for (Doctor doctor : doctors) {
            if (doctor.getCode().equals(id)) {
                return doctor;
            }
        }
        return null;
    }
}
