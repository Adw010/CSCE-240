#include "../../myrep-chatbot/src/headers/Contact.h"
#include <regex>
#include <string>
#include <fstream>
#include <iostream>
using namespace std;

Contact ::~Contact(){};

Contact ::Contact()
{
}

void Contact::selectPortion(string line)
{
	Chatsession r;
	messages = "Would you like to print the whole contact section or are you looking for something in particular?";
	messagestwo = "You can say whole or part.";
	cout << messages << endl;
	cout << messagestwo<< endl;
	messages = cpumessage + messages;
	messagestwo = cpumessage + messagestwo;
	r.noteOutput(messages, line);
	r.noteOutput(messagestwo, line);
	cin >> topic;
	user = usermessage + topic;
	r.noteOutput(user, line);
	topic = toLower(topic);
	Category c;
	topic = c.cat(topic);
	if (topic == "whole")
	{
		getWhole(line);
	}
	else if (topic == "quit" || topic == "q")
	{
		r.counter(line);
		r.timeEnd(line);
		exit(EXIT_FAILURE);
	}
	else if (topic == "part")
	{
		getPart(line);
	}
	else
	{
		messages = "You have encountered an error. We will send you back.";
		cout << messages << endl;
		messages = cpumessage + messages;
		r.noteOutput(messages, line);
		selectPortion(line);
	}
}

