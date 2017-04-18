package sample;

import java.nio.ByteBuffer;

/**
 * Created by serych on 11.04.17.
 */

// LINE AS A x + B y + C = 0
public class Line {

    enum LineType {Normal, Horizontal, Vertical, Invalid}

    public double a;
    public double b;
    public double c;
    private LineType type;

    /**
     * Line throw 2 points
     *
     * @param p1 first point
     * @param p2 second point
     */
    public Line(Point p1, Point p2) {
        double x1 = p1.x;
        double x2 = p2.x;
        double y1 = p1.y;
        double y2 = p2.y;
        if (p1.equals(p2)) {
            a = 0;
            b = 0;
            c = 0;
            type = LineType.Invalid;
            return;
        }
        a = y2 - y1;
        b = x1 - x2;
        c = -x1 * y2 + y1 * x2;
        if (a == 0) {
            type = LineType.Horizontal;
            b = 1;
            c = -y1;
            return;
        }
        if (b == 0) {
            type = LineType.Vertical;
            a = 1;
            c = -x1;
            return;
        }
        type = LineType.Normal;
        if (a < 0) {
            a *= -1;
            b *= -1;
            c *= -1;
        }
    }

    /**
     * Line, perpendicular to given and passes throw point
     *
     * @param line
     * @param p
     */
    public Line(Line line, Point p) {
        if (line.getType() == LineType.Vertical) {
            type = LineType.Horizontal;
            a = 0;
            b = 1;
            c = -p.y;
            return;
        }
        if (line.getType() == LineType.Horizontal) {
            type = LineType.Vertical;
            a = 1;
            b = 0;
            c = -p.x;
            return;
        }
        if (line.getType() == LineType.Normal) {
            type = LineType.Normal;
            a = -1 * line.b * line.b / line.a;
            b = line.b;
            c = -1 * a * p.x + -1 * b * p.y;
            if (a < 0) {
                a *= -1;
                b *= -1;
                c *= -1;
            }
            return;
        }
        type = LineType.Invalid;
        a = 0;
        b = 0;
        c = 0;
    }

    public Point getCrossPoint(Line line) {
        return getCrossPoint(line, this);
    }

    public static Point getCrossPoint(Line l1, Line l2) {
        double a1 = l1.a;
        double b1 = l1.b;
        double c1 = l1.c;
        double a2 = l2.a;
        double b2 = l2.b;
        double c2 = l2.c;
        if (l1.getType() == LineType.Vertical) {
            if (l2.getType() == LineType.Vertical) {
                return null;
            }
            if (l2.getType() == LineType.Horizontal) {
                return new Point(-c1 / a1, -c2 / b2);
            }
            if (l2.getType() == LineType.Normal) {
                double x = -c1 / a1;
                double y = (-a2 * x - c2) / b2;
                return new Point(x, y);
            }
        }
        if (l1.getType() == LineType.Horizontal) {
            if (l2.getType() == LineType.Vertical) {
                return new Point(-c2 / a2, -c1 / b1);
            }
            if (l2.getType() == LineType.Horizontal) {
                return null;
            }
            if (l2.getType() == LineType.Normal) {
                double y = -c1 / b1;
                double x = (-b2 * y - c2) / a2;
                return new Point(x, y);
            }
        }
        if (l1.getType() == LineType.Normal) {
            if (l2.getType() == LineType.Vertical) {
                double x = -c2 / a2;
                double y = (-a1 * x - c1) / b1;
                return new Point(x, y);
            }
            if (l2.getType() == LineType.Horizontal) {
                double y = - c2 / b2;
                double x = (-b1 * y - c1) / a1;
                return new Point(x, y);
            }
            if (l2.getType() == LineType.Normal) {
                double y = (c1 * a2 / a1 - c2) / (b2 - a2 * b1 / a1);
                double x = (-b1 * y - c1) / a1;
                return new Point(x, y);
            }
        }
        return null;
    }

    public double getAngle(Line line) {
        double a1 = line.a;
        double b1 = line.b;
        double a2 = this.a;
        double b2 = this.b;
        return Math.acos(Math.cos((a1 * a2 + b1 * b2) / Math.sqrt(a1 * a1 + b1 * b1) / Math.sqrt(a2 * a2 + b2 * b2)));
    }


    @Override
    public boolean equals(Object obj) {
        if (obj.getClass().equals(Line.class)) {
            Line line = (Line) obj;
            if (a == 0) {
                if (line.a == 0) {
                    if (b == 0)
                        return line.b == 0 && c == line.c;
                    double koef = line.b / b;
                    return (koef > 0) && (line.c / koef == c);
                }
                return false;
            }
            if (line.a == 0) {
                return false;
            }
            double koef = line.a / a;
            return b == line.b / koef && c == line.c / koef;
        }
        return false;
    }

    public LineType getType() {
        return type;
    }
}