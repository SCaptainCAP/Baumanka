package sample;

import javafx.animation.PauseTransition;
import javafx.beans.value.ChangeListener;
import javafx.beans.value.ObservableValue;
import javafx.collections.FXCollections;
import javafx.collections.ListChangeListener;
import javafx.collections.ObservableList;
import javafx.event.EventHandler;
import javafx.fxml.FXML;
import javafx.scene.canvas.Canvas;
import javafx.scene.canvas.GraphicsContext;
import javafx.scene.control.*;
import javafx.scene.input.MouseEvent;
import javafx.scene.layout.AnchorPane;
import javafx.scene.layout.HBox;
import javafx.scene.layout.Pane;
import javafx.scene.layout.Priority;
import javafx.scene.paint.Color;
import javafx.util.Duration;

import java.text.DecimalFormat;
import java.text.NumberFormat;
import java.util.Locale;

import static sample.StaticMath.heightCross;

public class Controller {

    private static final int POINT_RADIUS = 3;
    private static final double ZOOM_TRIANGLE_KOEF = 1.5;

    private double zoom = 1;
    private double xcam = 0;
    private double ycam = 0;

    @FXML
    private Canvas canvas;
    @FXML
    private ListView<Point> listView;
    @FXML
    private SplitPane splitPane;
    @FXML
    private Button buttonAdd;
    @FXML
    private Button buttonCam;
    @FXML
    private Button buttonDeleteAll;
    @FXML
    private TextField xField;
    @FXML
    private TextField yField;
    @FXML
    private TextField xCam;
    @FXML
    private TextField yCam;
    @FXML
    private TextField zoomCam;
    @FXML
    private RadioButton radioAuto;
    @FXML
    private RadioButton radioManual;
    @FXML
    private Label aAns;
    @FXML
    private Label bAns;
    @FXML
    private Label cAns;
    @FXML
    private Label hAns;
    @FXML
    private Label angleAns;

    private GraphicsContext gc;
    private ObservableList<Point> points = FXCollections.observableArrayList();
    private ToggleGroup toggleGroup = new ToggleGroup();


