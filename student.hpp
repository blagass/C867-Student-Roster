//
//  student.hpp
//  WGU C867 Project
//
//  Created by Brandon Lagasse on 6/29/21.
//

#ifndef student_hpp
#define student_hpp

#include "degree.hpp"

#include <stdio.h>
#include <string>
using std::string;

const int daysArrSize = 3; // This is to hold the instantiated days to complete for loop. Const is required for an array field size.

class Student{
    
private:
    string studentID;
    string firstName;
    string lastName;
    string emailAddress;
    int age;
    int daysToComplete[daysArrSize]; //daysArrSize is used here to set the daysToComplete array size
    DegreeProgram degreeProgram;

public:
    //Getters (with definitions)
    string getStudentID(){return studentID;};
    string getFirstName(string firstName){return firstName;};
    string getLastName(string lastName){return lastName;};
    string getEmailAddress(){return emailAddress;};
    int getAge(int age){return age;};
    int* getDaysToComplete(){return daysToComplete;};
    DegreeProgram getDegreeProgram(){return degreeProgram;};
    
    //Setters (with definitions on student.cpp)
    void setStudentID(string studentID);
    void setFirstName(string firstName);
    void setLastName(string lastName);
    void setEmailAddress(string emailAddress);
    void setAge(int age);
    void setDaysToComplete(int daysToComplete[]);
    void setDegreeProgram(DegreeProgram degreeProgram);
    
    //Constructors and Destuctor
    Student();
    Student(string studentID,string firstName,string lastName,string emailAddress,int age,int daysToComplete[3], DegreeProgram degreeProgram);
    ~Student();
    
    //Print specific student data
    void print();
};
#endif /* student_hpp */
