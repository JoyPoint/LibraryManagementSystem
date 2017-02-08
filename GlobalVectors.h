#pragma once

#ifndef GLOBALVECTORS_H
#define GLOBALVECTORS_H

#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>
#include "Book.h"
#include "Student.h"

//Global Variables are used to store data uploaded from text files into vectors

extern std::vector<Book> g_bookDataBase;

extern std::vector<Student> g_studentDataBase;


#endif // !GLOBALVECTORS_H