    @FXML
    public void initialize() {
        System.out.println("Controller initializing...");
        gc = canvas.getGraphicsContext2D();
        radioAuto.setToggleGroup(toggleGroup);
        radioManual.setToggleGroup(toggleGroup);
        gc.setLineWidth(1);

        //anchorPane.getChildren().add(notificationPane);
        SplitPane.setResizableWithParent(splitPane, Boolean.FALSE);
        updateCanvas();

        toggleGroup.selectedToggleProperty().addListener((observableValue, toggle, t1) -> {
            if (radioAuto.isSelected()) {
                xCam.setDisable(true);
                yCam.setDisable(true);
                zoomCam.setDisable(true);
            } else {
                xCam.setDisable(false);
                yCam.setDisable(false);
                zoomCam.setDisable(false);
            }
        });

        buttonCam.setOnAction(actionEvent -> {
            if (radioManual.isSelected()) {
                double newXcam = 0, newYcam = 0, newZoom = 0;
                try {
                    newXcam = Double.parseDouble(xCam.getText());
                    newYcam = Double.parseDouble(yCam.getText());
                    newZoom = Double.parseDouble(zoomCam.getText());
                    zoom = newZoom;
                    xcam = newXcam;
                    ycam = newYcam;
                } catch (NumberFormatException ignored) {
                    Main.getNotificationPane().show("Камера задается тремя числами с плавающей запятой");
                    PauseTransition delay = new PauseTransition(Duration.seconds(3));
                    delay.setOnFinished(e -> Main.getNotificationPane().hide());
                    delay.play();
                }
            }
            xCam.setText(String.format("%1$.2f", xcam));
            yCam.setText(String.format("%1$.2f", ycam));
            zoomCam.setText(String.format("%1$.2f", zoom));
            updateCanvas();
        });
        canvas.setOnMouseMoved(mouseEvent -> {
            Point point = pointFromMouseEvent(mouseEvent);
            Main.getStage().setTitle("X: " +
                    String.format("%1$ 8.2f", point.x) +
                    "; Y: " +
                    String.format("%1$ 8.2f", point.y));

            //Main.getStage().setTitle("X: " + point.x + ", Y: " + point.y);
        });
        canvas.setOnMouseExited(mouseEvent -> {
            Main.getStage().setTitle("Мышь вне поля");
        });
        canvas.setOnMouseClicked(mouseEvent -> {
            Point point = pointFromMouseEvent(mouseEvent);
            addPoint(point);
            updateCanvas();
        });
        buttonAdd.setOnAction(actionEvent -> {
            double x = 0, y = 0;
            try {
                x = Double.parseDouble(xField.getText());
                y = Double.parseDouble(yField.getText());
            } catch (NumberFormatException ignored) {
                xField.setText("");
                yField.setText("");
                Main.getNotificationPane().show("Точка задается двумя числами с плавающей запятой");
                PauseTransition delay = new PauseTransition(Duration.seconds(3));
                delay.setOnFinished(e -> Main.getNotificationPane().hide());
                delay.play();
                return;
            }
            xField.setText("");
            yField.setText("");
            Point point = new Point(x, y);
            addPoint(point);
            updateCanvas();
        });
        buttonDeleteAll.setOnMouseClicked(mouseEvent -> {
            while (points.size() > 0) {
                points.remove(0);
            }
            updateCanvas();
        });
        listView.setCellFactory(param -> new PointCell());
        listView.setItems(points);
        listView.getSelectionModel().selectedItemProperty().addListener((observableValue, point, t1) -> {
            Point selectedPoint = listView.getSelectionModel().getSelectedItem();
            updateCanvas();
            if (selectedPoint != null) {
                Point apoint = absolute(selectedPoint);
                gc.setFill(Color.GREEN);
                drawCircle(apoint, POINT_RADIUS * 2);
                gc.setFill(Color.BLACK);
            }
        });
    }

    private void addPoint(Point point) {
        if (points.contains(point)) {
            Main.getNotificationPane().show("Такая точка уже есть!");
            PauseTransition delay = new PauseTransition(Duration.seconds(3));
            delay.setOnFinished(e -> Main.getNotificationPane().hide());
            delay.play();
        } else {
            points.add(point);
        }
    }

    private Point pointFromMouseEvent(MouseEvent mouseEvent) {
        return new Point((mouseEvent.getX() - canvas.getWidth() / 2 + xcam) / zoom,
                (-mouseEvent.getY() + canvas.getHeight() / 2 + ycam) / zoom);
    }

    private Point absolute(Point point) {
        if (point == null)
            return null;
        return new Point(point.x * zoom + canvas.getWidth() / 2 - xcam,
                -point.y * zoom + canvas.getHeight() / 2 + ycam);
    }

    private boolean checkTriangle(Triangle t) {
        return !(new Line(t.getA(), t.getB()).equals(new Line(t.getB(), t.getC())));
    }

