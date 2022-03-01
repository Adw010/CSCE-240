/*
 * OutlookHeaderType.h
 *
 *  Created on: Feb 27, 2022
 *      Author: Aweso
 */

#ifndef OUTLOOKHEADERTYPE_H_
#define OUTLOOKHEADERTYPE_H_

#include <string>
#include <iostream>
#include "./BaseEmailHeaderType.h"

class OutlookHeaderType{
public:
	OutlookHeaderType();
	~OutlookHeaderType();
	void getThread(std::string inputfile);
	void MS_Exchange(std::string inputfile);
	void MS_Attach(std::string inputfile);
	void language(std::string inputfile);
	void authenication(std::string inputfile);
};



#endif 
