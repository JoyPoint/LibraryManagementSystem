// Library Management System
//By: Joe Grazewski
// February 7, 2017

#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>
#include "Book.h"
#include "Student.h"
#include "InputBook.h"
#include "GlobalVectors.h"



//***Add interface functions that work with both headers or global variables***
void adminMenu();
void issueBook();
void depositBook();
void saveBookData(); 
void saveStudentData();


int main()
{


	std::ifstream inBookFile;
	inBookFile.open("BookTest.txt");
	InputBook one{ inBookFile };

	std::ifstream inStudentFIle;
	inStudentFIle.open("StudentTest.txt");
	InputStudent two{ inStudentFIle };


	char selection;

	std::cout << "Library Management System";
	std::cout << "\nCreated By: Joe Grazewski";
	std::cout << "\nNashua High School South Library";

	do
	{
		std::cout << "\n\tMain Menu";
		std::cout << "\n\t01. Book Issue";
		std::cout << "\n\t02. Book Deposit";
		std::cout << "\n\t03. Admin Menu";
		std::cout << "\n\t04. Save";
		std::cout << "\n\t05. Exit\n";
		std::cin >> selection;
		std::cin.ignore();

		switch (selection)
		{
		case '1':
			issueBook();
			break;
		case '2':
			depositBook();
			break;
		case '3':
			adminMenu();
			break;
		case '4':	//WHEN SAVING BOOK AN EXTRA IN IS PRINTED; either b/c status of book changed or b/c in is printed when new book is created. Check this with student too
			saveBookData();
			saveStudentData();
			std::cout << "Student data and Book data has been saved." << std::endl;
			break;
		case '5':
			std::cout << "Thank you for using the Library Managment System!" << std::endl;
			break;
		}
	} while (selection != '5');

	return 0;
}


void adminMenu()
{
	char selection2;
	std::cout << "\n\tAdmin Menu";
	std::cout << "\n\t01. Create Student Record";
	std::cout << "\n\t02. Display All STudent Records";
	std::cout << "\n\t03. Display a Specific Student Record";
	std::cout << "\n\t04. Modify Student Record";
	std::cout << "\n\t05. Delete Student Record";
	std::cout << "\n\t06. Add New Book";
	std::cout << "\n\t07. Display All Books";
	std::cout << "\n\t08. Display Specific Book";
	std::cout << "\n\t09. Modify Book";
	std::cout << "\n\ta. Delete Book";
	std::cout << "\n\tb. Back to Main Menu\n";
	std::cin >> selection2;
	std::cin.ignore();

	switch (selection2)
	{
	case '1':
		writeStudent(g_studentDataBase);
		break;
	case '2':
		displayAllStudents(g_studentDataBase);
		break;
	case '3':
		displayStudent(g_studentDataBase);
		break;
	case '4':
		modifyStudent(g_studentDataBase);
		break;
	case '5':
		deleteStudent(g_studentDataBase);
		break;
	case '6':
		writeBook(g_bookDataBase);
		break;
	case '7':
		displayAllBooks(g_bookDataBase);
		break;
	case '8':
		displayBook(g_bookDataBase);
		break;
	case '9':
		modifyBook(g_bookDataBase);
		break;
	case 'a':
		deleteBook(g_bookDataBase);
		break;
	case 'b':
		return;
	default:
		return;

	}
}

