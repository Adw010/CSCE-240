#include "../../prog5-sessionlogger/src/headers/Freeform.h"
#include <regex>
#include <string>
#include <fstream>
#include <iostream>
using namespace std;

Freeform::~Freeform(){};

Freeform::Freeform()
{
};

void Freeform::question(std::string file)
{
    stop = false;
    holder = "Please ask a question and I can tell you where to find the answer.";
    messages = "When you recieve the location of where your search is, the discriptive will provide the details.";
    std::cout << " " << endl;
    Chatsession r;
    
    std::cout << holder << endl;
    std::cout << messages << endl;
    holder = cpumessage + holder;
    messages = cpumessage + messages;
    r.noteOutput(holder, file);
    r.noteOutput(messages, file);
    freeForm(file);
};

void Freeform::freeForm(std::string file)
{
    Chatsession r;
    string selection;
    cin >> ws;
    getline(cin, selection);
    Distinguishing x;
    user = usermessage + selection;
    r.noteOutput(user, file);
    selection = x.toLower(selection);
    stringstream series(selection);
    while (series >> words)
    {
        Category c;
        words = c.cat(words);
        if (words == "name" || words == "contact" || words == "address" || words == "phone" || words == "message" || words == "party" || words == "live")
        {
            holder = "For ";
            holder += words;
            messages = " information, you should go look at Contact information, by parts or whole.";
            holder += messages;
            std::cout << holder << endl;
            holder = cpumessage + holder;
            r.noteOutput(holder, file);
            fail = false;
            moving(file);
        }
        else if (words == "committee" || words == "committees")
        {
            holder = "For ";
            holder += words;
            messages = " information, you should look in Committee Information, by part or whole. This category is typically small.";
            holder += messages;
            std::cout << holder << endl;
            holder = cpumessage + holder;
            r.noteOutput(holder, file);
            fail = false;
            moving(file);
        }
        else if (words == "sponsored" || words == "bills" || words == "voting")
        {
            holder = "For ";
            holder += words;
            messages = ", these are typically very small as they are dynamic. By dynamic, we mean it is updated often and is a words tool.";
            holder += messages;
            std::cout << holder << endl;
            holder = cpumessage + holder;
            r.noteOutput(holder, file);
            fail = false;
            moving(file);
        }
        else if (words == "service")
        {
            holder = "For ";
            holder += words;
            messages = " information you should print the whole in the Service Option but we also separate it by parts if you want.";
            holder += messages;
            std::cout << holder << endl;
            holder = cpumessage + holder;
            r.noteOutput(holder, file);
            fail = false;
            moving(file);
        }
        else if (words == "whole" || words == "entire" || words == "all" || words == "everything")
        {
            holder = "For the";
            holder += words;
            messages = " thing, you can select the print whole document option.";
            holder += messages;
            std::cout << holder << endl;
            holder = cpumessage + holder;
            r.noteOutput(holder, file);
            fail = false;
            moving(file);
        }
        else if (words == "personal" || words == "college" || words == "university" || words == "school" || words == "children" || words == "parents" || words == "association" || words == "chapel")
        {
            holder = "For ";
            holder += words;
            messages = ", you can search the personal information. If you cannot find the specific, print the whole thing";
            holder += messages;
            std::cout << holder << endl;
            holder = cpumessage + holder;
            r.noteOutput(holder, file);
            
            fail = false;
            moving(file);
        }
        else if (words == "quit" || words == "q")
        {
            r.counter(file);
            r.timeEnd(file);
            exit(EXIT_FAILURE);
        }
        else
        {
            fail = true;
        }
    }
    if (fail != true)
    {
        series.clear();
        series.str("");
        moving(file);
    }
    else
    {
        messages = "Sorry that question yields no results. Please ask another or quit.";
        messages = cpumessage + messages;
        std::cout << messages << endl;
        r.noteOutput(messages, file);
        fail = false;
        series.clear(); 
        series.str("");
        freeForm(file);
    }
};

void Freeform::moving(string line)
{
    Chatsession r;
    string hellomessage = "Now that you have your information, I will send you back if you want to start with the descriptive chats";
	hellomessage = cpumessage + hellomessage;
    std::cout << hellomessage << endl;
    r.noteOutput(hellomessage, line);

    hellomessage = "Please enter more to reset free form or new for the descriptive form";
    std::cout << hellomessage << endl;
    hellomessage = cpumessage + hellomessage;
    r.noteOutput(hellomessage, line);

    
    cin >> selection;
    user = usermessage + selection;
    r.noteOutput(user, line);
    Distinguishing x;
    selection = x.toLower(selection);
    if (selection == "more" || selection == "reset" || selection == "free")
    {
        x.loop(line);
    }
    else if (selection == "quit" || selection == "q")
    {
        r.counter(line);
        r.timeEnd(line);
        exit(EXIT_FAILURE);
    }
    else if (selection == "new" || selection == "descriptive")
    {
        x.getType(line);
    }
    else
    {
        hellomessage = "You have encountered an error. We will send you back to free form.";
        std::cout << hellomessage << endl;
        hellomessage = cpumessage + hellomessage;
        r.noteOutput(hellomessage, line);
        freeForm(line);
    }
};