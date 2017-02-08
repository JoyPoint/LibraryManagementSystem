#pragma once

#ifndef INPUTBOOK_H
#define INPUTBOOK_H

#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <fstream>
#include <sstream>

class InputBook
{
private:
	std::shared_ptr<std::vector<std::string>> file;	

public:
	/*Constructor used initialize input file and add data to vector*/
	InputBook(std::ifstream&);	
	
};