void Contact::getPart(string line)
{
	Chatsession r;
	inputfile = "../../myrep-chatbot/Data/district";
	messages = "Please provide the district number. ";
	cout << messages << endl;
	messages = cpumessage + messages;
	r.noteOutput(messages, line);
	cin >> district;
	user = cpumessage + district;
	r.noteOutput(user, line);
	district = toLower(district);
	inputfile += district;
	inputfile += extension;
	ifstream inFile;
	inFile.open(inputfile);
	if (inFile.fail())
	{
		messages = "No file to open or couldn't open. Please restart";
		cout << messages << endl;
		messages = cpumessage + messages;
		r.noteOutput(messages, line);
		getPart(line);
	}
	else if (district == "quit" || district == "q")
	{
		r.counter(line);
		r.timeEnd(line);
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
	user = cpumessage + "'";
	user = user + section;
	user = user + "'";
	r.noteOutput(user, line);
	inFile.close();
	getPortion(line);
	
}

void Contact::getPortion(string line)
{
	Chatsession r;
	messages = "What category in Contact would you like to see: ";
	messagestwo = "Type name, region, address, or phone.";
	std::cout << messages << endl;
	std::cout << messagestwo << endl;
	messages = cpumessage + messages;
	messagestwo = cpumessage + messagestwo;
	r.noteOutput(messages, line);
	r.noteOutput(messagestwo, line);
	
	cin >> topic;
	user = usermessage + topic;
	r.noteOutput(user, line);
	topic = toLower(topic);
	Category c;
	topic = c.cat(topic);
	if (topic == "name")
	{
		regex searchFile("Representative [\a-zA-Z_0-9]+?[\r\n]");
		smatch matching;
		if (regex_search(section, matching, searchFile))
		{
			for (auto find : matching)
			{
				messages = "The name is: ";
				messages += find;
				cout << messages << endl;
				messages = cpumessage + messages;
				r.noteOutput(messages, line);
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
				messages = "The region is: ";
				messages += find;
				cout << messages << endl;
				messages = cpumessage + messages;
				r.noteOutput(messages, line);
				
			}
		}
	}
	else if (topic == "address")
	{
		cout << "Do you want Business or Home?" << endl;
		cin >> topic;
		user = usermessage + topic;
		r.noteOutput(user, line);
		topic = toLower(topic);
		Category c;
		topic = c.cat(topic);
		if (topic == "home")
		{
			regex searchFile("Home Address [\a-zA-z]+ [0-9]{5}");
			smatch matching;
			if (regex_search(section, matching, searchFile))
			{
				for (auto find : matching)
				{
					messages = "The home address is: ";
					messages += find;
					cout << messages << endl;
					messages = cpumessage + messages;
					r.noteOutput(messages, line);
					
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
					messages = "The business address is: ";
					messages += find;
					cout << messages << endl;
					messages = cpumessage + messages;
					r.noteOutput(messages, line);
					
				}
			}
		}
		else
		{
			messages = "There seems to be an error in your input. Please try again.";
			cout << messages << endl;
			messages = cpumessage + messages;
			r.noteOutput(messages, line);
			getPortion(line);
		}
	}
	else if (topic == "phone")
	{
		cout << "Do you want Business or Home?" << endl;
		cin >> topic;
		user = usermessage + topic;
		r.noteOutput(user, line);
		topic = toLower(topic);
		Category c;
		topic = c.cat(topic);
		if (topic == "home")
		{
			regex searchFile("Home Phone [(][0-9]*[)] [0-9]+[-][0-9]{4}");
			smatch matching;
			if (regex_search(section, matching, searchFile))
			{
				for (auto find : matching)
				{
					messages = "The home phone is: ";
					messages += find;
					cout << messages << endl;
					messages = cpumessage + messages;
					r.noteOutput(messages, line); 
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
					messages = "The business phone is: ";
					messages += find;
					cout << messages << endl;
					messages = cpumessage + messages;
					r.noteOutput(messages, find);
				}
			}
		}
		else
		{
			messages = "There seems to be an error in your input. Please try again.";
			cout << messages << endl;
			r.noteOutput(messages, line);
			messages = cpumessage + messages;
			getPortion(line);
		}
	}
	else if (topic == "quit" || topic == "q")
	{
		r.counter(line);
		r.timeEnd(line);
		exit(EXIT_FAILURE);
	}
	else
	{
		messages = "Error, please start again.";
		std::cout << messages << endl;
		messages = cpumessage + messages;
		r.noteOutput(messages, line);		
		getPortion(line);
	}
	messages = "Action complete. Do you want to exit? Otherwise, I will send you to the main screen.";
	cout << messages << endl;
	messages = cpumessage + messages;
	r.noteOutput(messages, line);
	cin >> contin;
	user = usermessage + contin;
	r.noteOutput(user, line);
	contin = toLower(contin);
    contin = c.cat(contin);
	if (contin == "yes" || contin == "quit" || contin == "sure" || contin == "ok" || contin == "q")
	{
		r.counter(line);
		r.timeEnd(line);
		exit(EXIT_FAILURE);
	}
	else
	{
		Distinguishing m;
		m.getType(line);
	}
}

void Contact::getWhole(string line)
{
	Chatsession r;
	inputfile = "../../myrep-chatbot/Data/district";
	messages = "Please provide the district number. ";
	cout << messages << endl;
	messages = cpumessage + messages;
	r.noteOutput(messages, line);
	
	cin >> district;
	user = usermessage + district;
	r.noteOutput(user, line);
	district = toLower(district);
	inputfile += district;
	inputfile += extension;
	ifstream inFile;
	inFile.open(inputfile);
	if (inFile.fail())
	{
		
		messages = "No file to open or couldn't open. Please restart.";
		cout << messages << endl;
		messages = cpumessage + messages;
		getWhole(line);
	}
	else if (district == "quit" || district == "q")
	{
		r.counter(line);
		r.timeEnd(line);
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
		user = cpumessage + "'";
		user = user + section;
		user = user + "'";
		r.noteOutput(user, line);
	}
	inFile.close();
	messages = "Action complete. Do you want to exit? Otherwise, I will send you to the main screen.";
	cout << messages << endl;
	messages = cpumessage + messages;
	r.noteOutput(messages, line);
	cin >> contin;
	user = usermessage + contin;
	r.noteOutput(user, line);
	contin = toLower(contin);
	Category c;
    contin = c.cat(contin);
	if (contin == "yes" || contin == "quit" || contin == "sure" || contin == "ok" || contin == "q")
	{
		r.counter(line);
		r.timeEnd(line);
		exit(EXIT_FAILURE);
	}
	else
	{
		Distinguishing m;
		m.getType(line);
	}
}

std::string Contact::toLower(string input)
{
	for_each(input.begin(), input.end(), [](char &c)
			 { c = ::tolower(c); });
	return input;
}