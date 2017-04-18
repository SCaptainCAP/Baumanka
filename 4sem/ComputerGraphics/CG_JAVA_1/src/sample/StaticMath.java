package sample;

import javafx.scene.canvas.GraphicsContext;

import java.awt.*;

/**
 * Created by serych on 11.04.17.
 */
public class StaticMath {

    public static Point heightCross(Triangle triangle) {
        Line ab = new Line(triangle.getA(), triangle.getB());
        Line bbh = new Line(ab, triangle.getC());
        Line bc = new Line(triangle.getB(), triangle.getC());
        Line aah = new Line(bc, triangle.getA());
        Point cross = aah.getCrossPoint(bbh);
        return cross;
    }

}
