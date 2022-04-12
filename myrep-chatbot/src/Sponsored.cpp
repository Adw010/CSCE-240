#include "../../myrep-chatbot/src/headers/Sponsored.h"
#include <regex>
#include <string>
#include <fstream>
#include <iostream>
using namespace std;

Sponsored ::~Sponsored(){};

Sponsored ::Sponsored()
{
}

void Sponsored::selectPortion(string line)
{
	Chatsession r;
	messages = "Would you like to print the whole Sponsored section or are you looking for something in particular?";
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

void Sponsored::getPart(string line)
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
	messages = "As this is a dynamic category, we will only print the whole thing.";
	cout << messages << endl;
	cout << section << endl;
	messagestwo = cpumessage + "'";
	messagestwo = cpumessage + section;
	messagestwo = cpumessage + "'";
	messages = cpumessage + messages;
	r.noteOutput(messages, line);
	r.noteOutput(messagestwo, line);
	
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


void Sponsored::getWhole(string line)
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
		user = cpumessage + "'";
		user = user + section;
		user = user + "'";
		r.noteOutput(section, line);
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

std::string Sponsored::toLower(string input)
{
	for_each(input.begin(), input.end(), [](char &c)
			 { c = ::tolower(c); });
	return input;
}