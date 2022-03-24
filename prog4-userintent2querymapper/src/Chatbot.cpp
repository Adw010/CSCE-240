#include "./Distinguishing.cpp"
#include "./Freeform.cpp"
#include "./Category.cpp"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <regex>
#include <algorithm>
using namespace std;

string selection;
string words;

int main()
{
	cout << "Hello there. My name is ChatBot. How are you?" << endl;
    getline(cin, selection);
    Distinguishing x;
    selection = x.toLower(selection);
    stringstream series(selection);
    while (series >> words)
    {
        if (words == "happy" || words == "great" || words == "good" || words == "wonderful")
        {
            cout << "That is wonderful to hear! I am an AI so I cannot feel that but it sounds wonderful." << endl;
        }
        else if (words == "bad" || words == "horrible")
        {
            cout << "I am sorry to hear that. I hope it gets better." << endl;
        }
        else if (words == "average" || words == "ok")
        {
            cout << "I hope to be the reason your day gets better!" << endl;
        }
        else
        {
            cout << "Not 100% sure what that means but I hope it means you're having a great day! If not, I hope to make it better!" << endl;
        }
    }
    series.clear();
    series.str("");
	cout << "If you want to know about the District 77 rep, you have two options." << endl;
	cout << "Option one is to be able to ask a limited number of free formed questions based on known data." << endl;
	cout << "Option two is to be able to have a conversation with me as I guide you through the experience." << endl;
	cout << "Please tell me which option you would like. You may say free form or conversation." << endl;
	getline(cin, selection);
	selection = x.toLower(selection);
	if (selection == "free form" || selection == "free" || selection == "form")
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