#include <string>
#include <sstream> //String stream for roster data
#include "roster.h"
#include "student.h"
#include "networkStudent.h"
#include "securityStudent.h"
#include "softwareStudent.h"


Student** Roster::getClassRosterArray() 
{
	return this->classRosterArray;
}

//Requirement E 3 a. Add functions

void Roster::add(std::string studentID, std::string firstName, std::string lastName, std::string emailAddress, int age, int daysInCourse1,
	int daysInCourse2, int daysInCourse3, Degree degreeProgram) //Student data string
{
	int* days = new int[3];

	days[0] = daysInCourse1;
	days[1] = daysInCourse2;
	days[2] = daysInCourse3;

	if (degreeProgram == SECURITY) 
	{
		classRosterArray[lastIndex] = new SecurityStudent(studentID, firstName, lastName, emailAddress, age, days, degreeProgram);
		lastIndex++;
	}
	else if (degreeProgram == NETWORK) 
	{
		classRosterArray[lastIndex] = new NetworkStudent(studentID, firstName, lastName, emailAddress, age, days, degreeProgram);
		lastIndex++;
	}
	else if (degreeProgram == SOFTWARE) 
	{
		classRosterArray[lastIndex] = new SoftwareStudent(studentID, firstName, lastName, emailAddress, age, days, degreeProgram);
		lastIndex++;
	}
	// Invalid degree program.
	else 
	{

	}
}

//Requirement E 3 b. Remove student.
void Roster::remove(std::string studentID) 
{
	for (int i = 0; i < 5; i++) 
	{
		if (classRosterArray[i] != nullptr)
			if (classRosterArray[i]->getStudentID() == studentID) //Student found
			{
				delete classRosterArray[i];
				classRosterArray[i] = nullptr;

				std::cout << " Student:" << studentID << " A student with this ID was not found." << std::endl;

				return;
			}
	}

	std::cout << " Student: " << studentID << " This student was not found." << std::endl;
}

//Requirement E 3 c.  Print all function.

void Roster::printAll()
{
	for (int i = 0; i < 5; i++) {
		classRosterArray[i]->print();
	}
}


//Requirement E 3 d Print average days.

void Roster::printAverageDaysInCourse(std::string studentID) 
{
	int* numDays = new int[3];

	int average = 0;

	for (int i = 0; i < 5; i++)
		if (classRosterArray[i]->getStudentID() == studentID) 
		{
			numDays = classRosterArray[i]->getNumDays();

			average = (numDays[0] + numDays[1] + numDays[2]) / 3;

			std::cout << " Student " << studentID << " average days in course: " << average << std::endl;
		}
}
// Requirement E 3 e Print invalid emails.

void Roster::printInvalidEmails() 
{
	std::string emailAddress;

	bool foundAt;
	bool foundPeriod;
	bool foundSpace;

	for (int i = 0; i < 5; i++)
	{
		foundAt = false;
		foundPeriod = false;
		foundSpace = false;

		emailAddress = classRosterArray[i]->getEmailAddress();

		for (int j = 0; j < emailAddress.length(); j++)
		{
			if (emailAddress[j] == '@')
				foundAt = true;
			if (emailAddress[j] == '.')
				foundPeriod = true;
			if (emailAddress[j] == ' ')
				foundSpace = true;
		}
		// || could also be used instead of or.
		if ((foundAt == false) or (foundPeriod == false) or (foundSpace == true))
			
			std::cout << " Student " << classRosterArray[i]->getStudentID() << ": " << classRosterArray[i]->getFirstName() << " " <<
			
			classRosterArray[i]->getLastName() << " has an invalid email: " << classRosterArray[i]->getEmailAddress() << std::endl;
	}

}
//Requirement E 3 f. Print student info for degree program.

void Roster::printByDegreeProgram(Degree degreeProgram) {
	for (int i = 0; i < 5; i++)
		if (classRosterArray[i] != nullptr)
			if (classRosterArray[i]->getDegreeProgram() == degreeProgram)
				classRosterArray[i]->print();
}

//Requirement F 3.

const std::string studentData[] =
{
" A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
" A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
" A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
" A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
" A5,Winston,King,wking26@wgu.edu,37,30,40,35,SOFTWARE"
};

// Constructor for Roster

Roster::Roster() 
{
	// Build the initial class roster array.

	std::istringstream studentDataStream; //istringstream allows acceptance of a single line of text and processes it.

	std::string studentID;
	std::string firstName;
	std::string lastName;
	std::string emailAddress;
	std::string age;
	std::string daysInCourse1, daysInCourse2, daysInCourse3;
	std::string degreeType;

	Degree degreeProgram;

	// No empty slots in data table. Next in line moves up.
	lastIndex = 0;

	for (int i = 0; i < 5; i++) {
		
		// Reads and inputs each string from from student data.
		studentDataStream.clear();
		studentDataStream.str(studentData[i]);

		// Parse data.
		std::getline(studentDataStream, studentID, ',');
		std::getline(studentDataStream, firstName, ',');
		std::getline(studentDataStream, lastName, ',');
		std::getline(studentDataStream, emailAddress, ',');
		std::getline(studentDataStream, age, ',');
		std::getline(studentDataStream, daysInCourse1, ',');
		std::getline(studentDataStream, daysInCourse2, ',');
		std::getline(studentDataStream, daysInCourse3, ',');
		std::getline(studentDataStream, degreeType, ',');

		// Determine Degree enum value from the degree string.
		if (degreeType == "SECURITY")
			degreeProgram = SECURITY;
		else if (degreeType == "NETWORK")
			degreeProgram = NETWORK;
		else if (degreeType == "SOFTWARE")
			degreeProgram = SOFTWARE;

		Roster::add(studentID, firstName, lastName, emailAddress, std::stoi(age), std::stoi(daysInCourse1), std::stoi(daysInCourse2),
			std::stoi(daysInCourse3), degreeProgram);
	}
}

// RosterDestructor

Roster::~Roster() {
	for (int i = 0; i < 5; i++)
		if (classRosterArray[i] != nullptr)
			delete classRosterArray[i];
}
//Requirement F. main function.
int main()
{
	//Requirement F1. Print to screen.
	std::cout << " C867-Scripting & Programming: Applications\n";
	std::cout << " Language: C++\n";
	std::cout << " Student ID: 001116878 \n";
	std::cout << " Name: Winston King\n";
	std::cout << "\n";

	
	// Requirement F2. Create instance classRoster.
	Roster* classRoster = new Roster();

	Student** classRosterArray = classRoster->getClassRosterArray();


	//Requirement F 4.
	classRoster->printAll(); 

	std::cout << std::endl;

	classRoster->printInvalidEmails();

	std::cout << std::endl;

	for (int i = 0; i < 5; i++) 
	{
		classRoster->printAverageDaysInCourse(classRosterArray[i]->getStudentID());
	}

	std::cout << std::endl;

	classRoster->printByDegreeProgram(SOFTWARE);

	std::cout << std::endl;

	classRoster->remove("A3");
	classRoster->remove("A3");

	delete classRoster;

	return 0;

}
