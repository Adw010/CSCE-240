#ifndef CHATSESSION_H_
#define CHATSESSION_H_

#include "./Distinguishing.h"
#include <string>
#include <regex>
#include <iostream>
#include <fstream>
#include <chrono>

class Chatsession{
public:
	Chatsession();//default
	
	void noteOutput(std::string type, std::string str);
	void timeStart();
	void timeEnd(std::string file);
    void counter(std::string file);
	void summary();
	void printer(std::string file);
	virtual ~Chatsession();

	std::chrono::_V2::steady_clock::time_point start = std::chrono::steady_clock::now();
    std::string path;
    std::string str;
	std::string newLine;
	std::string holder;
	std::string words;
	std::string checking;
    int inputnum = 0;
	int outputnum= 0;
	int inputnumto = 0;
	int outputnumto= 0;
	bool open = false;

};




#endif 
