

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author phuon
 */
public class Main {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        DoctorManagement manager = new DoctorManagement();
        DataInput in = new DataInput();
        FileAnalyze fa = new FileAnalyze();
        
//        List<Doctor> doctors = new ArrayList<>();
//        doctors.add(new Doctor("P1", "Phuong", "doc1", 3));
//        doctors.add(new Doctor("P3", "Ngo", "doc3", 1));
//        fa.exportData(doctors);
//
//        List<Doctor> doctors = fa.importDoctors();
//        for (Doctor doctor : doctors) {
//            System.out.println(doctor);
//        }
        boolean isExit = false;
        // loop until user choose stop the program
        while (!isExit) {
            manager.displayMenu();
            int choice = in.inputInt("Choice", 1, 5, false);            
            switch (choice) {
                case 1: { // choose 1: add a doctor
                    manager.addDoctor();
                    break;
                }
                case 2: { // choose 2: update a doctor
                    manager.updateDoctor();
                    break;
                }
                case 3: { // choose 3: delete a doctor
                    manager.deleteDoctor();
                    break;
                }
                case 4: { // choose 4: search a doctor
                    manager.searchDoctor();
                    break;
                }
                case 5: { // choose 5: exit program
                    isExit = true;
                    break;
                }
            }
        }
    }
    
}
