//
//  roster.hpp
//  WGU C867 Project
//
//  Created by Brandon Lagasse on 6/29/21.
//

#ifndef roster_hpp
#define roster_hpp

#include "student.hpp"

#include <stdio.h>

class Roster{
    
    
    //string parsedStrings[8];
    int endStudent = -1;
    int numStudents = 5;
    
public:
    
    void parse(string studentData);
    void add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3,DegreeProgram degreeProgram);
    void printAll();
    void printInvalidEmails();
    void printAverageDaysInCourse(string studentID);
    void printByDegreeProgram(DegreeProgram degreeProgram);
    void remove(string studentID);
    
    Student * classRosterArray[5];

    
Roster();
~Roster();
};

#endif /* roster_hpp */
