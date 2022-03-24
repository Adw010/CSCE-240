#ifndef CONTACT_H_
#define CONTACT_H_

#include "./Distinguishing.h"
#include "./Category.h"
#include <string>
#include <regex>
#include <iostream>
#include <fstream>

class Contact{
public:
	Contact();//default
	
	std::string toLower(std::string inputfile);
	void getPortion();
	void getWhole();
	void getPart();
	void selectPortion();
	virtual ~Contact();

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
};




#endif 
