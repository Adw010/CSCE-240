#include "./Personal.h"
#include <regex>
#include <string>
#include <fstream>
#include <iostream>
using namespace std;

Personal ::~Personal(){};

Personal ::Personal()
{
	selectPortion();
}

void Personal::selectPortion()
{
	section += "\n";
	cout << "Would you like to print the whole Personal section or are you looking for something in particular?" << endl;
	cout << "You can say whole or part." << endl;
	cin >> topic;
	topic = toLower(topic);
	Category c;
	topic = c.cat(topic);
	if (topic == "whole")
	{
		getWhole();
	}
	else if (topic == "quit" || topic == "q")
	{
		exit(EXIT_FAILURE);
	}
	else if (topic == "part")
	{
		getPart();
	}
	else
	{
		cout << "You have encountered an error. We will send you back." << endl;
		selectPortion();
	}
}

void Personal::getPart()
{
	inputfile = "../../prog4-userintent2querymapper/Data/district";
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
		getPart();
	}
	else if (district == "quit" || district == "q")
	{
		exit(EXIT_FAILURE);
	}
	else
	{
		while (getline(inFile, newLine))
		{ // gets lines
			if (newLine.empty())
			{
				continue; // sends back if line is empty
			}
			else
			{
				stringstream series(newLine);
				while (series >> words)
				{ // takes in line as string
					if (partEnd != true)
					{
						if (holder == newLine)
						{
							continue;
						}
						else if (words == "Personal")
						{
							parting = true;
						}
						else if (newLine == "END")
						{
							partEnd = true;
							continue;
						}
						else
						{
							if (parting != true)
							{
								holder = newLine;
							}
							else
							{
								section += newLine;
								section += "\n";
								holder = newLine;
							}
						}
					}
					else
					{
						continue;
					}
				}
			}
		}
	}
	getPortion();
	inFile.close();
}

void Personal::getPortion()
{
	std::cout << "What category in Personal would you like to see: " << endl;
	std::cout << "Type parents, birth, marriage, children, or fraternity." << endl;
	cin >> topic;
	topic = toLower(topic);
	Category c;
	topic = c.cat(topic);
	if (topic == "parents")
	{
		regex searchFile("\\w+(?=.*late)[\a-zA-Z]*?[\r\n]");
		smatch matching;
		if (regex_search(section, matching, searchFile))
		{
			for (auto find : matching)
			{
				cout << find << endl;
			}
		}
	}
	else if (topic == "birth")
	{
		regex searchFile("Born [\a-zA-Z]*?[\r\n]");
		smatch matching;
		if (regex_search(section, matching, searchFile))
		{
			for (auto find : matching)
			{
				cout << "The birth information is: " << find << endl;
			}
		}
	}
	else if (topic == "marriage")
	{
		regex searchFile("Marr[\a-zA-Z]+?[,]");
		smatch matching;
		if (regex_search(section, matching, searchFile))
		{
			for (auto find : matching)
			{
				cout << find << endl;
			}
		}
	}
	else if (topic == "children")
	{
		regex searchFile("\\w+(?=\\s+children)[\a-zA-Z]*?[\r\n]");
		smatch matching;
		if (regex_search(section, matching, searchFile))
		{
			for (auto find : matching)
			{
				cout << "The business address is: " << find << endl;
			}
		}
	}
	else if (topic == "fraternity")
	{
		regex searchFile("\\w+(?=.*Frat)[\a-zA-Z]*?[\r\n]");
		smatch matching;
		if (regex_search(section, matching, searchFile))
		{
			for (auto find : matching)
			{
				cout << "The home phone is: " << find << endl;
			}
		}
	}
	else if (topic == "quit" || topic == "q")
	{
		exit(EXIT_FAILURE);
	}
	else
	{
		std::cout << "Error, please start again." << endl;
		getPortion();
	}
	cout << "Action complete. Do you want to exit? Otherwise, I will send you to the main screen." << endl;
	cin >> contin;
	contin = toLower(contin);
	contin = c.cat(contin);
	if (contin == "yes" || contin == "quit" || contin == "sure" || contin == "ok" || contin == "q")
	{
		exit(EXIT_FAILURE);
	}
	else
	{
		Distinguishing m;
		m.getType(contin);
	}
}
void Personal::getWhole()
{
	inputfile = "../../prog4-userintent2querymapper/Data/district";
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
		getWhole();
	}
	else if (district == "quit" || district == "q")
	{
		exit(EXIT_FAILURE);
	}
	else
	{
		while (getline(inFile, newLine))
		{ // gets lines
			if (newLine.empty())
			{
				continue; // sends back if line is empty
			}
			else
			{
				stringstream series(newLine);
				while (series >> words)
				{ // takes in line as string
					if (partEnd != true)
					{
						if (holder == newLine)
						{
							continue;
						}
						else if (words == "Personal")
						{
							parting = true;
						}
						else if (newLine == "END")
						{
							partEnd = true;
							continue;
						}
						else
						{
							if (parting != true)
							{
								holder = newLine;
							}
							else
							{
								section += newLine;
								section += "\n";
								holder = newLine;
							}
						}
					}
					else
					{
						continue;
					}
				}
			}
		}
		cout << section << endl;
	}
	inFile.close();
	cout << "Action complete. Do you want to exit? Otherwise, I will send you to the main screen." << endl;
	cin >> contin;
	contin = toLower(contin);
	Category c;
	contin = c.cat(contin);
	if (contin == "yes" || contin == "quit" || contin == "sure" || contin == "ok" || contin == "q")
	{
		exit(EXIT_FAILURE);
	}
	else
	{
		Distinguishing m;
		m.getType(contin);
	}
}

std::string Personal::toLower(string input)
{
	for_each(input.begin(), input.end(), [](char &c)
			 { c = ::tolower(c); });
	return input;
}