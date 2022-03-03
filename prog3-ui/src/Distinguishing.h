#ifndef DISTINGUISHING_H_
#define DISTINGUISHING_H_

#include "./Freeform.h"
#include <string>
#include <regex>
#include <iostream>
#include <fstream>


class Distinguishing{
public:
	Distinguishing();//default
	void getType(std::string type);
	void error();
	void quit();
	std::string toLower(std::string input);
	void getWhole();
	void printWholeFile();
	void printWholeSection();
	void printSection();
	void getTopic();
	void loop();
	virtual ~Distinguishing();

	protected:
	std::string contin;
	std::string district;
	std::string newLine;
	std::string words;
	std::string holder;
	std::string topic;
	std::string inputfile;
	std::string extension = ".txt";
	bool errorSelection = false;
	

};

#endif 
