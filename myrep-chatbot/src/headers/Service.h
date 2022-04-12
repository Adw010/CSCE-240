#ifndef SERVICE_H_
#define SERVICE_H_

#include "./Distinguishing.h"
#include "./Category.h"
#include <string>
#include <regex>
#include <iostream>
#include <fstream>

class Service{
public:
	Service();//default
	
	std::string toLower(std::string inputfile);
	void getPortion(std::string line);
	void getWhole(std::string line);
	void getPart(std::string line);
	void selectPortion(std::string line);
	virtual ~Service();

	std::string contin;
	std::string district;
	std::string user;
	std::string messages;
	std::string messagestwo;
	std::string cpumessage = "CPU : ";
    std::string usermessage = "User : ";
	std::string line;
	std::string newLine;
	std::string words;
	std::string holder;
	std::string topic;
	std::string section = "Service In Public Office";
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
