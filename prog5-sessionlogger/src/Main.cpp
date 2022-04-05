#include "./Distinguishing.cpp"
#include "./Freeform.cpp"
#include "./Category.cpp"
#include "./Chatsession.cpp"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <regex>
#include <algorithm>
using namespace std;

string selection;
string words;
string hellomessage = "Hello there. My name is ChatBot. How are you?";
string message;
string cpumessage = "CPU : ";
string usermessage = "User : ";
string user;

int main()
{
	auto t = std::time(nullptr);
    auto tm = *std::localtime(&t);
    std::ostringstream oss;
    oss << std::put_time(&tm, "%d-%m-%Y %H-%M-%S");
    auto str = oss.str();
	std::cout << "Starting recording for session labeled " << str << endl;
	Chatsession r;
	r.timeStart();	
	std::cout << hellomessage << endl;
	hellomessage = cpumessage + hellomessage;
	r.noteOutput(hellomessage, str);

    getline(cin, selection);
    Distinguishing x;
	user = usermessage + selection;
	r.noteOutput(user, str);
	selection = x.toLower(selection);
    stringstream series(selection);
    while (series >> words)
    {
        if (words == "happy" || words == "great" || words == "good" || words == "wonderful")
        {
			message = "That is wonderful to hear! I am an AI so I cannot feel that but it sounds wonderful.";
            std::cout << message << endl;
			message = cpumessage + message;
			r.noteOutput(message, str);
		}
        else if (words == "bad" || words == "horrible")
        {
            message = "I am sorry to hear that. I hope it gets better.";
			std::cout << message << endl;
			message = cpumessage + message;
			r.noteOutput(message, str);
		}
        else if (words == "average" || words == "ok")
        {
            message = "I hope to be the reason your day gets better!";
			std::cout << message << endl;
			message = cpumessage + message;
			r.noteOutput(message, str);
		}
		else if (words == "quit" || words == "q") {
			user = usermessage + selection;
			r.noteOutput(user, str);
			r.counter(str);
			r.timeEnd(str);
			exit(EXIT_FAILURE);
		}
        else
        {
			message = "Not 100% sure what that means but I hope it means you're having a great day! If not, I hope to make it better!";
            std::cout << message << endl;
			message = cpumessage + message;
			r.noteOutput(message, str);
		}
    }
    series.clear();
    series.str("");

	message = "If you want to know about the District 77 rep, you have two options.";
	std::cout << message << endl;
	message = cpumessage + message;
	r.noteOutput(message, str);

	message = "Option one is to be able to ask a limited number of free formed questions based on known data.";
	std::cout << message << endl;
	message = cpumessage + message;
	r.noteOutput(message, str);

	message = "Option two is to be able to have a conversation with me as I guide you through the experience.";
	std::cout << message << endl;
	message = cpumessage + message;
	r.noteOutput(message, str);

	message = "Option three is to check the summary of the csv. Note, we will not save this to the csv or text file.";
	std::cout << message << endl;
	message = cpumessage + message;
	r.noteOutput(message, str);

	message = "Please tell me which option you would like. You may say summary, free form or conversation.";
	std::cout << message << endl;
	message = cpumessage + message;
	r.noteOutput(message, str);

	getline(cin, selection);
	user = usermessage + selection;
	r.noteOutput(user, str);
	selection = x.toLower(selection);
	if (selection == "free form" || selection == "free" || selection == "form")
	{
		Freeform j;
		j.question(str);
	}
	else if (selection == "summary" || selection == "sum")
	{
		message = "Session ending. Going to CSV chacking.";
		cout << message << endl;
		message = cpumessage + message;
		r.noteOutput(message, str);
		r.summary();
	}
	else if (selection == "conversation")
	{
		x.getType(str);
	}
	else if (selection == "quit" || selection == "q")
	{
		r.counter(str);
		r.timeEnd(str);
		exit(EXIT_FAILURE);
	}
	else
	{
		message = "You have entered an incorrect option. You will restart.";
		std::cout << message << endl;
		message = cpumessage + message;
		r.noteOutput(message, str);
		std::cout << "\n" << endl;
		main();
	}
}
