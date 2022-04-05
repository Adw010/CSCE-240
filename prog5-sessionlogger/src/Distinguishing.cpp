#include "../../prog5-sessionlogger/src/headers/Distinguishing.h"
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
	inputfile = "../../prog5-sessionlogger/Data/district";
};


void Distinguishing ::getType(string file)
{
	Chatsession r;
	messages = "Hello, would you like to start looking at the data? Yes to continue.";
	messagestwo = "Throughout this process, you can say quit to stop.";
	std::cout << messages << endl;
	std::cout << messagestwo << endl;
	messages = cpumessage + messages;
	messagestwo = cpumessage + messagestwo;
	r.noteOutput(messages, file);
	r.noteOutput(messagestwo, file);

	
	cin >> contin;
	user = usermessage + contin;
	r.noteOutput(user, file);
	contin = toLower(contin);
	Category c;
    contin = c.cat(contin);
	if (contin == "yes")
	{
		messages = "OK, we will continue.";
		std::cout << messages << endl;
		messages = cpumessage + messages;
		r.noteOutput(messages, file);
		
	}
	else if (contin == "quit" || contin == "q")
	{
		messages = "OK, we will stop.";
		std::cout << messages << endl;
		messages = cpumessage + messages;
		r.noteOutput(messages, file);
		r.counter(file);
		r.timeEnd(file);		
		exit(EXIT_FAILURE);
	}
	else
	{
		messages = "Sorry, we will restart then.";
		std::cout << messages << endl;
		std::cout << " " << endl;
		messages = cpumessage + messages;
		r.noteOutput(messages, file);
		getType(contin);
	}
	messages = "Would you like to look at the whole document or just a part?";
	std::cout << messages << endl;
	messages = cpumessage + messages;
	r.noteOutput(messages, file);
	cin >> typing;
	user = usermessage + typing;
	r.noteOutput(user, file);
	typing = toLower(typing);
    typing = c.cat(typing);
	if (typing == "whole")
	{
		printWholeFile(file);
	}
	else if (typing == "part")
	{
		getTopic(file);
	}
	else
	{
		error(file);
	}
};

void Distinguishing :: getTopic(string file){
	Chatsession r;
	messages = "Would you like to see Contact, Committee, Service, Voting, Sponsored or Personal?";
	messagestwo = "You can also say nvm or Nevermind to go back to start.";
	std::cout << messages << endl;
	std::cout << messagestwo << endl;
	r.noteOutput(messages, file);
	r.noteOutput(messagestwo, file);
	
	cin >> topic;
	user = usermessage + topic;
	r.noteOutput(user, file);
	topic = toLower(topic);
	Category c;
    topic = c.cat(topic);
	if (topic == "nvm" || topic == "nevermind") {
		getType(topic);
	}
	else if (topic == "contact"){
		messages = "You chose Contact.";
		std::cout << messages << endl;
		messages = cpumessage + messages;
		r.noteOutput(messages, file);
		
		Contact a;
		a.selectPortion(file);
	}
	else if (topic == "committee"){
		messages = "You chose Committee.";
		std::cout << messages << endl;
		messages = cpumessage + messages;
		r.noteOutput(messages, file);
		

		Committee b;
		b.selectPortion(file);
	}
	else if (topic == "sponsored"){
		messages = "You chose Sponsored.";
		std::cout << messages << endl;
		messages = cpumessage + messages;
		r.noteOutput(messages, file);
		
		Sponsored c;
		c.selectPortion(file);		
	}
	else if (topic == "voting"){
		messages = "You chose Voting.";
		std::cout << messages << endl;
		messages = cpumessage + messages;
		r.noteOutput(messages, file);
		
		Voting d;
		d.selectPortion(file);
	}
	else if (topic == "service"){
		messages = "You chose Service.";
		std::cout << messages << endl;
		messages = cpumessage + messages;
		r.noteOutput(messages, file);
		
		Service e;
		e.selectPortion(file);
	}
	else if (topic == "personal"){
		messages = "You chose Personal.";
		std::cout << messages << endl;
		messages = cpumessage + messages;
		r.noteOutput(messages, file);
		
		Personal f;
		f.selectPortion(file);
	}
	else if (topic == "q" || topic == "quit"){
		r.counter(file);
		r.timeEnd(file);
		exit(EXIT_FAILURE);
	}
	else{
		messages = "Bad choice, please select again.";
		std::cout << messages << endl;
		messages = cpumessage + messages;
		r.noteOutput(messages, file);
		getTopic(file);
	}
}

void Distinguishing ::printWholeFile(string file)
{
	inputfile = "../../prog5-sessionlogger/Data/district";
	Chatsession r;
	messages = "Please provide the district number. ";
	std::cout << messages << endl;
	messages = cpumessage + messages;
	r.noteOutput(messages, file);
	
	cin >> district;
	user = usermessage + district;
	r.noteOutput(user, file);
	district = toLower(district);
	inputfile += district;
	inputfile += extension;

	ifstream inFile;
	inFile.open(inputfile);
	if (inFile.fail())
	{
		messages = "No file to open or couldn't open. Please restart";
		std::cout << messages << endl;
		messages = cpumessage + messages;
		r.noteOutput(messages, file);
		printWholeFile(file);
	}
	else if (district == "quit" || district == "q")
	{
		r.counter(file);
		r.timeEnd(file);
		exit(EXIT_FAILURE);
	}
	else
	{
		user = cpumessage + "'";
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
						user += newLine;
						user += "\n";
						holder = newLine;
					}
				}
			}
		}
		user = user + "'";
		r.noteOutput(user, file);
		
	}
	
	inFile.close();
	messages = "Action complete. Do you want to exit? Otherwise, I will send you to the main screen.";
	std::cout << messages << endl;
	messages = cpumessage + messages;
	r.noteOutput(messages, file);
	cin >> contin;
	user = usermessage + contin;
	r.noteOutput(user, file);
	contin = toLower(contin);
	Category c;
    contin = c.cat(contin);
	if (contin == "yes" || contin == "quit" || contin == "sure" || contin == "ok" || contin == "q")
	{
		r.counter(file);
		r.timeEnd(file);
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

void Distinguishing ::error(std::string file)
{
	Chatsession r;
	messages = "You have encountered an error. Going back to the start.";
	messagestwo = "Would you like to quit or reset?";
	std::cout << messages << endl;
	std::cout << messagestwo << endl;
	r.noteOutput(messages, file);
	r.noteOutput(messagestwo, file);

	cin >> contin;
	user = usermessage + contin;
	r.noteOutput(user, file);
	contin = toLower(contin);
	Category c;
    contin = c.cat(contin);
	while (errorSelection != true)
	{
		if (contin == "quit" || contin == "q")
		{
			messages = "Program now ending.";
			std::cout << messages << endl;
			messages = cpumessage + messages;
			r.noteOutput(messages, file);
			r.counter(file);
			r.timeEnd(file);			
			exit(EXIT_FAILURE);
		}
		else if (contin == "reset")
		{
			getType(contin);
		}
		else
		{
			error(file);
		}
	}
}

void Distinguishing::loop(string file){
	Freeform y;
	y.question(file);
}
