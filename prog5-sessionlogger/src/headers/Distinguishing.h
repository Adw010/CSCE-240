#ifndef DISTINGUISHING_H_
#define DISTINGUISHING_H_

#include "./Freeform.h"
#include "./Category.h"
#include "./Chatsession.h"
#include <string>
#include <regex>
#include <iostream>
#include <fstream>


class Distinguishing{
public:
	Distinguishing();//default
	void getType(std::string type);
	void error(std::string file);
	void quit();
	std::string toLower(std::string input);
	void getWhole(std::string type);
	void printWholeFile(std::string type);
	void printWholeSection(std::string type);
	void printSection(std::string type);
	void getTopic(std::string type);
	void loop(std::string type);
	virtual ~Distinguishing();

	protected:

	std::string contin;
	std::string typing;
	std::string user;
	std::string district;
	std::string newLine;
	std::string words;
	std::string holder;
	std::string topic;
	std::string inputfile;
	std::string extension = ".txt";
	std::string messages;
	std::string messagestwo;
	std::string cpumessage = "CPU : ";
    std::string usermessage = "User : ";
	bool errorSelection = false;
	

};

#endif 
