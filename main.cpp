//
//  main.cpp
//  WGU C867 Project
//
//  Created by Brandon Lagasse on 6/29/21.
//
#include "degree.hpp"
#include "roster.hpp"
#include <iostream>

using std::string;
using std::cout;
using std::endl;

int main() {
    
    // Provided student data string array, including my own information.
    const string studentData[5] =
    {"A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY", "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK", "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE", "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY", "A5,Brandon,Lagasse,blagass@student.wgu.edu,40,40,30,50,SOFTWARE"};
    
    //Creating a new roster
    Roster * classRoster = new Roster;
    
    
    //Parse the student data and assign to new student objects
    for(int i=0; i < 5; i++){
        classRoster->parse(studentData[i]);
    };
    
    //Printing all students
    classRoster->printAll();
    
    //Printing invalid emails
    classRoster->printInvalidEmails();
    
    //For loop to print average days in course
    cout << "Printing Average days in course: " << endl;
    cout << endl;
    for(int i =0; i < 5; i++){
        classRoster->printAverageDaysInCourse(classRoster->classRosterArray[i]->getStudentID());
    };
    
    cout << endl;
    //Print by degree program
    classRoster->printByDegreeProgram(SOFTWARE);
    
    //Remove Student with ID "A3"
    classRoster->remove("A3");
    
    //Print all students with A3 removed
    classRoster->printAll();
    
    //Remove A3 again to show error message
    classRoster->remove("A3");
    
    //Confirmation to let the user know the process is complete
    cout << "DONE." << endl;

    return 0;
}
