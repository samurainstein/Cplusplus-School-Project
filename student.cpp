#include <string>
#include "degree.h";
#include "student.h";
#include <iostream>
using namespace std;

Student::Student() {
	studentID = "AA";
	firstName = "First Name";
	lastName = "Last Name";
	emailAddress = "Email Address";
	age = 0;
	daysInCourse[0] = 0;
	daysInCourse[1] = 0;
	daysInCourse[2] = 0;
	degreeProgram = DegreeProgram::SOFTWARE;
}

Student::Student(
	string studentID,
	string firstName,
	string lastName,
	string emailAddress,
	int age,
	int daysInCourse[],
	DegreeProgram degreeProgram) {

	this->studentID = studentID;
	this->firstName = firstName;
	this->lastName = lastName;
	this->emailAddress = emailAddress;
	this->age = age;
	this->daysInCourse[0] = daysInCourse[0];
	this->daysInCourse[1] = daysInCourse[1];
	this->daysInCourse[2] = daysInCourse[2];
	this->degreeProgram = degreeProgram;
}

void Student::Print() {
	cout << "Student ID: " << studentID << '\t'
		<< "First Name: " << firstName << '\t'
		<< "Last Name: " << lastName << '\t'
		<< "Email Address: " << emailAddress << '\t'
		<< "Age: " << age << '\t'
		<< "Days In Course: " << *daysInCourse << '\t'
		<< "DegreeProgram: " << degreeProgramStrings[degreeProgram] << '\n';
}

void Student::SetStudentID(string studentID) {
	this->studentID = studentID;
}

void Student::SetFirstName(string firstName) {
	this->firstName = firstName;
}

void Student::SetLastName(string lastName) {
	this->lastName = lastName;
}

void Student::SetEmailAddress(string emailAddress) {
	this->emailAddress = emailAddress;
}

void Student::SetAge(int age) {
	this->age = age;
}

void Student::SetDaysInCourse(int* daysInCourse) {
	this->daysInCourse[0] = daysInCourse[0];
	this->daysInCourse[1] = daysInCourse[1];
	this->daysInCourse[2] = daysInCourse[2];
}

void Student::SetDegreeProgram(DegreeProgram degreeProgram) {
	this->degreeProgram = degreeProgram;
}

string Student::GetStudentID() const {
	return studentID;
}

string Student::GetFirstName() const {
	return firstName;
}

string Student::GetLastName() const {
	return lastName;
}

string Student::GetEmailAddress() const {
	return emailAddress;
}

int Student::GetAge() const {
	return age;
}

int* Student::GetDaysInCourse()
{
	return daysInCourse;
}

DegreeProgram Student::GetDegreeProgram() const {
	return degreeProgram;
}
