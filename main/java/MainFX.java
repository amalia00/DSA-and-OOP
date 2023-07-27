import controller.ClinicController;
import javafx.application.Application;
import javafx.fxml.FXMLLoader;
import javafx.scene.Parent;
import javafx.scene.Scene;
import javafx.scene.control.Alert;
import javafx.stage.Stage;
import repository.AppointFileRepository;
import repository.AppointRepository;
import repository.PatientFileRepository;
import services.DentistServices;
import services.ServicesException;

import java.io.FileInputStream;
import java.io.IOException;
import java.util.Properties;

public class MainFX extends Application {
    @Override
    public void start(Stage primaryStage) throws Exception {
        try {
            FXMLLoader loader = new FXMLLoader(getClass().getResource("DentistClinic.fxml"));
            Parent root = loader.load();
            ClinicController ctrl = loader.getController();
            ctrl.setService(getService());
            Scene scene = new Scene(root);
            primaryStage.setScene(scene);
            primaryStage.setTitle("Dentist's List");
            primaryStage.show();
       }catch(Exception e){
            Alert alert=new Alert(Alert.AlertType.ERROR);
            alert.setTitle("Error ");
            alert.setContentText("Error while starting app "+e);
            alert.showAndWait();
        }
    }

    public static void main(String[] args) {
        launch(args);
    }

    static DentistServices getService() throws  ServicesException{
        try {
            Properties properties = new Properties();
            properties.load(new FileInputStream("DentistClinic.properties"));
            String requestFileName=properties.getProperty("AppointmentFile ");
            if (requestFileName==null){
                requestFileName="Appointments.txt";
                System.err.println("Appointment file not found. Using default "+requestFileName);
            }
            String formsFileName=properties.getProperty("PatientFile");
            if (formsFileName==null){
                formsFileName="Patient.txt";
                System.err.println("PatientForms file not found. Using default "+formsFileName);
            }

            PatientFileRepository crfRepo = new PatientFileRepository(formsFileName);
            AppointRepository crrRepo = new AppointFileRepository(requestFileName, crfRepo);
            return new DentistServices(crrRepo, crfRepo);
        }catch (IOException ex){
            throw new ServicesException("Error starting app "+ex);
        }
    }
}