/*Issues book to student; student can only have one book out at a time; checks to make sure book
is not already checked out; updates book status to be checked out */
void issueBook()
{
	std::cout << "\n\t***Book Issue***" << std::endl;

	//flag for student; once student number found will go to true
	bool flag = false;	
	//flag for book; once book number found will go to true
	bool flag2 = false;	
	std::string no;
	std::cout << "Enter the students number: " << std::endl;
	std::getline(std::cin, no);

	for (int i = 0; i != g_studentDataBase.size(); ++i)
		if (g_studentDataBase[i].retStudentNo() == no)
		{
			flag = true;

			if (g_studentDataBase[i].retBookOut() == 0)
			{
				std::string bno;
				std::cout << "Enter the book number the student would like to check out: " << std::endl;
				std::getline(std::cin, bno);

				for (int j = 0; j != g_bookDataBase.size(); ++j)
					if (g_bookDataBase[j].retBookNo() == bno)
					{
						flag2 = true;

						if (g_bookDataBase[j].retBookStatus() == "in")
						{
							//update book number that student has checked out
							g_studentDataBase[i].updateStudentBookNo(g_bookDataBase[j].retBookNo());	
							//mark that student has checked out their one allowed book
							g_studentDataBase[i].bookCheckOut();
							//mark that the book has been checked out so no other student can check out
							g_bookDataBase[j].bookStatusOut(); 
							std::cout << "The book has been checked out." << std::endl;
							break;
						}
						else
							std::cout << "The book is already checked out." << std::endl;
					}
				if (flag2 == false)
					std::cout << "The book you entered is invalid." << std::endl;
				break;	
			}
			else
				std::cout << "Last book is not returned." << std::endl;


		}
	if (flag == false)
		std::cout << "The student you entered is invalid." << std::endl;

}
/*Allows student to return book; updates student info for book check in; checks the book back in*/
void depositBook()
{
	std::cout << "\n\t***Book Deposit***" << std::endl;

	//flag for student; once student number found will go to true
	bool flag = false;	
	//flag for book; once book number found will go to true
	bool flag2 = false;	

	std::string no;
	std::cout << "Enter the students number: " << std::endl;
	std::getline(std::cin, no);

	for (int i = 0; i != g_studentDataBase.size(); ++i)
		if (g_studentDataBase[i].retStudentNo() == no)
		{
			flag = true;

			if (g_studentDataBase[i].retBookOut() == 1)
			{
				std::string bno;
				std::cout << "Enter the book number the student would like to return: " << std::endl;
				std::getline(std::cin, bno);
				for (int j = 0; j != g_bookDataBase.size(); ++j)
					
					//if only did first conditional if statement would run even if wrong bno is entered
					if (g_studentDataBase[i].retStudentBookNo() == g_bookDataBase[j].retBookNo()
						&& g_studentDataBase[i].retStudentBookNo() == bno)
					{
						flag2 = true;
						//update the book number that student has out
						g_studentDataBase[i].updateStudentBookNo("0");
						//update number of books student has checked out which is 0
						g_studentDataBase[i].bookCheckIn();
						//update status of book to checked in so another student can check out
						g_bookDataBase[j].bookStatusIn();

						std::cout << "The book has been returned." << std::endl;
						break;
					}
				if (flag2 == false)
					std::cout << "The book you entered is invalid." << std::endl;
				break;	
			}
			else
				std::cout << "Student does not have a book checked out." << std::endl;


		}
	if (flag == false)
		std::cout << "The student you entered is invalid." << std::endl;
}

/*Using ofstream saves bookDataBase vector to text file*/
void saveBookData()
{
	std::ofstream outBookFile;
	outBookFile.open("BookDataBase.txt"); //bookDataBase.txt will be created automatically

	for (int i = 0; i != g_bookDataBase.size(); ++i)
	{
		outBookFile << g_bookDataBase[i].m_bookNo << " " << g_bookDataBase[i].m_bookName << " " <<
			g_bookDataBase[i].m_authorName << " " << g_bookDataBase[i].m_bookStatus << std::endl;
	}
}

/*Using ofstream saves studentDataBase vector to text file*/
void saveStudentData()
{
	std::ofstream outStudentFile;
	outStudentFile.open("StudentDataBase.txt");

	for (int i = 0; i != g_studentDataBase.size(); ++i)
	{
		outStudentFile << g_studentDataBase[i].m_studentNo << " " << g_studentDataBase[i].m_studentName
			<< " " << g_studentDataBase[i].m_booksOut << " " << g_studentDataBase[i].m_studentBookNo
			<< std::endl;
	}
}
