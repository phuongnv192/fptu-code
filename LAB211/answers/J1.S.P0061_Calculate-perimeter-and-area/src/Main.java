
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
public class Main {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        DataInput in = new DataInput();

        Rectangle rec = in.inputRectangle();
        Circle cir = in.inputCircle();
        Triangle tri = in.inputTriangle();

        rec.printResult();
        cir.printResult();
        tri.printResult();
    }
}
