/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

import java.util.ArrayList;
import java.util.List;

/**
 *
 * @author phuon
 */
public class EquationCalculation {

    public List<Float> calculateEquation(float a, float b) {
        List<Float> result = new ArrayList<>();
        result.add(-b / a);
        return result;
    }

    public List<Float> calculateQuadraticEquation(float a, float b, float c) {
        List<Float> result = new ArrayList<>();
        float delta = b * b - (4 * a * c);
        if (delta < 0) { // delta < 0 ~> no solution
            return null;
        } else { // have solution
            float x1 = (float) ((-b + (Math.sqrt(delta))) / (2 * a));
            float x2 = (float) ((-b - (Math.sqrt(delta))) / (2 * a));
            result.add(x1);
            result.add(x2);
            return result;
        }
    }
}
