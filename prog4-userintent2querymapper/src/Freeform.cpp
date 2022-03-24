#include "./Freeform.h"
#include <regex>
#include <string>
#include <fstream>
#include <iostream>
using namespace std;

Freeform::~Freeform(){};

Freeform::Freeform()
{
};

void Freeform::question()
{
    stop = false;
    cout << " " << endl;
    cout << "Please ask a question and I can tell you where to find the answer." << endl;
    cout << "When you recieve the location of where your search is, the discriptive will provide the details." << endl;
    freeForm();
};

void Freeform::freeForm()
{
    string selection;
    cin >> ws;
    getline(cin, selection);
    Distinguishing x;
    selection = x.toLower(selection);
    stringstream series(selection);
    while (series >> words)
    {
        Category c;
        words = c.cat(words);
        if (words == "name" || words == "contact" || words == "address" || words == "phone" || words == "message" || words == "party" || words == "live")
        {
            cout << "For " << words << " information, you should go look at Contact information, by parts or whole." << endl;
            fail = false;
            moving();
        }
        else if (words == "committee" || words == "committees")
        {
            cout << "For " << words << " information, you should look in Committee Information, by part or whole." << endl;
            cout << "This category is typically small." << endl;
            fail = false;
            moving();
        }
        else if (words == "sponsored" || words == "bills" || words == "voting")
        {
            cout << "For " << words << ", these are typically very small as they are dynamic." << endl;
            cout << "By dynamic, we mean it is updated often and is a words tool." << endl;
            fail = false;
            moving();
        }
        else if (words == "service")
        {
            cout << "For " << words << " information you should print the whole in the Service Option but we also separate it by parts if you want." << endl;
            fail = false;
            moving();
        }
        else if (words == "whole" || words == "entire" || words == "all" || words == "everything")
        {
            cout << "For the" << words << " thing, you can select the print whole document option." << endl;
            fail = false;
            moving();
        }
        else if (words == "personal" || words == "college" || words == "university" || words == "school" || words == "children" || words == "parents" || words == "association" || words == "chapel")
        {
            cout << "For " << words << ", you can search the personal information. If you cannot find the specific, print the whole thing" << endl;
            fail = false;
            moving();
        }
        else if (words == "quit" || words == "q")
        {
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
        moving();
    }
    else
    {
        cout << "Sorry that question yields no results. Please ask another or quit." << endl;
        fail = false;
        series.clear();
        series.str("");
        freeForm();
    }
};

void Freeform::moving()
{

    cout << "Now that you have your information, I will send you back if you want to start with the descriptive chats" << endl;
    cout << "Please enter more to reset free form or new for the descriptive form" << endl;
    cin >> selection;
    Distinguishing x;
    selection = x.toLower(selection);
    if (selection == "more" || selection == "reset" || selection == "free")
    {
        x.loop();
    }
    else if (selection == "quit" || selection == "q")
    {
        exit(EXIT_FAILURE);
    }
    else if (selection == "new" || selection == "descriptive")
    {
        x.getType(selection);
    }
    else
    {
        cout << "You have encountered an error. We will send you back to free form." << endl;
        freeForm();
    }
};