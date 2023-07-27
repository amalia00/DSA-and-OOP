package repository;

import dentist.Appointment;
import dentist.Patient;
import dentist.RequestStatus;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;

public class AppointFileRepository extends AppointInMemoryRepository {
    private String filename;
    private PatientRepository appointRepository;
    private static int idGenerator=0;
    public AppointFileRepository(String filename, PatientRepository appointRepository) {
        this.filename = filename;
        this.appointRepository=appointRepository;
        readFromFile();
    }

    private void readFromFile(){
        try(BufferedReader br=new BufferedReader(new FileReader(filename))){
            String line=br.readLine();
            try{
                idGenerator=Integer.parseInt(line);
            }catch (NumberFormatException ex){
                System.err.println("Invalid Value for idGenerator, starting from 0");
            }
            while((line=br.readLine())!=null){
                String[] elems=line.split(";");
                if (elems.length!=8){
                    System.err.println("Invalid line ..."+line);
                    continue;
                }
                try{
                    int id=Integer.parseInt(elems[0]);
                    int requestId=Integer.parseInt(elems[1]);
                    RequestStatus status=RequestStatus.valueOf(RequestStatus.class,elems[6]);
                    Patient crr=appointRepository.findById(requestId);
                    Appointment crf=new Appointment(id,elems[2],elems[3],elems[4],elems[5],crr);
                    crf.setStatus(status);
                    super.add(crf);
                }catch(NumberFormatException ex){
                    System.err.println("Error converting "+elems[0]);
                }catch (IllegalArgumentException ex){
                    System.err.println("Error converting "+elems[7]);
                }
            }

        }catch(IOException ex){
            throw new RepositoryException("Error reading "+ex);
        }

    }

    private void writeToFile(){
        try(PrintWriter pw=new PrintWriter(filename)){
            pw.println(idGenerator);
            for(Appointment crr:findAll()){
                pw.println(crr.getID()+";"+crr.getPatient().getID()+";"+crr.getHour()+";"+crr.getDate()+";"+crr.getDoctorName()+";"+crr.getMedicalFile()+crr.getStatus());
            }
        }catch(IOException ex){
            throw new RepositoryException("Error writing "+ex);
        }

    }


    @Override
    public Appointment add(Appointment el) {
        el.setID(getNextId());
        super.add(el);
        writeToFile();
        return el;
    }

    @Override
    public void delete(Appointment el) {
        super.delete(el);
        writeToFile();
    }

    @Override
    public void update(Appointment el, Integer integer) {
        super.update(el, integer);
        writeToFile();
    }

    private static int getNextId(){
        return idGenerator++;
    }
}
