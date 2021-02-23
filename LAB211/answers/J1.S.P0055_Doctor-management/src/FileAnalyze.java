
import entity.Doctor;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.FileWriter;
import java.io.IOException;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.util.ArrayList;
import java.util.List;
import java.util.logging.Level;
import java.util.logging.Logger;

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
/**
 *
 * @author phuon
 */
public class FileAnalyze {

    public List<Doctor> importDoctors() {
        List<Doctor> doctors = new ArrayList<>();
        File f = new File("doctors.dat");

        if (!f.exists()) {
            System.out.println("Read data failed: File is not exists.");
            return new ArrayList<>();
        }
        if (f.length() == 0) {
            System.out.println("Read data failed: File empty.");
            return new ArrayList<>();
        }

        FileInputStream in = null;
        try {
            in = new FileInputStream(f);
            ObjectInputStream ois = new ObjectInputStream(in);
            doctors = (List<Doctor>) ois.readObject(); // exception
            System.out.println("Import successfull " + doctors.size() + " doctors. ");
        } catch (IOException | ClassNotFoundException ex) {
            System.out.println("Read data failed: Can not read file.");
            f.delete();
            return new ArrayList<>();
        } finally {
            try {
                in.close();
            } catch (IOException ex) {
            }
        }
        return doctors;
    }

    public boolean exportData(List<Doctor> doctors) {
        DataInput in = new DataInput();
        File f = new File("doctors.dat");
        boolean isWrite = true;

        if (!f.exists()) {
            try {
                f.createNewFile();
            } catch (IOException ex) {
            }
        } else if (f.length() > 0) {
            System.out.print("File already exists, do you want to overwrite? (Y/N): ");
            isWrite = in.isYesOrNo();
        }

        if (isWrite) {
            FileOutputStream fos = null;
            try {
                fos = new FileOutputStream(f);
                ObjectOutputStream oos = new ObjectOutputStream(fos);
                oos.writeObject(doctors);
                System.out.println("Export data successfull.");
            } catch (IOException ex) {
            } finally {
                try {
                    fos.close();
                } catch (IOException ex) {
                }
            }
            return true;
        } else {
            System.out.println("Export data failed.");
            return false;
        }
    }
}
