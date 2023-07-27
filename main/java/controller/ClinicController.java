
package controller;

import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.scene.control.*;
import javafx.scene.text.Text;
import javafx.util.StringConverter;
import dentist.Appointment;
import dentist.Patient;
import dentist.RequestStatus;
import services.DentistServices;
import services.ServicesException;
import java.time.LocalDate;
import java.time.format.DateTimeFormatter;
import java.util.List;

public class ClinicController {
    public Button addButton;
    public Button AddAppointButton;
    public Button searchButton;
    public Button ClearFiledsButton;
    //for Patient
    @FXML
    private TextField Name, Address, Telephone, PhoneSearch, SearchName;
    @FXML
    private Text requestID;
//    @FXML
//    private TextArea requestName;
//    @FXML
//    private TextArea requestAdresss;
//    @FXML
//    private TextArea requestTelephone;


    //for Appointment
    @FXML
    private TextField MedicalFile, Hour, Date, Status,DoctorName,searchDate;

    private TableView<Patient> patientResults;


    @FXML
    private TableView<Appointment> appointmentResults;

    @FXML
    private ChoiceBox<RequestStatus> requestStatus;

    //connection to services
    private DentistServices dentistService;

    public ClinicController() {

    }

    public void setService(DentistServices service) {
        this.dentistService = service;
    }

    @FXML
    public void initialize() {
        StringConverter<LocalDate> converter = new StringConverter<>() {
            @Override
            public String toString(LocalDate date) {
                return (date != null) ? dateFormatter.format(date) : "";
            }

            @Override
            public LocalDate fromString(String string) {
                return (string != null && !string.isEmpty())
                        ? LocalDate.parse(string, dateFormatter)
                        : null;
            }
        };
        requestStatus.getItems().add(RequestStatus.New);
        requestStatus.getItems().add(RequestStatus.Finished);
        requestStatus.getItems().add(RequestStatus.Cancelled);
        //you may use the method values on an enum to obtain all the possible values
        //requestStatus.getItems().addAll(RequestStatus.values());
        requestStatus.getSelectionModel().selectFirst();

    }

    @FXML
    public void addPatientHandler(ActionEvent actionEvent) {
        String name = Name.getText();
        String address = Address.getText();
        String telephone = Telephone.getText();
        RequestStatus status = RequestStatus.New;
        if (checkString(name) && checkString(address) && checkString(telephone)) {
            try {
                int id = dentistService.addPatient(name, address, telephone);
                requestID.setText("Patient identification number is " + id);
                showNotification("Patient successfully added! ", Alert.AlertType.INFORMATION);
            } catch (ServicesException ex) {
                showNotification(ex.getMessage(), Alert.AlertType.ERROR);
            }
        } else
            showNotification("You have to fill in all the fields! ", Alert.AlertType.ERROR);
    }


    @FXML
    public void addAppointmentHandler(ActionEvent actionEvent) {
        //System.out.println("Add repaired button pressed ..."+repairDate.getValue().format(dateFormatter));
        int selectedPatient = patientResults.getSelectionModel().getSelectedIndex();
        if (selectedPatient < 0) {
            showNotification("You must select a Patient first! ", Alert.AlertType.ERROR);
            return;
        }
        //String serv = service.getText();
        String hour = Hour.getText();
        String date = Date.getText();
        String doctorName = DoctorName.getText();
        String medicalFile = MedicalFile.getText();
        if (checkString(hour) && checkString(date) && checkString(doctorName) && checkString(medicalFile)) {
            try {
                Patient patient = patientResults.getItems().get(selectedPatient);
                dentistService.addAppointment(hour, date, doctorName, medicalFile, patient);
                patientResults.getItems().remove(selectedPatient);
                clearAppointmentFields();
                showNotification("Appointment successfully added! ", Alert.AlertType.INFORMATION);
            } catch (ServicesException ex) {
                showNotification(ex.getMessage(), Alert.AlertType.ERROR);
            }
        }

    }

    private void clearAppointmentFields() {
        //services.setText("");
        Hour.setText("");
        MedicalFile.setText("");
        Date.setText("");
        DoctorName.setText("");
    }

    @FXML
    public void searchPatientHandler(ActionEvent actionEvent) {
        String searchName = SearchName.getText();
        if (!checkString(searchName)) {
            showNotification("You must introduce the Name! ", Alert.AlertType.ERROR);
            return;
        }
        List<Patient> results = dentistService.getPatientsByName(searchName);
        patientResults.getItems().clear();
        patientResults.getItems().addAll(results);

    }

    @FXML
    public void clearFieldsHandler(ActionEvent actionEvent) {
        Name.setText("");
        Address.setText("");
        Telephone.setText("");
        Hour.setText("");
        requestID.setText("");
    }

    private void showNotification(String message, Alert.AlertType type) {
        Alert alert = new Alert(type);
        alert.setTitle("Notification");
        alert.setContentText(message);
        alert.showAndWait();
    }

    private final DateTimeFormatter dateFormatter = DateTimeFormatter.ofPattern("dd-MM-yyyy");


    private boolean checkString(String s) {
        return s != null && !s.isEmpty();
    }

    @FXML
    public void addedAppointmentsHandler(ActionEvent actionEvent) {
        RequestStatus selected = requestStatus.getSelectionModel().getSelectedItem();
        List<Appointment> results = dentistService.getAppointmentsByStatus(selected);
        appointmentResults.getItems().clear();
        appointmentResults.getItems().addAll(results);
    }
}