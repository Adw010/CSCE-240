#include "../../myrep-chatbot/src/headers/Personal.h"
#include <regex>
#include <string>
#include <fstream>
#include <iostream>
using namespace std;

Personal ::~Personal(){};

Personal ::Personal()
{
}

void Personal::selectPortion(string line)
{
	Chatsession r;
	messages = "Would you like to print the whole Personal section or are you looking for something in particular?";
	messagestwo = "You can say whole or part.";
	section += "\n";
	cout << messages << endl;
	cout << messagestwo << endl;
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

void Personal::getPart(string line)
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
	getPortion(line);
	inFile.close();
}

void Personal::getPortion(string line)
{
	Chatsession r;
	messages = "What category in Personal would you like to see: ";
	messagestwo = "Type parents, birth, marriage, children, or fraternity.";
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
	if (topic == "parents")
	{
		regex searchFile("\\w+(?=.*late)[\a-zA-Z]*?[\r\n]");
		smatch matching;
		if (regex_search(section, matching, searchFile))
		{
			for (auto find : matching)
			{
				cout << find << endl;
				r.noteOutput(find, line);

				
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
				messages = "The birth information is: ";
				messages += find;
				cout << messages << endl;
				messages = cpumessage + messages;
				r.noteOutput(messages, line);
				
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
				r.noteOutput(find, line);
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
				messages = "The business address is: ";
				messages += find;
				cout << messages << endl;
				messages = cpumessage + messages;
				r.noteOutput(messages, line);
				
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
				messages = "The home phone is: ";
				messages += find;
				cout << messages << endl;
				messages = cpumessage + messages;
				r.noteOutput(messages, line);
				
			}
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
void Personal::getWhole(string line)
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
		messages = "No file to open or couldn't open. Please restart";
		cout << messages << endl;
		r.noteOutput(messages, line);
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
		user = cpumessage + "'";
		user = user + section;
		user = user + "'";
		r.noteOutput(user, line);

		
	}
	inFile.close();
	messages = "Action complete. Do you want to exit? Otherwise, I will send you to the main screen.";
	cout << messages << endl;
	messages = usermessage + messages;
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

std::string Personal::toLower(string input)
{
	for_each(input.begin(), input.end(), [](char &c)
			 { c = ::tolower(c); });
	return input;
}