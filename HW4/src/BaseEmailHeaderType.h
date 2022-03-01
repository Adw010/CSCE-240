/*
 * BaseEmailHeaderType.h
 *
 *  Created on: Feb 25, 2022
 *      Author: Aweso
 */

#ifndef BASEEMAILHEADERTYPE_H_
#define BASEEMAILHEADERTYPE_H_

#include <string>
#include <regex>
#include <iostream>
#include <fstream>

class BaseEmailHeaderType{
public:
	BaseEmailHeaderType();//default
	~BaseEmailHeaderType();
	std::string readInputFile(std::string inputfile);
	void getHeader(std::string inputfile);
	void getReceived(std::string inputfile);
	void getDate(std::string inputfile);
	void getSubject(std::string inputfile);
	void getContentType(std::string inputfile);
	void getTo(std::string inputfile);
	void getFrom(std::string inputfile);
	void getCC(std::string inputfile);
	void getMessage(std::string inputfile);
};




#endif 
