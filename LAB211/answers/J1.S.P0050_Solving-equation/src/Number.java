/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */


/**
 *
 * @author phuon
 */
public class Number {

    public Float checkin(String floatString) {
        try {
            Float number = Float.parseFloat(floatString);
            return number;
        } catch (NumberFormatException e) {
            return null;
        }
    }

    public boolean isOdd(float number) {
        return number % 2 != 0;
    }

    public boolean isPerfectSquare(float number) {
        return Math.sqrt(number) % 1 == 0;
    }
}
