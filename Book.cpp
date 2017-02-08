#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>
#include "Book.h"

/*Allows user to create new book*/
void Book::newBook()     
{
	std::cout << "**New Book Entry**\n";		
	std::cout << "Enter a book number:\n";	
	std::getline(std::cin, m_bookNo);
	std::cout << "Enter a book name:\n";
	std::getline(std::cin, m_bookName);
	std::cout << "Enter author:\n";
	std::getline(std::cin, m_authorName);
	std::cout << "Thank you, the new book was created!" << std::endl;
}

/*Shows a books info*/
void Book::showBook() const
{
	std::cout << "Book Number: " << m_bookNo << '\n';
	std::cout << "Book Name: " << m_bookName << '\n';
	std::cout << "Author: " << m_authorName << '\n';
	std::cout << std::endl;
}

/*Prompts user for book number that they would like to modify*/
void Book::modifyB()
{
	std::cout << "You are about to modify book number: " << m_bookNo << '\n';
	std::cout << "Enter the modified book name:\n";
	std::getline(std::cin, m_bookName);
	std::cout << "Enter the modifed author:\n";
	std::getline(std::cin, m_authorName);
}

void Book::bookStatusIn()
{
	m_bookStatus = "in";
}

void Book::bookStatusOut()
{
	m_bookStatus = "out";
}

/*Write book to a vector which is our database*/
void writeBook(std::vector<Book>& newlyBook)
{
	Book title;
	title.newBook();
	newlyBook.push_back(title);
}

/*Function that calls member function modify to allow user to modify book*/
void modifyBook(std::vector<Book>& newlyBook)
{
	std::string number;
	bool flag = false;
	std::cout << "What is the book number of the book that you would like to modify?" << std::endl;
	std::getline(std::cin, number);
	for (int i = 0; i != newlyBook.size(); ++i)
		if (newlyBook[i].retBookNo() == number)
		{
			newlyBook[i].modifyB();
			flag = true;
			break;
		}

	if (flag == false)
		std::cout << "The book number you entered is invalid." << std::endl;
}

/*Function that calls member function showBook() and allows user to display a books info*/
void displayBook(std::vector<Book> &newlyBook)
{
	std::string name;
	bool flag = false;
	std::cout << "What is the name of the book that you would like to display?" << std::endl;
	std::getline(std::cin, name);
	for (int i = 0; i != newlyBook.size(); ++i)
		if (newlyBook[i].retBookName() == name)
		{
			newlyBook[i].showBook();
			flag = true;
			break;
		}
	if (flag == false)
		std::cout << "The library does not have that book in the system." << std::endl;
}

/*Display all books by calling member function showBook()*/
void displayAllBooks(std::vector<Book>& newlyBook)
{
	for (int i = 0; i != newlyBook.size(); ++i)
	{
		newlyBook[i].showBook();
	}
}

/*Allows user to remove a book. Rather than remove element completely because that
invalidates all iterators, references and pointers element will just set to a default value.*/
void deleteBook(std::vector<Book>& newlyBook)
{
	std::string number;
	bool flag = false;
	std::cout << "What is the book number that you would like to remove?" << std::endl;
	std::getline(std::cin, number);
	for (int i = 0; i != newlyBook.size(); ++i)
		if (newlyBook[i].retBookNo() == number)
		{
			newlyBook[i].m_bookName = "Book was deleted";
			newlyBook[i].m_authorName = "Book was deleted";
			flag = true;
			break;
		}
	if (flag == false)
		std::cout << "The book number that you entered is invalid." << std::endl;

}
