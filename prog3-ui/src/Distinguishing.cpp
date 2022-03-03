#include "./Distinguishing.h"
#include "./Contact.cpp"
#include "./Committee.cpp"
#include "./Sponsored.cpp"
#include "./Service.cpp"
#include "./Voting.cpp"
#include "./Personal.cpp"
#include <stdio.h>
#include <stdlib.h>
#include <regex>
#include <string>
#include <fstream>
#include <iostream>
using namespace std;

Distinguishing ::~Distinguishing(){};

Distinguishing ::Distinguishing()
{
	inputfile = "../../prog3-ui/Data/district";
};


void Distinguishing ::getType(string typing)
{
	cout << "Hello, would you like to start looking at the data? Yes to continue." << endl;
	cout << "Throughout this process, you can say quit to stop." << endl;
	cin >> contin;
	contin = toLower(contin);
	if (contin == "yes")
	{
		cout << "OK, we will continue." << endl;
	}
	else if (contin == "quit" || contin == "q")
	{
		cout << "OK, we will stop." << endl;
		exit(EXIT_FAILURE);
	}
	else
	{
		cout << "Sorry, we will restart then." << endl;
		cout << " " << endl;
		getType(contin);
	}
	cout << "Would you like to look at the whole document or just a part?" << endl;
	cin >> typing;
	typing = toLower(typing);
	if (typing == "whole")
	{
		printWholeFile();
	}
	else if (typing == "part")
	{
		getTopic();
	}
	else
	{
		error();
	}
};

void Distinguishing :: getTopic(){
	cout << "Would you like to see Contact, Committee, Service, Voting, Sponsored or Personal?" << endl;
	cout << "You can also say nvm or Nevermind to go back to start." << endl;
	cin >> topic;
	topic = toLower(topic);
	if (topic == "nvm" || topic == "nevermind") {
		getType(topic);
	}
	else if (topic == "contact"){

		cout << "You chose Contact." << endl;
		Contact a;
		a.selectPortion();
	}
	else if (topic == "committee"){

		cout << "You chose Committee." << endl;
		Committee b;
		b.selectPortion();
	}
	else if (topic == "sponsored"){

		cout << "You chose Sponsored." << endl;
		Sponsored c;
		c.selectPortion();		
	}
	else if (topic == "voting"){

		cout << "You chose Voting." << endl;
		Voting d;
		d.selectPortion();
	}
	else if (topic == "service"){

		cout << "You chose Service." << endl;
		Service e;
		e.selectPortion();
	}
	else if (topic == "personal"){

		cout << "You chose Personal." << endl;
		Personal f;
		f.selectPortion();
	}
	else if (topic == "q" || topic == "quit"){
		exit(EXIT_FAILURE);
	}
	else{
		cout << "Bad choice, please select again." << endl;
		getTopic();
	}
}

void Distinguishing ::printWholeFile()
{
	inputfile = "../../prog3-ui/Data/district";
	cout << "Please provide the district number. " << endl;
	cin >> district;
	district = toLower(district);
	inputfile += district;
	inputfile += extension;

	ifstream inFile;
	inFile.open(inputfile);
	if (inFile.fail())
	{
		cout << "No file to open or couldn't open. Please restart" << endl;
		printWholeFile();
	}
	else if (district == "quit" || district == "q")
	{
		exit(EXIT_FAILURE);
	}
	else
	{
		while (getline(inFile, newLine))
		{
			if (newLine.empty())
			{
				continue; // sends back if line is empty
			}
			else
			{
				stringstream series(newLine);
				while (series >> words)
				{
					if (holder == newLine)
					{
						continue;
					}
					else
					{
						std::cout << newLine << endl;
						holder = newLine;
					}
				}
			}
		}
	}
	
	inFile.close();
	cout << "Action complete. Do you want to exit? Otherwise, I will send you to the main screen." << endl;
	cin >> contin;
	contin = toLower(contin);
	if (contin == "yes" || contin == "quit" || contin == "sure" || contin == "ok" || contin == "q")
	{
		exit(EXIT_FAILURE);
	}
	else
	{
		getType(contin);
	}
}

string Distinguishing::toLower(string input)
{

	for_each(input.begin(), input.end(), [](char &c)
			 { c = ::tolower(c); });

	return input;
}

void Distinguishing ::error()
{

	cout << "You have encountered an error. Going back to the start." << endl;
	cout << "Would you like to quit or reset?" << endl;
	cin >> contin;
	contin = toLower(contin);
	while (errorSelection != true)
	{
		if (contin == "quit" || contin == "q")
		{
			cout << "Program now ending" << endl;
			exit(EXIT_FAILURE);
		}
		else if (contin == "reset")
		{
			getType(contin);
		}
		else
		{
			error();
		}
	}
}

void Distinguishing::loop(){
	Freeform y;
	y.question();
}
