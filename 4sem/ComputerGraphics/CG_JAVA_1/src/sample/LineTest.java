package sample;

import static org.junit.jupiter.api.Assertions.*;

/**
 * Created by serych on 12.04.17.
 */
class LineTest {
    @org.junit.jupiter.api.Test
    void getCrossPoint() {
        Line line1 = new Line(new Point(0,0), new Point(5,1));
        Line line4 = new Line(new Point(5,1), new Point(4,6));
        Point cross = line1.getCrossPoint(line4);
        assert cross.y == 1 && cross.x == 5;
    }

    @org.junit.jupiter.api.Test
    void getAngle() {
    }

    @org.junit.jupiter.api.Test
    void equals() {
        Line line1 = new Line(new Point(0,0), new Point(5,1));
        Line line2 = new Line(new Point(0,0), new Point(10,2));
        Line line3 = new Line(new Point(0,0), new Point(10,3));
        Line line4 = new Line(new Point(5,1), new Point(4,6));
        Line line5 = new Line(new Point(4,6), new Point(5,1));
        assert line1.equals(line2);
        assert !line1.equals(line3);
        assert line4.equals(line5);
    }

    @org.junit.jupiter.api.Test
    void lineConstructor1() {
        Line line = new Line(new Point(0,0), new Point(5,1));
        assert line.a == 1;
        assert line.b == -5;
        assert line.c == 0;
    }

    @org.junit.jupiter.api.Test
    void lineConstructor2() {
        Line line = new Line(new Point(5,1), new Point(0,0));
        assert line.a == 1;
        assert line.b == -5;
        assert line.c == 0;
    }

    @org.junit.jupiter.api.Test
    void lineConstructor3() {
        Line line = new Line(new Point(5,1), new Point(4,6));
//        assert line.a == 1;
//        assert line.b == -5;
//        assert line.c == 0;
    }

}