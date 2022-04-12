#ifndef FREEFORM_H_
#define FREEFORM_H_

#include "./Distinguishing.h"
#include "./Category.h"
#include "./Chatsession.h"
#include <string>
#include <regex>
#include <iostream>
#include <fstream>

class Freeform{
public:
	Freeform();//default	
	std::string toLower(std::string inputfile);
	void freeForm(std::string str);
    void question(std::string str);
    void moving(std::string str);
	virtual ~Freeform();

    protected:
    std::string holder;
    std::string user;
    std::string selection;
    std::string words;
    std::string messages;
	std::string messagestwo;
    std::string messagesthree;
	std::string cpumessage = "CPU : ";
    std::string usermessage = "User : ";
    bool fail = false;
    bool stop = false;
    

	
};




#endif 
