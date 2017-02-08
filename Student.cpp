#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>
#include "Student.h"

/*Allows user to create new student*/
void Student::newStudent()
{
	std::cout << "**New Student Entry**\n";
	std::cout << "Enter a student number:\n";
	std::getline(std::cin, m_studentNo);
	std::cout << "Enter the students name:\n";
	std::getline(std::cin, m_studentName);
	std::cout << "Student is added to System!" << std::endl;

}

/*Prompts user for student number then prints student number*/
void Student::studentInfo() const
{
	std::cout << "Student Number: " << m_studentNo << '\n';
	std::cout << "Student Name: " << m_studentName << '\n';
	std::cout << "Number of books checked out: " << m_booksOut << '\n';
	if (m_booksOut != 0)
		std::cout << "The book number of your checked out book is: " << m_studentBookNo << '\n';
	std::cout << std::endl;
}

/*Prompts user for student number and allows user to modify*/
void Student::modifyS()
{
	std::cout << "You are about to modify student number: " << m_studentNo << '\n';
	std::cout << "Please enter the modified students name:\n";
	std::getline(std::cin, m_studentName);
	std::cout << "Would you like to reset the books check out (yes or no)?\n";
	std::string choice;
	std::getline(std::cin, choice);
	if (choice == "yes")
	{
		m_booksOut = 0;
		m_studentBookNo = "0";
	}
	std::cout << "The student number has been modified.\n";
	std::cout << std::endl;

}

void Student::bookCheckOut()
{
	m_booksOut = 1;
}

void Student::bookCheckIn()
{
	m_booksOut = 0;
}

/*Write sudent to vector which is our database*/
void writeStudent(std::vector<Student>& newlyStudent)
{
	Student name;
	name.newStudent();
	newlyStudent.push_back(name);
}

/*Calls member function modify() to allow user to modify student*/
void modifyStudent(std::vector<Student>& newlyStudent)
{
	std::string num;
	bool flag = false;
	std::cout << "What student would you like to modify?" << std::endl;
	std::getline(std::cin, num);

	for (int i = 0; i != newlyStudent.size(); ++i)
		if (newlyStudent[i].retStudentNo() == num)
		{
			newlyStudent[i].modifyS();
			flag = true;
			break;
		}
	if (flag == false)
		std::cout << "You entered a invalid student number." << std::endl;

}

/*Allows user to remove a student. Rather than remove element completely because that
invalidates all iterators, references and pointers element will just set to a default value.*/
void deleteStudent(std::vector<Student>& newlyStudent)
{
	std::string s;
	bool flag = false;

	std::cout << "What is the students number that you would like to delete?" << std::endl;
	std::getline(std::cin, s);

	for (int i = 0; i != newlyStudent.size(); ++i)
		if (newlyStudent[i].retStudentNo() == s)
		{
			newlyStudent[i].m_studentName = "Student has been deleted";
			newlyStudent[i].bookCheckIn();
			newlyStudent[i].updateStudentBookNo("0");
			flag = true;
			break;
		}
	if (flag == false)
		std::cout << "The student number that you entered was invalid." << std::endl;
}

/*Calls member function student info on all students to display all*/
void displayAllStudents(std::vector<Student>& newlyStudent)
{
	for (int i = 0; i != newlyStudent.size(); ++i)
		newlyStudent[i].studentInfo();
}

/*Prompts user to enter student number, searches for a match and then displays*/
void displayStudent(std::vector<Student>& newlyStudent)
{
	std::string no;
	bool flag = false;
	std::cout << "Enter the students number that you would like to display: " << std::endl;
	std::getline(std::cin, no);

	for (int i = 0; i != newlyStudent.size(); ++i)
		if (no == newlyStudent[i].retStudentNo())
		{
			newlyStudent[i].studentInfo();
			flag = true;
		}
	if (flag == false)
		std::cout << "We do not have that student in our system" << std::endl;
}
