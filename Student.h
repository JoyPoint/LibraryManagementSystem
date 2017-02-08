#pragma once

//Student Header

#ifndef STUDENT_H
#define STUDENT_H

#include "stdafx.h"
#include <iostream>
#include <string>
#include "InputStudent.h"


class Student
{
	//rather than making deleteStudent a friend could use setters
	friend void deleteStudent(std::vector<Student>&);	
	friend InputStudent::InputStudent(std::ifstream&); 
	friend void saveStudentData();

private:
	std::string m_studentNo;
	std::string m_studentName;
	//student can only check out 1 book at a time
	unsigned m_booksOut = 0;			
	std::string m_studentBookNo = "0";

public:
	/*Constructors- */
	Student() : m_studentNo(" "), m_studentName(" "), m_booksOut(0), m_studentBookNo("0") { }
	Student(const std::string &studentNo, const std::string &studentName) :
		m_studentNo(studentNo), m_studentName(studentName) { }
	Student(const std::string &studentNo, const std::string &studentName, unsigned booksOut,
		const std::string &no) :
		m_studentNo(studentNo), m_studentName(studentName), m_booksOut(booksOut), m_studentBookNo(no) { }

	/*Member Functions that are implicitly inline below- "Getters"*/
	std::string retStudentNo() const { return m_studentNo; }
	std::string retStudentName() const { return m_studentName; }
	unsigned retBookOut() const { return m_booksOut; }
	std::string retStudentBookNo() const { return m_studentBookNo; }
	void updateStudentBookNo(std::string no) { m_studentBookNo = no; }

	/*Member function declarations are below*/
	//create a new student
	void newStudent();
	//Show students information
	void studentInfo() const;
	//modify students information
	void modifyS();
	//Student checks out book- make this a MAX OF 2
	void bookCheckOut();
	//Student checks in book
	void bookCheckIn();


};

/*Non Member Interface Functions*/
void writeStudent(std::vector<Student>&);
void modifyStudent(std::vector<Student>&);
void deleteStudent(std::vector<Student>&);
void displayAllStudents(std::vector<Student>&);
void displayStudent(std::vector<Student>&);



#endif // !STUDENT_H
