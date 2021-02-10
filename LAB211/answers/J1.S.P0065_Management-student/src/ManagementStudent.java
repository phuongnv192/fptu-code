
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
/**
 *
 * @author phuon
 */
public class ManagementStudent {

    public List<Student> inputMark() {
        DataInput in = new DataInput();
        System.out.println("====== Management Student Program ======");
        List<Student> students = new ArrayList<>();
        boolean isExit = false;

        // loop until user choose stop input student's info
        while (!isExit) {
            String name = in.inputStr("Name");
            String classes = in.inputStr("Classes");
            double math = in.inputMark("Maths");
            double chemistry = in.inputMark("Chemistry");
            double physics = in.inputMark("Physics");
            MarkCalculation cal = new MarkCalculation();
            Student stu = cal.createStudent(name, classes, math, chemistry, physics);
            students.add(stu);
            System.out.print("Do you want to enter more student information? (Y/N): ");
            boolean isYes = in.isYesOrNo();
            if (!isYes) { // choose Y ~> exit
                isExit = true;
            }
        }
        return students;
    }

    public void showStudentInfos(List<Student> students) {
        System.out.println();
        int count = 1;
        
        // display each student's info in list students
        for (Student stu : students) {
            System.out.println("------ Student" + count + " Info ------");
            System.out.println("Name: " + stu.getName());
            System.out.println("Classes: " + stu.getClasses());
            System.out.format("AVG: %.1f\n", stu.getAverage());
            System.out.println("Type: " + stu.getType());
            count++;
        }
    }

    public void showClassificationInfo(HashMap<String, Double> studentTypes) {
        System.out.println("--------Classification Info -----");
        
        // display statitics of each type of students in studentTypes
        for (Map.Entry<String, Double> entry : studentTypes.entrySet()) {
            String type = entry.getKey();
            Double percent = entry.getValue();
            System.out.format("%s: %.1f%%\n", type, percent);
        }
    }
}
