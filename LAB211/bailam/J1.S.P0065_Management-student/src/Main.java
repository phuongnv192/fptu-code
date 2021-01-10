
import java.util.HashMap;
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
public class Main {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        ManagementStudent manager = new ManagementStudent();
        MarkCalculation markCal = new MarkCalculation();

        List<Student> students = manager.inputMark();

        students = markCal.averageStudent(students);
        HashMap<String, Double> studentTypes = markCal.getPercentTypeStudent(students);

        manager.showStudentInfos(students);
        manager.showClassificationInfo(studentTypes);
    }
}
