#pragma once
#include <iostream>
#include <string>
#include "student.h"

class SoftwareStudent : public Student  // Subclass of Student. Requirement D. 3
{
public:

	SoftwareStudent(
		std::string studentID,
		std::string firstName,
		std::string lastName,
		std::string emailAddress,
		int age,
		int* numDays,
		Degree degreeProgram);

	//These virtual methods are overridden in this class.
	Degree getDegreeProgram();
	void print();

protected:
	Degree degreeProgram;

	//Destructor
	~SoftwareStudent();
};