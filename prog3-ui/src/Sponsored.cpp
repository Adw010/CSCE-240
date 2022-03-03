#include "./Sponsored.h"
#include <regex>
#include <string>
#include <fstream>
#include <iostream>
using namespace std;

Sponsored ::~Sponsored(){};

Sponsored ::Sponsored()
{
	selectPortion();
}

void Sponsored::selectPortion()
{
    section += "\n";
	cout << "Would you like to print the whole Sponsored section or are you looking for something in particular?" << endl;
	cout << "You can say whole or part." << endl;
	cin >> topic;
	topic = toLower(topic);
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

void Sponsored::getPart()
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
						else if (newLine == "Sponsored Bills in the House"){
                            parting = true;
                        }
						else if (newLine == "Voting Record")
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
	cout << "As this is a dynamic category, we will only print the whole thing." << endl;
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
		Distinguishing m;
		m.getType(contin);
	}
}


void Sponsored::getWhole()
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
                        else if (newLine == "Sponsored Bills in the House"){
                            parting = true;
                        }
						else if (newLine == "Voting Record")
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

std::string Sponsored::toLower(string input)
{
	for_each(input.begin(), input.end(), [](char &c)
			 { c = ::tolower(c); });
	return input;
}