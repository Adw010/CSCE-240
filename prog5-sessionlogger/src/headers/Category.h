#ifndef CATEGORY_H_
#define CATEGORY_H_

#include "./Counter.h"
#include "./Freeform.h"
#include "./Distinguishing.h"
#include "./Contact.h"
#include "./Committee.h"
#include "./Voting.h"
#include "./Service.h"
#include "./Personal.h"
#include "./Sponsored.h"
#include <string>
#include <regex>
#include <iostream>
#include <fstream>

class Category{
public:
    Category(); // default
    std::string cat(std::string str);
    void cat2();
    virtual ~Category();

protected:
    std::string selection;
    std::string words;
    std::string name = "name";
    std::string contact = "contact";
    std::string address = "address";
    std::string phone = "phone";
    std::string message = "message";
    std::string party = "party";
    std::string live = "live";
    std::string committee = "committee";
    std::string sponsored = "sponsored";
    std::string bills = "bills";
    std::string voting = "voting";
    std::string service = "service";
    std::string whole = "whole";
    std::string entire = "entire";
    std::string all = "all";
    std::string everything = "everything";
    std::string personal = "personal";
    std::string college = "college";
    std::string university = "university";
    std::string school = "school";
    std::string children = "children";
    std::string parents = "parents";
    std::string association = "association";
    std::string chapel = "chapel";
    std::string quit = "quit";
    std::string part = "part";
    std::string region = "region";
    std::string home = "home";
    std::string business = "business";
    std::string yes = "yes";
    std::string no = "no";
    std::string ok = "ok";
    std::string nvm = "nvm";
    std::string nevermind = "nevermind";
    std::string reset = "reset";
    std::string education = "education";
    std::string regulation = "regulation";
    std::string reg = "reg";
    std::string house = "house";
    std::string council = "council";
    std::string birth = "birth";
    std::string marriage = "marriage";
    std::string fraternity = "fraternity";
};

#endif
