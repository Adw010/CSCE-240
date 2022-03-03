#include "./Distinguishing.cpp"
#include "./Freeform.cpp"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <regex>
#include <algorithm>
using namespace std;

string selection;



int main()
{
	cout << "Hello there. My name is ChatBot. You have two options." << endl;
	cout << "Option one is to be able to ask a limited number of free formed questions based on known data." << endl;
	cout << "Option two is to be able to have a conversation with me as I guide you through the experience." << endl;
	cout << "Please tell me which option you would like. You may say free form or conversation." << endl;
	getline(cin, selection);
	Distinguishing x;
	selection = x.toLower(selection);
	if (selection == "free form")
	{
		Freeform j;
		j.question();
	}
	else if (selection == "conversation")
	{
		x.getType(selection);
	}
	else if (selection == "quit" || selection == "q")
	{
		exit(EXIT_FAILURE);
	}
	else
	{
		cout << "You have entered an incorrect option. You will restart." << endl;
		cout << "\n"
			 << endl;
		main();
	}
}
