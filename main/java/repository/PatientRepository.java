package repository;

import dentist.Patient;

import java.util.List;

public interface PatientRepository extends Repository<Integer, Patient> {
    List<Patient> filterByName(String name);
    List<Patient> filterByNameAndAddress(String name, String address);
}
