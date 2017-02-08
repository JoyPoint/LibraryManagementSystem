#pragma once

#ifndef INPUTSTUDENT_H
#define INPUTSTUDENT_H

#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <fstream>
#include <sstream>

class InputStudent
{
private:
	std::shared_ptr<std::vector<std::string>> file1;

public:
	/*constructor used to intialize input data and add to the vector*/
	InputStudent(std::ifstream&);	
};
