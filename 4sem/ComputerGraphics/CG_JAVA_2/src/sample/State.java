package sample;

/**
 * Created by serych on 17.04.17.
 */
public class State {
    private double x = 0;
    private double y = 0;
    private double zoom = 0;
    private double angle = 0;

    public State(double x, double y, double zoom, double angle) {
        this.x = x;
        this.y = y;
        this.zoom = zoom;
        this.angle = angle;
    }

    public double getX() {
        return x;
    }

    public double getY() {
        return y;
    }

    public double getZoom() {
        return zoom;
    }

    public double getAngle() {
        return angle;
    }
}
