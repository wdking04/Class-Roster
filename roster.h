#pragma once
#include <iostream>
#include <string>
#include "student.h"
#include "securityStudent.h"
#include "networkStudent.h"
#include "softwareStudent.h"


class Roster
{
public:

	Student** getClassRosterArray();


	void add(std::string studentID, std::string firstName, std::string lastName, std::string emailAddress, int age, int daysInCourse1,
		int daysInCourse2, int daysInCourse3, Degree degreeProgram);
	void printAll();
	void remove(std::string studentID);  // removes a student based on id
	void printAverageDaysInCourse(std::string studentID);
	void printInvalidEmails();
	void printByDegreeProgram(Degree degreeProgram);


	Roster();
	~Roster();  // destructor destroys the roster

protected:
	// Rubric E1: Array of pointers created to hold data in the studentData table.
	Student* classRosterArray[5];

	// Records how many entries in roster, the next unused slot in the roster array.
	int lastIndex;


};