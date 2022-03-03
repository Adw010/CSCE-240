#include "./Contact.h"
#include <regex>
#include <string>
#include <fstream>
#include <iostream>
using namespace std;

Contact ::~Contact(){};

Contact ::Contact()
{
	selectPortion();
}

void Contact::selectPortion()
{
	cout << "Would you like to print the whole contact section or are you looking for something in particular?" << endl;
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

void Contact::getPart()
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
						else if (newLine == "Committee Assignments")
						{
							partEnd = true;
							continue;
						}
						else
						{
							section += newLine;
							section += "\n";
							holder = newLine;
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

void Contact::getPortion()
{
	std::cout << "What category in Contact would you like to see: " << endl;
	std::cout << "Type name, region, address, or phone." << endl;
	cin >> topic;
	topic = toLower(topic);
	if (topic == "name")
	{
		regex searchFile("Representative [\a-zA-Z_0-9]+?[\r\n]");
		smatch matching;
		if (regex_search(section, matching, searchFile))
		{
			for (auto find : matching)
			{
				cout << "The name is: " << find << endl;
			}
		}
	}
	else if (topic == "region")
	{
		regex searchFile("District [0-9]* [-] [\a-zA-Z]*?[\r\n]");
		smatch matching;
		if (regex_search(section, matching, searchFile))
		{
			for (auto find : matching)
			{
				cout << "The region is: " << find << endl;
			}
		}
	}
	else if (topic == "address")
	{
		cout << "Do you want Business or Home?" << endl;
		cin >> topic;
		topic = toLower(topic);
		if (topic == "home")
		{
			regex searchFile("Home Address [\a-zA-z]+ [0-9]{5}");
			smatch matching;
			if (regex_search(section, matching, searchFile))
			{
				for (auto find : matching)
				{
					cout << "The home address is: " << find << endl;
				}
			}
		}
		else if (topic == "business")
		{
			regex searchFile("Columbia Address[\r\n]+[\a-zA-Z]+Columbia [0-9]{5}");
			smatch matching;
			if (regex_search(section, matching, searchFile))
			{
				for (auto find : matching)
				{
					cout << "The business address is: " << find << endl;
				}
			}
		}
		else {
			cout << "There seems to be an error in your input. PLease try again." << endl;
			getPortion();
		}
	}
	else if (topic == "phone")
	{
		cout << "Do you want Business or Home?" << endl;
		cin >> topic;
		topic = toLower(topic);
		if (topic == "home")
		{
			regex searchFile("Home Phone [(][0-9]*[)] [0-9]+[-][0-9]{4}");
			smatch matching;
			if (regex_search(section, matching, searchFile))
			{
				for (auto find : matching)
				{
					cout << "The home phone is: " << find << endl;
				}
			}
		}
		else if (topic == "business")
		{
			regex searchFile("Business Phone [(][0-9]*[)] [0-9]+[-][0-9]{4}");
			smatch matching;
			if (regex_search(section, matching, searchFile))
			{
				for (auto find : matching)
				{
					cout << "The business phone is: " << find << endl;
				}
			}
		}
		else {
			cout << "There seems to be an error in your input. PLease try again." << endl;
			getPortion();
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

void Contact::getWhole()
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
						else if (newLine == "Committee Assignments")
						{
							partEnd = true;
							continue;
						}
						else
						{
							section += newLine;
							section += "\n";
							holder = newLine;
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

std::string Contact::toLower(string input)
{
	for_each(input.begin(), input.end(), [](char &c)
			 { c = ::tolower(c); });
	return input;
}