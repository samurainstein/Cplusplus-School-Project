#include <iostream>
#include <string>
#include "degree.h"
#include "student.h"
#include "roster.h"
using namespace std;

int main() {

	cout << "Course Title: Scripting and Programming - Applications (C867)" << endl;
	cout << "Programming Language: C++" << endl;
	cout << "WGU Student ID: 002312922" << endl;
	cout << "Name: Eric Matelyan" << endl;
	cout << endl;

	const string studentData[] = {
		"A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
		"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
		"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
		"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
		"A5,Eric,Matelyan,eric.matelyan@gmail.com,32,15,20,25,SOFTWARE"
	};

	Roster* classRoster = new Roster;
	
	//------------Parse and Add------------
	const int numStudents = 5;
	
	for (int i = 0; i < numStudents; i++) {
		size_t rhs = studentData[i].find(",");
		string studentID = studentData[i].substr(0, rhs);

		size_t lhs = rhs + 1;
		rhs = studentData[i].find(",", lhs);
		string firstName = studentData[i].substr(lhs, rhs - lhs);

		lhs = rhs + 1;
		rhs = studentData[i].find(",", lhs);
		string lastName = studentData[i].substr(lhs, rhs - lhs);

		lhs = rhs + 1;
		rhs = studentData[i].find(",", lhs);
		string emailAddress = studentData[i].substr(lhs, rhs - lhs);

		lhs = rhs + 1;
		rhs = studentData[i].find(",", lhs);
		int age = stoi(studentData[i].substr(lhs, rhs - lhs));

		lhs = rhs + 1;
		rhs = studentData[i].find(",", lhs);
		int daysInCourse1 = stoi(studentData[i].substr(lhs, rhs - lhs));

		lhs = rhs + 1;
		rhs = studentData[i].find(",", lhs);
		int daysInCourse2 = stoi(studentData[i].substr(lhs, rhs - lhs));

		lhs = rhs + 1;
		rhs = studentData[i].find(",", lhs);
		int daysInCourse3 = stoi(studentData[i].substr(lhs, rhs - lhs));

		lhs = rhs + 1;
		rhs = studentData[i].find(",", lhs);
		string degreeProgramString = (studentData[i].substr(lhs));

		DegreeProgram degreeProgram = SECURITY;
		if (degreeProgramString == "NETWORK") {
			degreeProgram = NETWORK;
		}
		if (degreeProgramString == "SOFTWARE") {
			degreeProgram = SOFTWARE;
		}

		classRoster->add(
			studentID,
			firstName,
			lastName,
			emailAddress,
			age,
			daysInCourse1,
			daysInCourse2,
			daysInCourse3,
			degreeProgram
		);
	}

	classRoster->printAll();
	cout << '\n';

	classRoster->printInvalidEmails();
	cout << '\n';

	for (int i = 0; i < 5; i++) {
		classRoster->printAverageDaysInCourse(classRoster->findStudent(i)->GetStudentID());
	}
	cout << '\n';

	classRoster->printByDegreeProgram(SOFTWARE);
	cout << '\n';

	classRoster->remove("A3");
	cout << '\n';

	classRoster->printAll();
	cout << '\n';

	classRoster->remove("A3");
	cout << '\n';

	delete classRoster;

	return 0;
}