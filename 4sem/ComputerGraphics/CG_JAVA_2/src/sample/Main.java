package sample;

import javafx.application.Application;
import javafx.fxml.FXMLLoader;
import javafx.scene.Parent;
import javafx.scene.Scene;
import javafx.stage.Stage;
import org.controlsfx.control.NotificationPane;

import java.util.Locale;

public class Main extends Application {

    private static Stage stage;
    private static NotificationPane notificationPane;

    @Override
    public void start(Stage primaryStage) throws Exception{
        Locale.setDefault(new Locale("en", "EN"));
        stage = primaryStage;
        stage.setResizable(false);
        Parent root = FXMLLoader.load(getClass().getResource("sample.fxml"));
        notificationPane = new NotificationPane(root);
        notificationPane.setShowFromTop(false);
        notificationPane.getStyleClass().add(NotificationPane.STYLE_CLASS_DARK);
        stage.setTitle("Птичка");
        stage.setScene(new Scene(notificationPane, 1200, 650));
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
