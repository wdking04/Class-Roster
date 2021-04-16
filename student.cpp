#include "iostream"
#include "degree.h"
#include "student.h"

// Requirement 2.C constructors

Student::Student(std::string studentID, std::string firstName, std::string lastName, std::string emailAddress, int age, int* numDays) 
{
	this->studentID = studentID;
	this->firstName = firstName;
	this->lastName = lastName;
	this->emailAddress = emailAddress;
	this->age = age;
	this->numDays = numDays;
}

//getters(accessors) Requirement D. 2. a

std::string Student::getStudentID() 
{
	return this->studentID;
}

std::string Student::getFirstName() 
{
	return this->firstName;
}

std::string Student::getLastName() 
{
	return this->lastName;
}

std::string Student::getEmailAddress() 
{
	return this->emailAddress;
}

int Student::getAge() 
{
	return this->age;
}

int* Student::getNumDays()   // * is pointer to array of numDays
{
	return this->numDays;
}


//setters (mutators) Requirement D. 2. b

void Student::setStudentID(std::string studentID) 
{
	this->studentID = studentID;
}

void Student::setFirstName(std::string firstName)
{
	this->firstName = firstName;
}

void Student::setLastName(std::string lastName) 
{
	this->lastName = lastName;
}

void Student::setEmailAddress(std::string emailAddress) 
{
	this->emailAddress = emailAddress;
}

void Student::setAge(int age) 
{
	this->age = age;
}

void Student::setNumDays(int* numDays)
{
	for (int i = 0; i < 3; i++)
		this->numDays[i] = numDays[i];
}
//Destructor
Student::~Student() 
{
	// Delete the array created for days to complete course.
	delete this->numDays;
}