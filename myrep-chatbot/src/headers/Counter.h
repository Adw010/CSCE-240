#ifndef COUNTER_H_
#define COUNTER_H_

#include "./Category.h"
#include "./Chatsession.h"
#include <string>
#include <regex>
#include <iostream>
#include <fstream>

class Counter
{
public:
    Counter(); // default

    std::string toLower(std::string inputfile);
    std::string counter(std::string input, std::string comparision);
    virtual ~Counter();

    std::string selection;
    std::string messages;
	std::string messagestwo;
    std::string words;
    std::string str;
    float nummer;
    float denom;
    float total;
    float limit;
};

#endif
