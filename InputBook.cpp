#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <fstream>
#include <sstream>
#include "InputBook.h"
#include "Book.h"
#include "GlobalVectors.h"

/*Declared vector with extern in header- must be included*/
std::vector<Book> g_bookDataBase; 

/*Initialize input data and add to global vector of type Book objects*/
InputBook::InputBook(std::ifstream &is) : file(new std::vector<std::string>)
{
	std::string text;
	while (std::getline(is, text)) 
	{
		file->push_back(text);		
		std::istringstream inString(text);

		Book bookData;
		inString >> bookData.m_bookNo;
		inString >> bookData.m_bookName;
		inString >> bookData.m_authorName;
		inString >> bookData.m_bookStatus;


		g_bookDataBase.push_back(bookData); 

	}

}
