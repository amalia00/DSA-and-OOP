/*package streams;
import dentist.Patient;
import dentist.Appointment;
import repository.AppointRepository;
import java.util.ArrayList;
import java.util.List;

public class AppointmentStream {
    private final AppointRepository repo;

    public AppointmentStream(AppointRepository repo)
    {
        this.repo=repo;
    }
    public void add(Appointment p) {
        repo.add(p);
    }

    public List<Patient> patientsByDate(String date){
        List<Patient> patients = new ArrayList<>();
        repo.findall().forEach(s -> {
            if(s.getDate()==date)
                patients.add(s.getPatient());
        });
        return patients;
    }
    public List<String> appoForPatient(String Name){
        List<String> ap = new ArrayList<>();
        repo.findall().forEach(s -> {
            if(s.getPatient().getName()==Name)
                ap.add(s.getDate()+" "+s.getStatus());
        });
        return ap;
    }
    public List<String> problemsPat(String name) {
        List<String> ap = new ArrayList<>();
        repo.findall().forEach(s -> {
            if(s.getPatient().getName()==name)
                ap.add(s.getMedicalFile());
        });
        return ap;
    }


}*/
