package repository;

        import dentist.Patient;
        import dentist.Appointment;

        import java.io.BufferedReader;
        import java.io.FileReader;
        import java.io.IOException;
        import java.io.PrintWriter;

public class PatientFileRepository extends PatientInMemoryRepository {
    private String filename;

    private static int idGenerator=0;

    public PatientFileRepository(String filename) {
        this.filename = filename;
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
                if (elems.length!=4){
                    System.err.println("Invalid line ..."+line);
                    continue;
                }
                try {
                    int id = Integer.parseInt(elems[0]);
                    int requestId=Integer.parseInt(elems[1]);
                    Patient crf=new Patient (id,elems[1],elems[2],elems[4]);


                }catch(NumberFormatException ex){
                    System.err.println("Invalid data "+ex);
                }catch (RepositoryException ex){
                    System.err.println("Repository Error "+ex);
                }
            }
        }catch (IOException ex){
            throw new RepositoryException("Error reading "+ex);
        }

    }

    @Override
    public Patient add(Patient el) {
        el.setID(getNextId());
        super.add(el);
        writeToFile();
        return el;
    }

    @Override
    public void delete(Patient el) {
        super.delete(el);
        writeToFile();
    }

    @Override
    public void update(Patient el, Integer integer) {
        super.update(el, integer);
        writeToFile();
    }

    private void writeToFile(){
        try(PrintWriter pw=new PrintWriter(filename)){
            pw.println(idGenerator);
            for(Patient crf:findAll()){
                pw.println(crf.getID()+";"+crf.getName()+";"+crf.getAddress()+";"+crf.getPhoneNumber());
            }
        }catch(IOException ex){
            throw new RepositoryException("Error writing "+ex);
        }

    }

    private static int getNextId(){
        return idGenerator++;
    }
}
