#include "./Service.h"
#include <regex>
#include <string>
#include <fstream>
#include <iostream>
using namespace std;

Service ::~Service(){};

Service ::Service()
{
	selectPortion();
}

void Service::selectPortion()
{
    section += "\n";
	cout << "Would you like to print the whole Service section or are you looking for something in particular?" << endl;
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

void Service::getPart()
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
						else if (newLine == "Service In Public Office"){
                            parting = true;
                        }
						else if (words == "Personal")
						{
							partEnd = true;
							continue;
						}
						else
						{
                            if (parting != true) {
                                holder = newLine;
                            }
                            else{
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
	cout << section << endl;
	getPortion();
	inFile.close();
}

void Service::getPortion()
{
	std::cout << "What category in Service would you like to see: " << endl;
	std::cout << "Type house or council." << endl;
	cin >> topic;
	topic = toLower(topic);
	Category c;
	topic = c.cat(topic);
	if (topic == "house")
	{
		regex searchFile("House [\a-zA-Z_0-9]+?[\r\n]");
		smatch matching;
		if (regex_search(section, matching, searchFile))
		{
			for (auto find : matching)
			{
				cout << "The first Service is: " << find << endl;
			}
		}
	}
	else if (topic == "council")
	{
		regex searchFile("Florence [0-9]*[\a-zA-Z]*?[\r\n]");
		smatch matching;
		if (regex_search(section, matching, searchFile))
		{
			for (auto find : matching)
			{
				cout << "The second Service is: " << find << endl;
			}
		}
	}
	else if (topic == "quit" || topic == "q"){
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
void Service::getWhole()
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
                        else if (newLine == "Service In Public Office"){
                            parting = true;
                        }
						else if (words == "Personal")
						{
							partEnd = true;
							continue;
						}
						else
						{
                            if (parting != true) {
                                holder = newLine;
                            }
                            else{
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

std::string Service::toLower(string input)
{
	for_each(input.begin(), input.end(), [](char &c)
			 { c = ::tolower(c); });
	return input;
}