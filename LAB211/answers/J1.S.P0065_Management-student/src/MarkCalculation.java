
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
public class MarkCalculation {

    public Student createStudent(String name, String classes, double maths, double chemistry, double physics) {
        return new Student(name, classes, maths, chemistry, physics);
    }

    public List<Student> averageStudent(List<Student> students) {

        // loop each stu to calculate average marks of students
        for (Student stu : students) {
            double average = (stu.getMath() + stu.getChemistry()
                    + stu.getPhysics()) / 3;
            stu.setAverage(average);
            if (average > 7.5) { // average > 7.5 ~> A type
                stu.setType("A");
            } else if (average >= 6) { // 7.5 >= average >= 6 ~> B type
                stu.setType("B");
            } else if (average >= 4) { // 6 > average >= 4 ~> C type
                stu.setType("C");
            } else { // 4 > average ~> D type
                stu.setType("D");
            }
        }
        return students;
    }

    public HashMap<String, Double> getPercentTypeStudent(List<Student> students) {
        HashMap<String, Double> studenTypes = new HashMap<>();
        int countA = 0, countB = 0, countC = 0, countD = 0;
        // loop each stu in list students count numbers types of students
        for (Student stu : students) {
            switch (stu.getType()) {
                case "A": { // type A ~> countA increase 1
                    countA++;
                    break;
                }
                case "B": { // type B ~> countB increase 1
                    countB++;
                    break;
                }
                case "C": { // type C ~> countC increase 1
                    countC++;
                    break;
                }
                case "D": { // type D ~> countD increase 1
                    countD++;
                    break;
                }
            }
        }
        double percentA = (countA) / (double) students.size() * 100;
        studenTypes.put("A", percentA);
        double percentB = (countB) / (double) students.size() * 100;
        studenTypes.put("B", percentB);
        double percentC = (countC) / (double) students.size() * 100;
        studenTypes.put("C", percentC);
        double percentD = (countD) / (double) students.size() * 100;
        studenTypes.put("D", percentD);
        return studenTypes;
    }
}
