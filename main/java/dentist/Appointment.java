package dentist;
import java.io.Serializable;

public class Appointment implements Identifiable<Integer>,Serializable {
    private int ID;
    private String hour, date, doctorName, medicalFile;
    private RequestStatus status;
    private Patient patient;

    public Appointment() {
        ID = 0;
        this.hour = "";
        this.date = "";
        this.doctorName = "";
        status=RequestStatus.Unknown;
        this.medicalFile = "";
    }

    public Appointment(int ID, String hour, String date, String doctorName, String medicalFile, Patient patient) {
        this.ID = ID;
        this.hour = hour;
        this.date = date;
        this.doctorName = doctorName;
        this.medicalFile = medicalFile;
        status=RequestStatus.New;
        this.patient = patient;
    }
    public Appointment(String hour, String date, String doctorName, String medicalFile, Patient patient) {
        this.hour = hour;
        this.date = date;
        this.doctorName = doctorName;
        this.medicalFile = medicalFile;
        status=RequestStatus.New;
        this.patient = patient;
    }

    public Integer getID() {
        return ID;
    }

    public void setID(Integer Id) {
        this.ID = Id;
    }

    public String getHour() {
        return hour;
    }

    public void setHour(String hour) {
        this.hour = hour;
    }
    public String getDate(){
        return date;
    }

    public void setDate(String date){
        this.date=date;
    }
    public RequestStatus getStatus() {
        return status;
    }

    public void setStatus(RequestStatus status) {
        this.status = status;
    }
    public String getDoctorName(){
        return doctorName;
    }
    public void setDoctorName(String doctorName){
        this.doctorName=doctorName;
    }
    public String getMedicalFile(){
        return medicalFile;
    }
    public void setMedicalFile(String medicalFile){
        this.medicalFile=medicalFile;
    }
    public Patient getPatient(){
        return patient;
    }
    @Override
    public boolean equals(Object obj)
    {
        if(obj instanceof Appointment)
        {
            Appointment p = (Appointment) obj;
        }
        return false;
    }
    @Override
    public String toString() {
        return
                        "ID=" + ID +
                        ", hour='" + hour + '\'' +
                        ", date='" + date + '\'' +
                        ", doctorName='" + doctorName + '\'' +
                        ", medicalFile='" + medicalFile + '\''+
                        ", status='" + status + '\'' +
                        ", patient='" + patient + '\'';

    }
}

