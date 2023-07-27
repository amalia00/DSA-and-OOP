package repository;

import dentist.Appointment;
import dentist.RequestStatus;

import java.util.List;

public interface AppointRepository extends Repository<Integer,Appointment>{
    List<Appointment> findByDoctorName(String name);
    List<Appointment> findByDate (String date);
    List<Appointment> filterdByStatus(RequestStatus status);
    List<Appointment> filterByDateAndStatus(String date,RequestStatus status);




}
