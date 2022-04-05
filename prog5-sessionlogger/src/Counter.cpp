#include "../../prog5-sessionlogger/src/headers/Counter.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <regex>
#include <algorithm>
using namespace std;

Counter ::~Counter(){};

Counter ::Counter()
{
}

string Counter::counter(std::string words, std::string str)
{
    float denom = 0;
    float nummer = 0;
    float total = 0;
    float limit = 0;
    for (char i : words)
    {
        limit++;
    }
    for (char i: str) {

        denom++;
    }
    for (int a = 0, j = 0; j < limit; j++)
    {
        if (words[a] == str[j])
        {
            nummer++;
            a++;
        }
    }
    total = nummer / denom;
    
    if (total >= 1.0)
    {
        return words;
    }
    else if (total >= 0.80)
    {
        messages = "I assume you mean ";
        messages += words;
        messages = ".";
        cout << messages << endl;
        return words;
    }
    else
    {
        return str;
    }
}