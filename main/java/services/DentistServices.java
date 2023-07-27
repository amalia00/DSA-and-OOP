package services;

import dentist.Appointment;
import dentist.Patient;
import dentist.RequestStatus;
import repository.AppointRepository;
import repository.PatientRepository;
import repository.RepositoryException;

import java.util.List;

public class DentistServices {

    private AppointRepository appointRepository;

    private PatientRepository patientRepository;

    public DentistServices(AppointRepository appointRepository, PatientRepository patientRepository) {
        this.appointRepository = appointRepository;
        this.patientRepository = patientRepository;
    }

    public int addPatient(String Name, String Address, String PhoneNumber) throws ServicesException{
        try {
            Patient crr = new Patient(Name, Address, PhoneNumber);
            Patient patient = patientRepository.add(crr);
            return patient.getID();
        }catch (RepositoryException ex){
            throw new ServicesException("Error adding request"+ex);
        }
    }
    public List<Patient> getPatientsByName(String name){
        return patientRepository.filterByName(name);

    }


    public List<Appointment> getUnfinishedAppointmentsByDate(String date){
        return appointRepository.filterByDateAndStatus(date, RequestStatus.New);

    }

    public void addAppointment(String Hour, String Date,String DoctorName, String MedicalFile,Patient patient) throws ServicesException{
        try {

            Appointment appointment = new Appointment(Hour, Date, DoctorName ,MedicalFile, patient);
            appointment.setStatus(RequestStatus.Finished);
            patientRepository.update(patient, patient.getID());
            appointRepository.add(appointment);
        }catch (RepositoryException er){
            throw  new ServicesException("Error adding form"+er);
        }

    }
    public List<Appointment> getFinishedAppointments(){
        return appointRepository.filterdByStatus(RequestStatus.Finished);

    }

    public List<Appointment> getAppointmentsByStatus(RequestStatus status){
        return appointRepository.filterdByStatus(status);

    }

}
