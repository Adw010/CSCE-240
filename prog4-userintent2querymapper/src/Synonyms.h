#ifndef SYNONYMS_H_
#define SYNONYMS_H_

#include "./Freeform.h"
#include <string>
#include <regex>
#include <iostream>
#include <fstream>

class Synonyms{
public:
	Synonyms();//default
	
	std::string toLower(std::string inputfile);
	void freeForm();
    void question();
    void moving();
	virtual ~Synonyms();

    protected:
    std::string selection;
    std::string words;
    bool fail = false;
    bool stop = false;
    

	
};




#endif 
