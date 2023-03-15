//
//  student.cpp
//  WGU C867 Project
//
//  Created by Brandon Lagasse on 6/29/21.
//

#include "student.hpp"
#include <string>
#include <iostream>

using std::string;
using std::cout;
using std::endl;

//string getStudentID(){
  //  return studentID;
    
///};

//Setter functions  (Getters defined in student.hpp)
void Student::setStudentID(string studentID){
    this->studentID = studentID;
};

void Student::setFirstName(string firstName){
    this->firstName = firstName;
};

void Student::setLastName(string lastName){
    this->lastName = lastName;
};

void Student::setEmailAddress(string emailAddress){
    this->emailAddress = emailAddress;
};

void Student::setAge(int age){
    this->age = age;
};

void Student::setDaysToComplete(int daysToComplete[]){
    for (int i=0; i < daysArrSize; i++){
        this->daysToComplete[i] = daysToComplete[i];
    }
};

void Student::setDegreeProgram(DegreeProgram degreeProgram){
    this->degreeProgram = degreeProgram;
};

//Constructors and Destructor

Student::Student(){
    this->studentID = "No ID.";
    this->firstName = "No First Name.";
    this->lastName = "No Last Name.";
    this->emailAddress = "No Email Address.";
    this->age = -1;
    
    //daysToCompleteomple loop
    for (int i = 0; i < daysArrSize; i++){
        this-> daysToComplete[i] = 0;
    };
    
    this->degreeProgram = SOFTWARE;
};

Student::Student(string studentID,string firstName,string lastName,string emailAddress,int age,int daysToComplete[daysArrSize], DegreeProgram degreeProgram){
    this->studentID = studentID;
    this->firstName = firstName;
    this->lastName = lastName;
    this->emailAddress = emailAddress;
    this->age = age;
    
    //daysToCompleteomple loop
    for (int i = 0; i < daysArrSize; i++){
        this-> daysToComplete[i] = daysToComplete[i];
    };
    //DegreeProgram enum selector
    this->degreeProgram = degreeProgram;
};

Student::~Student(){};

//Print the student data, showing all object private vaiables.
void Student::print(){
    cout << getStudentID() << '\t';
    cout << getFirstName(this->firstName) << '\t';
    cout << getLastName(this->lastName) << '\t';
    cout << getEmailAddress() << '\t';
    cout << getAge(this->age) << '\t';
    cout << "{" << getDaysToComplete() << "}" << '\t';
    
    switch (getDegreeProgram()){
        case SOFTWARE:
            cout << "Software" << endl;
            break;
            
        case NETWORK:
            cout << "Network" << endl;
            break;
            
        case SECURITY:
            cout << "Security" << endl;
            break;
    }
};

