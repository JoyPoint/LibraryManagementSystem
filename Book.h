#pragma once

//Book Header

#ifndef BOOK_H
#define BOOK_H

#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>
#include "InputBook.h"

class Book
{
	//rather than making deleteBook a friend could use setters 
	friend void deleteBook(std::vector<Book>&);	
	friend InputBook::InputBook(std::ifstream&); 
	friend void saveBookData();

private:
	std::string m_bookNo;
	std::string m_bookName;
	std::string m_authorName;
	std::string m_bookStatus = "in";

public:
	/* Constructors*/
	Book() : m_bookNo(" "), m_bookName(" "), m_authorName(" "), m_bookStatus("in") { }
	Book(const std::string &bookNo, const std::string &bookName, const std::string &authorName) :
		m_bookNo(bookNo), m_bookName(bookName), m_authorName(authorName) { }
	

/*member functions that are implictily inline below- "Getters"*/
	std::string retBookNo() const { return m_bookNo; }
	std::string retAuthorName() const { return m_authorName; }
	std::string retBookName() const { return m_bookName; }
	std::string retBookStatus() const { return m_bookStatus; }

	/*member function declarations*/
	//create new Book
	void newBook();
	//will show Books info 
	void showBook() const;
	//modify Book info
	void modifyB();
	//change book status to in
	void bookStatusIn();
	//change book status to out
	void bookStatusOut();

};

/*Non Member Interface Functions*/
void writeBook(std::vector<Book>&);
void modifyBook(std::vector<Book>&);
void displayBook(std::vector<Book>&);
void displayAllBooks(std::vector<Book>&);
void deleteBook(std::vector<Book>&);



#endif // !BOOK_H
