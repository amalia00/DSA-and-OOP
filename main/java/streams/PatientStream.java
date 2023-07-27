/*package streams;
import dentist.Patient;
import repository.PatientRepository;
import java.util.ArrayList;
import java.util.List;

public class PatientStream {
    private final PatientRepository repo;

    public PatientStream(PatientRepository repo)
    {
        this.repo=repo;
    }
    public void add(Patient p) {
        repo.add(p);
    }

    public List<String> allPatients(){
        List<String> patients= new ArrayList<>();
        repo.findall().forEach(s ->patients.add(s.getName()));
        return patients;
    }
    public List<String> thePhNr(String name){
        List<String> patients= new ArrayList<>();
        repo.findall().forEach(s ->{
            if(s.getName()== name)
                patients.add(s.getPhoneNumber());
        });
        return patients;
    }
    public List<Patient> patientbyName(String name){
        List<Patient> patients= new ArrayList<>();
        repo.findall().forEach(s ->{
            if(s.getName()== name)
                patients.add(s);
        });
        return patients;
    }



}*/
