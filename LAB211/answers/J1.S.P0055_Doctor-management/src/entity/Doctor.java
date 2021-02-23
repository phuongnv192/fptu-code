/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package entity;

import java.io.Serializable;

/**
 *
 * @author phuon
 */
public class Doctor implements Serializable, Comparable<Doctor> {

    private String code;
    private String name;
    private String specialization;
    private int availability;

    public Doctor(String code, String name, String specialization, int availability) {
        this.code = code;
        this.name = name;
        this.specialization = specialization;
        this.availability = availability;
    }

    @Override
    public int compareTo(Doctor rhs) {
        if (code.equals(rhs.code)) {
            if (name.equals(rhs.name)) {
                if (specialization.equals(rhs.specialization)) {
                    return availability - rhs.availability;
                }
                return specialization.compareTo(rhs.specialization);
            }
            return name.compareTo(rhs.name);
        }
        return code.compareTo(rhs.code);
    }

    @Override
    public String toString() {
        return String.format("%-7s %-11s %-19s %5d",
                code, name, specialization, availability);
    }

    public String getCode() {
        return code;
    }

    public void setCode(String code) {
        this.code = code;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public String getSpecialization() {
        return specialization;
    }

    public void setSpecialization(String specialization) {
        this.specialization = specialization;
    }

    public int getAvailability() {
        return availability;
    }

    public void setAvailability(int availability) {
        this.availability = availability;
    }
}
