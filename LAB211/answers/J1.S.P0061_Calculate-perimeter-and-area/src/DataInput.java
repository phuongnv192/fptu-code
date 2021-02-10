
import java.util.Scanner;
import shape.Circle;
import shape.Rectangle;
import shape.Triangle;

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

    private double inputDouble(double min, double max, String mode) {
        Scanner scanner = new Scanner(System.in);
        String raw;

        // loop until have number in range (min, max] were inputted
        while (true) {
            raw = scanner.nextLine().trim();
            if (!raw.isEmpty()) { // not empty string ~> check next condition
                try {
                    double number = Double.parseDouble(raw);
                    if (number > min) { // number > min ~> check next condition
                        if (number <= max) { // number <= max ~> finish
                            return number;
                        } else { // number <= 0 ~> display error & re-enter
                            System.out.print(mode + " must not more than " + max
                                    + ", enter again: ");
                        }
                    } else { // number > max ~> display error & re-enter
                        System.out.print(mode + " must more than " + min
                                + ", enter again: ");
                    }
                } catch (NumberFormatException e) {
                    System.out.print(mode + " must be a number, enter again: ");
                }
            } else { // empty string ~> display error & re-enter
                System.out.print(mode + " can not be empty, enter again: ");
            }
        }
    }

    public Rectangle inputRectangle() {
        DataInput in = new DataInput();
        System.out.println("=====Calculator Shape Program=====");
        double width, length;

        // loop until have valid sides of rectangle were inputted
        while (true) {
            System.out.println("Please input side width of Rectangle: ");
            width = in.inputDouble(0, Double.MAX_VALUE, "Side width");
            System.out.println("Please input length of Rectangle: ");
            length = in.inputDouble(0, Double.MAX_VALUE, "Length");
            if (width <= length) { // width <= length ~> valid ~> exit loop
                break;
            }
            System.out.println("Side width must less than length, enter again.");
        }
        return new Rectangle(width, length);
    }

    public Circle inputCircle() {
        DataInput in = new DataInput();
        System.out.println("Please input radius of Circle: ");
        double radius = in.inputDouble(0, Double.MAX_VALUE, "Radius");
        return new Circle(radius);
    }

    public Triangle inputTriangle() {
        DataInput in = new DataInput();
        double sideA, sideB, sideC;

        // loop until have valid sides of triangle were inputted
        while (true) {
            System.out.println("Please input side A of Triangle: ");
            sideA = in.inputDouble(0, Double.MAX_VALUE, "Side A");
            System.out.println("Please input side B of Triangle: ");
            sideB = in.inputDouble(0, Double.MAX_VALUE, "Side B");
            System.out.println("Please input side C of Triangle: ");
            sideC = in.inputDouble(0, Double.MAX_VALUE, "Side C");
            // triangle inequality: valid ~> exit loop
            if ((sideA + sideB) > sideC && (sideB + sideC) > sideA && (sideC + sideA) > sideB) {
                break;
            }
            System.out.println("You must input 3 side of a triangle, enter again.");
        }
        System.out.println();
        return new Triangle(sideA, sideB, sideC);
    }
}
