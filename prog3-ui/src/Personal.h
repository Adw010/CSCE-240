#ifndef PERSONAL_H_
#define PERSONAL_H_

#include "./Distinguishing.h"
#include <string>
#include <regex>
#include <iostream>
#include <fstream>

class Personal{
public:
	Personal();//default
	
	std::string toLower(std::string inputfile);
	void getPortion();
	void getWhole();
	void getPart();
	void selectPortion();
	virtual ~Personal();

	std::string contin;
	std::string district;
	std::string newLine;
	std::string words;
	std::string holder;
	std::string topic;
	std::string section;
	std::string inputfile;
	std::string extension = ".txt";
	int partnum= 0;
	bool errorSelection = false;
	bool whole = false;
	bool part = false;
	bool partEnd = false;
    bool parting = false;
};




#endif 
