/*
 * GmailHeaderType.h
 *
 *  Created on: Feb 27, 2022
 *      Author: Aweso
 */

#ifndef GMAILHEADERTYPE_H_
#define GMAILHEADERTYPE_H_

#include <iostream>
#include <string>
#include "./BaseEmailHeaderType.h"

class GmailHeaderType{
public:
	GmailHeaderType();
	~GmailHeaderType();
	void getTo(std::string inputfile);
	void deliverTo(std::string inputfile);
	void encoding(std::string inputfile);
	void replyTo(std::string inputfile);
	void getsource(std::string inputfile);
	void mime(std::string inputfile);
};



#endif /* GMAILHEADERTYPE_H_ */
