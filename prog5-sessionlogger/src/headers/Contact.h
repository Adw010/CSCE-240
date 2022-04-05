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
	void getPortion(std::string line);
	void getWhole(std::string line);
	void getPart(std::string line);
	void selectPortion(std::string line);
	virtual ~Contact();

	std::string contin;
	std::string user;
	std::string line;
	std::string messages;
	std::string messagestwo;
	std::string cpumessage = "CPU : ";
    std::string usermessage = "User : ";
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
