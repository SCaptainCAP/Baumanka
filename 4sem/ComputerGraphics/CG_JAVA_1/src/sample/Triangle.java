package sample;

import java.util.Vector;

/**
 * Created by serych on 11.04.17.
 */
public class Triangle {
    private Point a;
    private Point b;
    private Point c;

    public Triangle(Point a, Point b, Point c) {
        this.a = a;
        this.b = b;
        this.c = c;
    }

    public Point getA() {
        return a;
    }

    public Point getB() {
        return b;
    }

    public Point getC() {
        return c;
    }

    public Line getAB() {
        return new Line(a,b);
    }

    public Line getBC() {
        return new Line(b,c);
    }

    public Line getCA() {
        return new Line(c,a);
    }

    public Vector<Point> getPoints() {
        Vector<Point> vector = new Vector<>();
        vector.add(a);
        vector.add(b);
        vector.add(c);
        return vector;
    }

}
