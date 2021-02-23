
import entity.Doctor;
import java.util.ArrayList;
import java.util.List;

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
/**
 *
 * @author phuon
 */
public class DoctorManagement {

    public void displayMenu() {
        System.out.println();
        System.out.println("========= Doctor Management ==========");
        System.out.println("1. Add Doctor");
        System.out.println("2. Update Doctor");
        System.out.println("3. Delete Doctor");
        System.out.println("4. Search Doctor");
        System.out.println("5. Exit");
        System.out.print("Your choice: ");
    }

    public void addDoctor() {
        DataInput in = new DataInput();
        FileAnalyze fa = new FileAnalyze();

        System.out.println("--------- Add Doctor ----------");
        List<Doctor> doctors = fa.importDoctors();
        String code = in.inputNewID(doctors, false);
        String name = in.inputStr("Name", false);
        String specialization = in.inputStr("Specialization", false);
        System.out.print("Enter availability: ");
        int availability = in.inputInt("Availability", 0, Integer.MAX_VALUE, false);
        Doctor d = new Doctor(code, name, specialization, availability);
        doctors.add(d);
        boolean isSuccess = fa.exportData(doctors);
        System.out.println(isSuccess ? "Update doctor successfull." : "Update doctor failed.");
    }

    public void updateDoctor() {
        DataInput in = new DataInput();
        FileAnalyze fa = new FileAnalyze();

        System.out.println("--------- Update Doctor -------");
        List<Doctor> doctors = fa.importDoctors();
        String code = in.inputExistedID(doctors);
        Doctor d = in.getDoctorByID(doctors, code);
        String oldName = d.getName();
        String oldSpecialization = d.getSpecialization();
        int oldAvailability = d.getAvailability();
        doctors.remove(d);
        /* Update error : 
        - all blank <~> keep all = not change
        - same old infos <~> not change
        - duplicated id
         */
        System.out.println("Edit your new information:");
        String newCode = in.inputNewID(doctors, true); // accepted duplicated id
        String newName = in.inputStr("Name", true);
        String newSpecialization = in.inputStr("Specialization", true);
        System.out.print("Enter availability: ");
        int newAvailability = in.inputInt("Availability", 0, Integer.MAX_VALUE, true);
        Doctor newD = new Doctor(newCode, newName, newSpecialization, newAvailability);

        // duplicated code
        if (in.getDoctorByID(doctors, newCode) != null) {
            System.out.println("Update fail: new info has "
                    + "code duplicated with another infos");
        } else if ((newCode == null
                && newName == null
                && newSpecialization == null
                && newAvailability == -1) || newD.compareTo(d) == 0) {
            // same old info

            System.out.println("Update fail: new infos must not the same with old infos");
        } else { // correct update process
            boolean isSuccess = fa.exportData(doctors);
            System.out.println(isSuccess ? "Update doctor successfull." : "Update doctor failed.");

        }

    }

    public void deleteDoctor() {
        DataInput in = new DataInput();
        FileAnalyze fa = new FileAnalyze();

        System.out.println("--------- Delete Doctor -------");
        List<Doctor> doctors = fa.importDoctors();
        String code = in.inputExistedID(doctors);
        Doctor d = in.getDoctorByID(doctors, code);
        doctors.remove(d);

        boolean isSuccess = fa.exportData(doctors);
        System.out.println(isSuccess ? "Update doctor successfull." : "Update doctor failed.");
    }

    public void searchDoctor() {
        DataInput in = new DataInput();
        FileAnalyze fa = new FileAnalyze();

        System.out.println("---------- Search Doctor --------");
        List<Doctor> doctors = fa.importDoctors();
        String text = in.inputStr("text", true);

        List<Doctor> result = getDoctorByText(doctors, text);
        if (!result.isEmpty()) { // not empty ~> found
            System.out.format("%-7s %-11s %-19s %12s\n", "Code", "Name", "Specialization", "Availability");
            for (Doctor d : result) {
                System.out.println(d.toString());
            }
        } else {
            System.out.println("There are no doctor have text \"" + text + "\"");
        }
    }

    private List<Doctor> getDoctorByText(List<Doctor> doctors, String text) {
        List<Doctor> result = new ArrayList<>();

        if (text == null) { // empty ~> show all
            return doctors;
        } else {
            for (Doctor d : doctors) {
                // match id, name or specialization
                if (d.getCode().contains(text)
                        || d.getName().contains(text)
                        || d.getSpecialization().contains(text)) {
                    result.add(d);
                }
            }
        }
        return result;
    }
}
