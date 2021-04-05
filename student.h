#pragma once
#include <iostream>
#include <string>
#include "degree.h"
using std::string;

//abstract class because has virtual methods.
//Requirement D. 1 Create student class.


class Student {

protected:  //items are visible to derived classes
	std::string studentID;
	std::string firstName;
	std::string lastName;
	std::string emailAddress;

	int age;
	int* numDays;

public:

	Student(std::string studentID, string firstName, string lastName, string emailAddress,
		int age, int* numDays); //full constructor - does not include degree, sublcasses will do this


	//Requirement D. 2 a. "getters" accessors for each instance field.

	std::string getStudentID();
	std::string getFirstName();
	std::string getLastName();
	std::string getEmailAddress();
	int getAge();
	int* getNumDays(); // * on int is a pointer to the array of days.
	
	virtual Degree getDegreeProgram() = 0; // VIRTUAL; left to the subclass to et Degree type. Requirement D. 2 f.

	//Requirement D. 2 b. "setters" mutators
	void setStudentID(std::string studentID);
	void setFirstName(std::string firstName);
	void setLastName(std::string lastName);
	void setEmailAddress(std::string emailAddress);
	void setAge(int age);
	void setNumDays(int* numDays);
	
	virtual void print() = 0; // displays / print specific student data defined in subclass. Requirement D. 2 d

// Requirement D. 2 e. The destructor. 
	~Student();

};


