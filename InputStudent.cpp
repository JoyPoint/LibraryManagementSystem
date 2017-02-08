#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <fstream>
#include <sstream>
#include "InputStudent.h"
#include "Student.h"
#include "GlobalVectors.h"

/* Declared vector with extern in GlobalVector header- must be included*/
std::vector<Student> g_studentDataBase; 

/*Initialize input data and add to global vector of type Student objects*/
InputStudent::InputStudent(std::ifstream &is) : file1(new std::vector<std::string>)
{
	std::string text1;

	while (std::getline(is, text1))	
	{

		file1->push_back(text1);		
		std::istringstream inString(text1);

		Student studentData;

		inString >> studentData.m_studentNo;
		inString >> studentData.m_studentName;
		inString >> studentData.m_booksOut;
		inString >> studentData.m_studentBookNo;

		g_studentDataBase.push_back(studentData);

	}
}