    private void updateCanvas() {
        gc.setFill(Color.WHITE);
        gc.fillRect(0, 0, canvas.getWidth(), canvas.getHeight());
        gc.setFill(Color.BLACK);

        Triangle answerTriangle = null;
        Point answerTriangleH = null;
        double minAngle = Math.PI * 2;

        if (points.size() >= 3) {
            for (int i = 0; i < points.size() - 2; i++) {
                for (int j = i + 1; j < points.size() - 1; j++) {
                    for (int k = j + 1; k < points.size(); k++) {
                        Point a = points.get(i);
                        Point b = points.get(j);
                        Point c = points.get(k);
                        Triangle triangle = new Triangle(a, b, c);
                        if (checkTriangle(triangle)) {
                            Point cross = heightCross(triangle);
                            if (cross != null) {
                                if (cross.x == 0 && cross.y == 0) {
                                    answerTriangle = triangle;
                                    answerTriangleH = cross;
                                    minAngle = 0;
                                }
                                else {
                                    double angle = Math.acos(cross.y / Math.sqrt(cross.x * cross.x + cross.y * cross.y));
                                    if (angle <= minAngle) {
                                        answerTriangle = triangle;
                                        answerTriangleH = cross;
                                        minAngle = angle;
                                    }
                                }
                            } else {
                                System.out.println("WTF condition. Please check code");
                            }
                        }
                    }
                }
            }
        }
        if (answerTriangle != null) {
            double minx = answerTriangleH.x;
            double miny = answerTriangleH.y;
            double maxx = minx;
            double maxy = miny;
            for (int i = 0; i < 3; i++) {
                double x = answerTriangle.getPoints().get(i).x;
                double y = answerTriangle.getPoints().get(i).y;
                if (y > maxy)
                    maxy = y;
                if (y < miny)
                    miny = y;
                if (x > maxx)
                    maxx = x;
                if (x < minx)
                    minx = x;
            }
            if (radioAuto.isSelected()) {
                zoom = 1 / Math.max((maxx - minx) / canvas.getHeight(), (maxy - miny) / canvas.getWidth()) / ZOOM_TRIANGLE_KOEF;
                xcam = (maxx + minx) / 2 * zoom;
                ycam = (maxy + miny) / 2 * zoom;
            }
        } else {
            if (radioAuto.isSelected()) {
                zoom = 1;
                xcam = 0;
                ycam = 0;
            }
        }
        xCam.setText(String.format("%1$.2f", xcam));
        yCam.setText(String.format("%1$.2f", ycam));
        zoomCam.setText(String.format("%1$.2f", zoom));
        Point zero = absolute(new Point(0, 0));
        gc.setLineWidth(3);
        gc.strokeLine(zero.x, -canvas.getHeight(), zero.x, canvas.getHeight());
        gc.strokeLine(-canvas.getWidth(), zero.y, canvas.getWidth(), zero.y);
        gc.setLineWidth(1);
        //gc.strokeLine();
        //gc.strokeLine(canvas.getWidth() / 2, 0, canvas.getWidth() / 2, canvas.getHeight());
        //gc.strokeLine(0, canvas.getHeight() / 2, canvas.getWidth(), canvas.getHeight() / 2);


        for (Point point : points) {
            Point apoint = absolute(point);
            drawCircle(apoint, POINT_RADIUS);
        }
        if (answerTriangle != null) {
            gc.setFill(Color.YELLOW);
            for (int i = 0; i < answerTriangle.getPoints().size(); i++) {
                Point apoint = absolute(answerTriangle.getPoints().get(i));
                Point apoint2 = absolute(answerTriangle.getPoints().get((i + 1) % 3));
                gc.strokeLine(apoint.x, apoint.y, apoint2.x, apoint2.y);
                gc.strokeLine(apoint.x, apoint.y, apoint2.x, apoint2.y);
            }
            Point ahh = absolute(new Line(answerTriangle.getA(), answerTriangleH).getCrossPoint(answerTriangle.getBC()));
            if (ahh == null) {
                Line ahhl = new Line(answerTriangle.getBC(), answerTriangle.getA());
                ahh = absolute(ahhl.getCrossPoint(answerTriangle.getBC()));
            }
            Point bhh = absolute(new Line(answerTriangle.getB(), answerTriangleH).getCrossPoint(answerTriangle.getCA()));
            if (bhh == null) {
                Line bhhl = new Line(answerTriangle.getCA(), answerTriangle.getB());
                bhh = absolute(bhhl.getCrossPoint(answerTriangle.getCA()));
            }
            Point chh = absolute(new Line(answerTriangle.getC(), answerTriangleH).getCrossPoint(answerTriangle.getAB()));
            if (chh == null) {
                Line chhl = new Line(answerTriangle.getAB(), answerTriangle.getC());
                chh = absolute(chhl.getCrossPoint(answerTriangle.getAB()));
            }
            gc.setStroke(Color.BLUEVIOLET);
            gc.strokeLine(absolute(answerTriangle.getC()).x, absolute(answerTriangle.getC()).y, chh.x, chh.y);
            gc.strokeLine(absolute(answerTriangle.getB()).x, absolute(answerTriangle.getB()).y, bhh.x, bhh.y);
            gc.strokeLine(absolute(answerTriangle.getA()).x, absolute(answerTriangle.getA()).y, ahh.x, ahh.y);
            gc.strokeLine(absolute(answerTriangle.getA()).x, absolute(answerTriangle.getA()).y, absolute(answerTriangleH).x, absolute(answerTriangleH).y);
            gc.strokeLine(absolute(answerTriangle.getC()).x, absolute(answerTriangle.getC()).y, absolute(answerTriangleH).x, absolute(answerTriangleH).y);
            gc.strokeLine(absolute(answerTriangle.getB()).x, absolute(answerTriangle.getB()).y, absolute(answerTriangleH).x, absolute(answerTriangleH).y);
            gc.setStroke(Color.BLACK);

            for (Point point : answerTriangle.getPoints()) {
                Point apoint = absolute(point);
                drawCircle(apoint, POINT_RADIUS * 2);
            }

            gc.setFill(Color.RED);
            drawCircle(absolute(answerTriangleH), POINT_RADIUS * 2);
            gc.setFill(Color.BLACK);


            aAns.setText("X: " +
                    String.format("%1$ 8.2f", answerTriangle.getPoints().get(0).x) +
                    "; Y: " +
                    String.format("%1$ 8.2f", answerTriangle.getPoints().get(0).y));
            bAns.setText("X: " +
                    String.format("%1$ 8.2f", answerTriangle.getPoints().get(1).x) +
                    "; Y: " +
                    String.format("%1$ 8.2f", answerTriangle.getPoints().get(1).y));
            cAns.setText("X: " +
                    String.format("%1$ 8.2f", answerTriangle.getPoints().get(2).x) +
                    "; Y: " +
                    String.format("%1$ 8.2f", answerTriangle.getPoints().get(2).y));
            hAns.setText("X: " +
                    String.format("%1$ 8.2f", answerTriangleH.x) +
                    "; Y: " +
                    String.format("%1$ 8.2f", answerTriangleH.y));
            angleAns.setText(String.format("%1$ 6.2f", minAngle / Math.PI * 180 ) + " градусов");
        }
        else {
            aAns.setText("Нет ответа");
            bAns.setText("Нет ответа");
            cAns.setText("Нет ответа");
            hAns.setText("Нет ответа");
            angleAns.setText("Нет ответа");
        }
    }

    private void drawCircle(Point point, int raduis) {
        gc.fillOval(point.x - raduis,
                point.y - raduis,
                raduis * 2, raduis * 2);
    }

    private class PointCell extends ListCell<Point> {
        HBox hbox = new HBox();
        Label label = new Label("(empty)");
        Pane pane = new Pane();
        Button button = new Button("Удалить");
        Point point;

        PointCell() {
            super();
            hbox.getChildren().addAll(label, pane, button);
            HBox.setHgrow(pane, Priority.ALWAYS);
            button.setOnAction(actionEvent -> {
                points.remove(point);
                updateCanvas();
            });
        }

        @Override
        protected void updateItem(Point point, boolean empty) {
            super.updateItem(point, empty);
            setText(null);
            if (empty) {
                this.point = null;
                setGraphic(null);
            } else {
                this.point = point;
                if (point != null) {
                    label.setText("X: " +
                            String.format("%1$ 8.2f", point.x) +
                            "; Y: " +
                            String.format("%1$ 8.2f", point.y));
                } else {
                    label.setText("<null>");
                }
                setGraphic(hbox);
            }
        }
    }
}