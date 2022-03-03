#ifndef FREEFORM_H_
#define FREEFORM_H_

#include "./Distinguishing.h"
#include <string>
#include <regex>
#include <iostream>
#include <fstream>

class Freeform{
public:
	Freeform();//default
	
	std::string toLower(std::string inputfile);
	void freeForm();
    void question();
    void moving();
	virtual ~Freeform();

    protected:
    std::string selection;
    std::string words;
    bool fail = false;
    bool stop = false;
    

	
};




#endif 
