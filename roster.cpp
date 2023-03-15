//
//  roster.cpp
//  WGU C867 Project
//
//  Created by Brandon Lagasse on 6/29/21.
//

#include "roster.hpp"
#include "student.hpp"

#include <iostream>
#include <vector>
#include <sstream>
#include <string>

using std::vector;
using std::stringstream;
using std::string;
using std::cout;
using std::endl;


//Parse string using studentData as input parameter
void Roster::parse(string studentData){
    size_t beginning;
    size_t end;
    
    end = studentData.find(",");
    string studentID = studentData.substr(0,end);
    
    beginning = end + 1;
    
    end = studentData.find(",", beginning);
    string firstName = studentData.substr( beginning, end - beginning);
    
    beginning = end + 1;
    
    end = studentData.find(",",beginning);
    string lastName = studentData.substr(beginning, end - beginning);
    
    beginning = end + 1;
    
    end = studentData.find(",",beginning);
    string emailAddress = studentData.substr(beginning, end - beginning);
    
    beginning = end + 1;
    
    end = studentData.find(",",beginning);
    int age = stoi(studentData.substr(beginning, end - beginning));
    
    beginning = end + 1;
    
    end = studentData.find(",",beginning);
    int daysInCourse1 = stoi(studentData.substr(beginning, end - beginning));

    beginning = end + 1;
    
    end = studentData.find(",",beginning);
    int daysInCourse2 = stoi(studentData.substr(beginning, end - beginning));
    
    beginning = end + 1;
    
    end = studentData.find(",",beginning);
    int daysInCourse3 = stoi(studentData.substr(beginning, end - beginning));
    
    beginning = end + 1;
    
    end = studentData.find(",",beginning);
    string strDegreeProgram = studentData.substr(beginning, end - beginning);
    
    //Switch to print string degree
    DegreeProgram degreeProgram = DegreeProgram::SOFTWARE;
    if(strDegreeProgram == "SOFTWARE")
    {
        degreeProgram = DegreeProgram::SOFTWARE;
    }
    else if (strDegreeProgram == "NETWORK")
    {
        degreeProgram = DegreeProgram::NETWORK;
    }
    else if (strDegreeProgram == "SECURITY")
    {
        degreeProgram = DegreeProgram::SECURITY;
    }
    
    //Invoke the add() function from within parse() to assign strings to each paramater
    add(studentID, firstName, lastName, emailAddress, age, daysInCourse1, daysInCourse2 , daysInCourse3,degreeProgram);
}
;

//Add each parameter to each students private variables
void Roster::add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3,DegreeProgram degreeProgram)
    {
    if (endStudent < numStudents){
        endStudent++;
        
        classRosterArray[endStudent] = new Student();
        classRosterArray[endStudent]->setStudentID(studentID);
        classRosterArray[endStudent]->setFirstName(firstName);
        classRosterArray[endStudent]->setLastName(lastName);
        classRosterArray[endStudent]->setEmailAddress(emailAddress);
        classRosterArray[endStudent]->setAge(age);
        int days[daysArrSize]= { daysInCourse1,daysInCourse2,daysInCourse3};
        classRosterArray[endStudent]->setDaysToComplete(days);
        classRosterArray[endStudent]->setDegreeProgram(degreeProgram);
    }
    else{
        cout << "Not enough room." << endl;
    };
        
};

//Print all students loop
void Roster::printAll(){
    cout << "Displaying all students:" << '\n' << endl;
    for (int i=0; i <= this->endStudent; i++)
    {
        this->classRosterArray[i]->print();
    };
    cout << endl;
}

//Constructor
Roster::Roster(){};

//Destructor
Roster::~Roster(){
    for (int i=0;i < numStudents; i++)
    {
        delete this->classRosterArray[i];
    };
        delete this;
};

//PRINT invalid emails loop
void Roster::printInvalidEmails(){
    cout << "Displaying invalid emails:" << '\n' << endl;
    for (int i = 0; i < numStudents; ++i){
        string emailChecker = this->classRosterArray[i]->getEmailAddress();
        
        if((emailChecker.find('.') == string::npos) || (emailChecker.find('@') == string::npos) || !(emailChecker.find(' ') == string::npos))
        {
            cout << "Error - incorrect formatting on " << emailChecker << endl;
        }
        
    };
    cout << endl;
}

//Average the days in each course by matching hte studentID
void Roster::printAverageDaysInCourse(string studentID){
    for (int i=0;i < numStudents; i++){
        if(this->classRosterArray[i]->getStudentID() == studentID){
            int * daysToCompleteArr;
            
            daysToCompleteArr = classRosterArray[i]->getDaysToComplete();
            
            int avgDays = (daysToCompleteArr[0] + daysToCompleteArr[1] + daysToCompleteArr[2]) / 3;
            
            cout << studentID << " average days in course: " << avgDays << endl;
        };
    };
    
};

//Case switch for degreeProgram input
void Roster::printByDegreeProgram(DegreeProgram degreeProgram){
    string degree;
    
    switch (degreeProgram){
        case SOFTWARE:
            degree = "Software";
            break;
            
        case NETWORK:
            degree = "Network";
            break;
            
        case SECURITY:
            degree = "Security";
        break;}
    
    cout << "Showing students in degree program:" << degree << '\n'<< endl;
    
    for (int i =0; i < numStudents; i++){
        if(this->classRosterArray[i]->getDegreeProgram() == degreeProgram){
            this->classRosterArray[i]->print();
        }
    }
    cout << endl;
};

//Remove Student90 from array based on studentID
void Roster::remove(string studentID){
    cout << "Removing " << studentID << ":" << '\n';
    bool id = false;
    for (int i = 0;i < numStudents; i++)
    {
        if(this->classRosterArray[i]->getStudentID() == studentID)
        {
            id = true;
            delete this->classRosterArray[i];
            this->classRosterArray[i] = this->classRosterArray[endStudent];
            endStudent--;
        }
    }
    if (id == false){
        cout << "The student with the ID: " << studentID << " was not found." << endl;
    }
    ;
    cout << endl;
};



