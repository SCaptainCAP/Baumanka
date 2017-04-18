package sample;

import javafx.fxml.FXML;
import javafx.scene.canvas.Canvas;
import javafx.scene.canvas.GraphicsContext;
import javafx.scene.paint.Color;

import java.util.Stack;

public class Controller {
    @FXML
    private Canvas canvas;

    private GraphicsContext gc;

    private State nowState;
    private Stack<State> stack;


    private void updateCanvas() {
        gc.setFill(Color.WHITE);
        gc.fillRect(0, 0, canvas.getWidth(), canvas.getHeight());
        gc.setFill(Color.BLACK);

        double x = nowState.getX();
        double y = nowState.getY();
        double angle = nowState.getAngle();
        double zoom = nowState.getZoom();

        gc.translate(x, y);
        gc.rotate(10);
        gc.strokeOval(100 * zoom, 50 * zoom, 200, 100);
        gc.rotate(-10);
        gc.strokeOval(100 * zoom, 50 * zoom, 200, 100);
    }

    @FXML
    public void initialize() {
        System.out.println("Controller initializing...");
        gc = canvas.getGraphicsContext2D();
        stack = new Stack<>();
        nowState = new State(canvas.getWidth() / 2,canvas.getHeight() / 2,1,0);
        //nowState = new State(0,0,1,0);
        stack.push(nowState);
        updateCanvas();
    }
}
