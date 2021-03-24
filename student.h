#pragma once
#include <string>
#include "degree.h";
using namespace std;


class Student {
	public:
		Student();
		Student(
			string studentID,
			string firstName,
			string lastName,
			string emailAddress,
			int age,
			int daysInCourse[],
			DegreeProgram degreeProgram
		);

		void Print();

		void SetStudentID(string studentID);
		void SetFirstName(string firstName);
		void SetLastName(string lastName);
		void SetEmailAddress(string emailAddress);
		void SetAge(int age);
		void SetDaysInCourse(int* daysInCourse);
		void SetDegreeProgram(DegreeProgram degreeProgram);

		string GetStudentID() const;
		string GetFirstName() const;
		string GetLastName() const;
		string GetEmailAddress() const;
		int GetAge() const;
		int* GetDaysInCourse();
		DegreeProgram GetDegreeProgram() const;

	private:
		string studentID;
		string firstName;
		string lastName;
		string emailAddress;
		int age;
		int daysInCourse[3];
		DegreeProgram degreeProgram;
		string degreeProgramStrings[3] = { "SECURITY", "NETWORK", "SOFTWARE" };



};