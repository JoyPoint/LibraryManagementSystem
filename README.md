# LibraryManagementSystem
Program is a library management system that inputs data from a text file and loads that data into a vector. Book data or student data can be modified, added or deleted. Program allows student to check out 1 book at a time and tracks if a particular book is checked in or out. The program also allows the student to return their book and updates the status of that book so another student can check it out. Lastly, the program allows the user to save the book data and student data to a text file.

Below are some specifics and improvements I could make on the classes source files, golbal variables and a few particular functions:

GlobalVariables.h- Although global variables should be avoided I needed to access a database across several classes. Since this was the case I thought it was reasonable to use global variables for the vectors of my student and book databases. To improve this and not use global variables I could use smart pointers to access the data across several classes.

Book.cpp and Student.cpp - I used vectors which are sequential containers to store the book data in. In several functions I search for the book number and student numberwhich take O(n) time complexity. This time complexity could be reduced to O(1) by using associative containers.

Book.h and Student.h- could use setters to access private member variables. 

InputBook.cpp and InputStudent.cpp- Input book data from text file using ifstream and istringstream then add each string to the global vector. Right now can only read in one word at a time- when it hits space goes to next variable. Should make compatable to csv files.

issueBook() function- student can have 1 book out at a time. Checks to make sure book isnt already checked out. After student checks out book updates both student info and book status so another student can not check it out. time complexity is O(n^2) which would be improved if we were using associative coontainers.

depositBook() function- updates students info and checks book in. time complexity is O(n^2) which would be improved if we were using associative coontainers.

saveBookData() and saveStudentData functions- saves data base vectors to text files. COuld improve by making them save csv files.
