package sample;

import javafx.application.Application;
import javafx.event.EventHandler;
import javafx.fxml.FXML;
import javafx.fxml.FXMLLoader;
import javafx.scene.Parent;
import javafx.scene.Scene;
import javafx.scene.canvas.Canvas;
import javafx.scene.input.DragEvent;
import javafx.stage.Stage;
import org.controlsfx.control.NotificationPane;

import java.nio.ByteBuffer;
import java.util.Locale;

public class Main extends Application {
    private static Stage stage;
    private static NotificationPane notificationPane;

    @Override
    public void start(Stage primaryStage) throws Exception{
        System.out.println("Starting...");
        Locale.setDefault(new Locale("en", "EN"));
        stage = primaryStage;
        stage.setResizable(false);
        Parent root = FXMLLoader.load(getClass().getResource("sample.fxml"));
        notificationPane = new NotificationPane(root);
        notificationPane.setShowFromTop(false);
        notificationPane.getStyleClass().add(NotificationPane.STYLE_CLASS_DARK);
        stage.setTitle("Мышь вне поля");
        stage.setScene(new Scene(notificationPane, 1000, 700));
        stage.show();
    }

    public static void main(String[] args) {
        launch(args);
    }

    public static Stage getStage() {
        return stage;
    }

    public static NotificationPane getNotificationPane() {
        return notificationPane;
    }
}
