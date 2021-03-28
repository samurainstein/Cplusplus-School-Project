#include "roster.h"
#include "degree.h"
#include "student.h"
#include <iostream>
#include <string>
using namespace std;

Roster::Roster() {
}

Roster::~Roster() {
}

void Roster::add(
	string studentID,
	string firstName,
	string lastName,
	string emailAddress,
	int age,
	int daysInCourse1,
	int daysInCourse2,
	int daysInCourse3,
	DegreeProgram degreeProgram) {

	int daysInCourse[] = { daysInCourse1, daysInCourse2, daysInCourse3 };

	Student* studentPointer = new Student(
		studentID,
		firstName,
		lastName,
		emailAddress,
		age,
		daysInCourse,
		degreeProgram
		);
	classRosterArray[studentAddIndex] = studentPointer;
	studentAddIndex++;
	}

void Roster::remove(string studentID)
{
	bool found = false;
	for (int i = 0; i < 5; i++) {
		if (classRosterArray[i] != nullptr) {
			if (studentID == classRosterArray[i]->GetStudentID()) {
				delete classRosterArray[i];
				classRosterArray[i] = nullptr;
				cout << "Student ID " << studentID << " deleted" << '\n';
				found = true;
			}
		}
	}
	if (!found) {
		cout << "Student ID " << studentID << " not found" << '\n';
	}
}

void Roster::printAll() {
	for (int i = 0; i < 5; i++) {
		if (classRosterArray[i] != nullptr) {
			classRosterArray[i]->Print();
		}
	}
}

void Roster::printAverageDaysInCourse(string studentID) {
	int sum = 0;
	double average = 0;
	for (int i = 0; i < 5; i++) {
		if (classRosterArray[i] != nullptr) {
			if (classRosterArray[i]->GetStudentID() == studentID) {
				sum = classRosterArray[i]->GetDaysInCourse()[0] +
					classRosterArray[i]->GetDaysInCourse()[1] +
					classRosterArray[i]->GetDaysInCourse()[2];
				average = sum / 3;
				cout << "Student ID: " << studentID << " - Average Days In Course: " << average << '\n';
			}
		}
	}
}

void Roster::printInvalidEmails() {
	for (int i = 0; i < 5; i++) {
		string emailCheck = "";
		emailCheck = classRosterArray[i]->GetEmailAddress();
		if (emailCheck.find(' ') != string::npos) {
			cout << "Invalid Email Address: " << emailCheck << '\n';
		}
		else if (emailCheck.find('@') == string::npos) {
			cout << "Invalid Email Address: " << emailCheck << '\n';
		}
		else if (emailCheck.find('.') == string::npos) {
			cout << "Invalid Email Address: " << emailCheck << '\n';
		}
	}
}

void Roster::printByDegreeProgram(DegreeProgram degreeProgram) {
	for (int i = 0; i < 5; i++) {
		if (classRosterArray[i] != nullptr) {
			if (classRosterArray[i]->GetDegreeProgram() == degreeProgram) {
				cout << classRosterArray[i]->GetFirstName() << " " << classRosterArray[i]->GetLastName() << '\n';
			}
		}
	}
}

	


