#include <iostream>
#include "softwareStudent.h"




SoftwareStudent::SoftwareStudent(std::string studentID, std::string firstName, std::string lastName, std::string emailAddress, int age, int* numDays, Degree degreeProgram)

	: Student(studentID, firstName, lastName, emailAddress, age, numDays)
{
	this->degreeProgram = degreeProgram;
}

Degree SoftwareStudent::getDegreeProgram()
{
	return degreeProgram;
}

void SoftwareStudent::print()
{
	int* numDays;

	numDays = this->getNumDays();

	std::cout << this->getStudentID() << "\t";
	std::cout << "First Name: " << this->getFirstName() << "\t";
	std::cout << "Last Name: " << this->getLastName() << " \t";
	std::cout << "Age: " << this->getAge() << " \t";
	std::cout << "Days in course: {" << numDays[0] << ", " << numDays[1] << ", " << numDays[2] << "} \t";
	std::cout << "Degree Program: SOFTWARE";
	std::cout << std::endl;
}

SoftwareStudent::~SoftwareStudent()
{

}