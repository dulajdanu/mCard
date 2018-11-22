package com.solutions.mazz.mcard;

import java.util.Date;

public class Student
{
    private String nameOfStu;
    private int ageOfStu;
    private String schoolOfStu;
    private int phoneOfStu;
    private Boolean hasPaid;
    //private Date dateJoined;
    private int daysAbsent;

    public  Student(String name, String school , int phoneNum)
    {
        this.nameOfStu = name;
        this.ageOfStu =18;
        this.schoolOfStu = school;
        this.phoneOfStu = phoneNum;
        this.hasPaid = Boolean.TRUE;
        //this.dateJoined = 2018.1.
        this.daysAbsent = 0;
    }

    public Boolean getHasPaid() {
        return hasPaid;
    }

    public int getAgeOfStu() {
        return ageOfStu;
    }

    public int getDaysAbsent() {
        return daysAbsent;
    }

    public int getPhoneOfStu() {
        return phoneOfStu;
    }

    public String getNameOfStu() {
        return nameOfStu;
    }

    public String getSchoolOfStu() {
        return schoolOfStu;
    }

}
