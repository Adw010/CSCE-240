#include "../../prog5-sessionlogger/src/headers/Category.h"
#include "./Counter.cpp"
#include <regex>
#include <string>
#include <fstream>
#include <iostream>
using namespace std;

Category ::~Category(){};

Category ::Category()
{
};

string Category::cat(std::string str)
{
    Counter m;
    str = m.counter(name, str);
    str = m.counter(contact, str);
    str = m.counter(address, str);
    str = m.counter(phone, str);
    str = m.counter(message, str);
    str = m.counter(party, str);
    str = m.counter(live, str);
    str = m.counter(committee, str);
    str = m.counter(sponsored, str);
    str = m.counter(bills, str);
    str = m.counter(voting, str);
    str = m.counter(service, str);
    str = m.counter(whole, str);
    str = m.counter(entire, str);
    str = m.counter(all, str);
    str = m.counter(everything, str);
    str = m.counter(personal, str);
    str = m.counter(college, str);
    str = m.counter(university, str);
    str = m.counter(school, str);
    str = m.counter(children, str);
    str = m.counter(parents, str);
    str = m.counter(association, str);
    str = m.counter(chapel, str);
    str = m.counter(quit, str);
    str = m.counter(part, str);
    str = m.counter(region, str);
    str = m.counter(home, str);
    str = m.counter(business, str);
    str = m.counter(yes, str);
    str = m.counter(no, str);
    str = m.counter(ok, str);
    str = m.counter(nvm, str);
    str = m.counter(nevermind, str);
    str = m.counter(reset, str);
    str = m.counter(education, str);
    str = m.counter(regulation, str);
    str = m.counter(reg, str);
    str = m.counter(house, str);
    str = m.counter(council, str);
    str = m.counter(birth, str);
    str = m.counter(marriage, str);
    str = m.counter(fraternity, str);
    str = m.counter(children, str);

    return str;
};