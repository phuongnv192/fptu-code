/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

import java.text.DecimalFormat;
import java.util.ArrayList;
import java.util.List;

/**
 *
 * @author phuon
 */
public class EquationProgram {

    public void displayMenu() {
        System.out.println();
        System.out.println("========= Equation Program =========");
        System.out.println("1. Calculate Superlative Equation");
        System.out.println("2. Calculate Quadratic Equation");
        System.out.println("3. Exit");
        System.out.print("Your choice: ");
    }

    public void calSuperlativeEq() {
        DataInput in = new DataInput();
        EquationCalculation ec = new EquationCalculation();

        System.out.println("----- Calculate Equation -----");
        float a = in.inputFloat("A", false);
        float b = in.inputFloat("B", true);
        List<Float> result = ec.calculateEquation(a, b);
        System.out.format("Solution: %.3f\n", result.get(0));
        List<Float> list = new ArrayList<>();
        list.add(a);
        list.add(b);
        list.addAll(result);
        System.out.print("Number is Odd: ");
        displayNumberList(list, "odd");
        System.out.print("Number is Even: ");
        displayNumberList(list, "even");
        System.out.print("Number is Perfect Square: ");
        displayNumberList(list, "perfectSquare");
    }

    public void calQuadraticEq() {
        DataInput in = new DataInput();
        EquationCalculation ec = new EquationCalculation();

        System.out.println("----- Calculate Quadratic Equation -----");
        float a = in.inputFloat("A", false);
        float b = in.inputFloat("B", true);
        float c = in.inputFloat("C", true);
        List<Float> result = ec.calculateQuadraticEquation(a, b, c);
        List<Float> list = new ArrayList<>();
        list.add(a);
        list.add(b);
        list.add(c);
        if (result == null) { // null: no solution
            System.out.format("Solution: no solution\n");
        } else { // have solution
            System.out.format("Solution: x1 = %.3f and x2 = %.3f\n",
                    result.get(0), result.get(1));
            list.addAll(result);
        }
        System.out.print("Odd Number(s): ");
        displayNumberList(list, "odd");
        System.out.print("Number is Even: ");
        displayNumberList(list, "even");
        System.out.print("Number is Perfect Square: ");
        displayNumberList(list, "perfectSquare");
    }

    private void displayNumberList(List<Float> list, String type) {
        Number number = new Number();
        DecimalFormat df = new DecimalFormat("#0.0#");

        String result = "";
        // classify numbers by type
        switch (type) {
            case "odd": {
                int i = 0;
                // get each number in list and classify by odd numbers
                for (Float f : list) {
                    String numStr = "";
                    if (number.isOdd(f)) { // odd number ~> get this number
                        numStr = df.format(f);
                        i++;
                    }
                    if (!numStr.isEmpty()) { // not empty ~> already got a number
                        if (i == 1) { // 1st number ~> print with out ", "
                            result += numStr;
                        } else { // 2nd below ~> print with ", "
                            result += ", " + numStr;
                        }
                    }
                }
                break;
            }
            case "even": {
                int i = 0;
                // get each number in list and classify by even numbers
                for (Float f : list) {
                    String numStr = "";
                    if (!number.isOdd(f)) { // even ~> get this number
                        numStr = df.format(f);
                        i++;
                    }
                    if (!numStr.isEmpty()) { // not empty ~> already got a number
                        if (i == 1) { // 1st number ~> print with out ", "
                            result += numStr;
                        } else { // 2nd below ~> print with ", "
                            result += ", " + numStr;
                        }
                    }
                }
                break;
            }
            case "perfectSquare": {
                int i = 0;
                // get each number in list and classify by perfect numbers
                for (Float f : list) {
                    String numStr = "";
                    if (number.isPerfectSquare(f)) { // perfect square ~> get this number
                        numStr = df.format(f);
                        i++;
                    }
                    if (!numStr.isEmpty()) { // not empty ~> already got a number
                        if (i == 1) { // 1st number ~> print with out ", "
                            result += numStr;
                        } else { // 2nd below ~> print with ", "
                            result += ", " + numStr;
                        }
                    }
                }
                break;
            }
        }
        if (result.isEmpty()) { // result empty ~> empty list
            result = "there are no numbers";
        }
        System.out.println(result);
    }
}
