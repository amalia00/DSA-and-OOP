/*package Controller;
import dentist.Patient;
import dentist.Appointment;
import streams.*;

import java.util.Scanner;

public class Controller {
    private AppointmentStream apstream;
    private PatientStream pstream;
    private Scanner scanner;

    public Controller(AppointmentStream apstream,PatientStream pstream, Scanner scanner){
        this.apstream =apstream;
        this.pstream=pstream;
        this.scanner=scanner;
    }

    public static void printMenu(){
        System.out.println("1.Add appointment ");
        System.out.println("2. The name of all the patients");
        System.out.println("3. The phone number of a certain patient");
        System.out.println("4. All the information about a certain patient");
        System.out.println("5. All the patients that have an appointment on a given day");
        System.out.println("6. All the appointments and the status of them for a certain patient");
        System.out.println("7. The medical file of a patient");
    }
    private void handleMenu(){
        System.out.print(" your option is ");
        int option=scanner.nextInt();
        switch (option) {
            case 1:
                System.out.print(" id for the appointment= ");
                int idapp = scanner.nextInt();
                System.out.println("hour of the appointment ");
                String hour=scanner.next();
                System.out.println("Date of the appointment ");
                String date=scanner.next();
                System.out.println("The name of the doctor ");
                String docname=scanner.next();
                System.out.println("The status of the appointment ");
                String status=scanner.next();
                System.out.println("The medical file of the patient ");
                String medfile=scanner.next();
                System.out.print(" id for the patient= ");
                int idp = scanner.nextInt();
                System.out.println("The name of the patient ");
                String name=scanner.next();
                System.out.println("The adress of the patient ");
                String adress=scanner.next();
                System.out.println("The phone number of the patient ");
                String pnr=scanner.next();
                apstream.add(new Appointment(idapp,hour,date,docname,status,medfile,new Patient(idp,name,adress,pnr)));
                break;
            case 2:
                for(var i : pstream.allPatients())
                    System.out.println(i);
            case 3:
                System.out.println("The name of the patient");
                String namep=scanner.next();
                System.out.println(pstream.thePhNr(namep));
            case 4:
                System.out.println("The name of the patient");
                String namepp=scanner.next();
                System.out.println(pstream.patientbyName(namepp));
            case 5:
                System.out.println("The date for the appointments you want to see ");
                String datea=scanner.next();
                for (var i : apstream.patientsByDate(datea))
                    System.out.println(i);
            case 6:
                System.out.println("The name of the patient");
                String namepat=scanner.next();
                for (var i : apstream.appoForPatient(namepat))
                    System.out.println(i);
            case 7:
                System.out.println("The name of the patient");
                String n=scanner.next();
                for (var i : apstream.problemsPat(n))
                    System.out.println(i);
        }
    }
}
*/