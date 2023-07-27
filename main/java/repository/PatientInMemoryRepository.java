package repository;

import dentist.Patient;

import java.util.List;
import java.util.stream.Collectors;

public class PatientInMemoryRepository extends AbstractRepository<Integer, Patient> implements PatientRepository{

    @Override
    public List<Patient> filterByName(String name) {
        return getAll().stream().filter(x->x.getName().toLowerCase().equals(name.toLowerCase())).collect(Collectors.toList());
    }

    @Override
    public List<Patient> filterByNameAndAddress(String name, String address) {
        return getAll().stream().filter(x->x.getName().toLowerCase().equals(name.toLowerCase()) && x.getAddress().equals(address)).collect(Collectors.toList());
    }
}
