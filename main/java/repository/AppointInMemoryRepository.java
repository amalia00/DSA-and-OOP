package repository;

import dentist.Appointment;
import dentist.RequestStatus;

import java.util.List;
import java.util.stream.Collectors;

public class AppointInMemoryRepository extends AbstractRepository< Integer,Appointment> implements AppointRepository{
    public AppointInMemoryRepository(){}

    @Override
    public List<Appointment> findByDoctorName(String name) {
        return getAll().stream().filter(x->x.getDoctorName().toLowerCase().contains(name.toLowerCase())).collect(Collectors.toList());
    }

    @Override
    public List<Appointment> findByDate(String date) {
        return getAll().stream().filter(x->x.getDate().toLowerCase().contains(date.toLowerCase())).collect(Collectors.toList());
    }

    @Override
    public List<Appointment> filterdByStatus(RequestStatus status) {
        return getAll().stream().filter(x->x.getStatus()==status).collect(Collectors.toList());
    }

    @Override
    public List<Appointment> filterByDateAndStatus(String model, RequestStatus status) {
        return getAll().stream().filter(x->x.getDate().toLowerCase().contains(model.toLowerCase()) && x.getStatus()==status).collect(Collectors.toList());
    }


}

