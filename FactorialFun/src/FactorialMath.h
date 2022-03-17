#ifndef FACTORIALMATH_H_
#define FACTORIALMATH_H_

#include <string>
#include <regex>
#include <iostream>
#include <fstream>

class FactorialMath{
public:
	FactorialMath();//default
	
	std::string toLower(std::string inputfile);
	void math(long long numberenter);
	long long factorial(long long numberenter);
	long long combinational(long long numberenter, long long number);
	virtual ~FactorialMath();

	long long number= 0;
    long long numberenter = 0;
};




#endif 
