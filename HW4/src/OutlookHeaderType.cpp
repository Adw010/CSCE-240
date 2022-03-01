/*
 * OutlookHeaderType.cpp
 *
 *  Created on: Feb 27, 2022
 *      Author: Aweso
 */

#include <string>
#include <iostream>
#include <fstream>
#include <regex>
#include "./OutlookHeaderType.h"

using namespace std;

OutlookHeaderType :: ~OutlookHeaderType(){};

OutlookHeaderType :: OutlookHeaderType(){
	regex thread ("Thread-[\a-zA-Z_0-9]+ ...+");
	regex msExchange ("X-MS-Exchange-Organization-SCL: -[0-9]{1}");
	regex msAttach("X-MS-Has-Attach: [a-zA-Z_0-9]*");
	regex languageA("Accept-Language: [a-zA-Z]+-[A-Z]+");
	regex languageC("Content-Language: [a-zA-Z]+-[A-Z]+");
	regex authenicate("Authentication-Results: [\a-zA-Z_0-9]+dkim=[a-zA-Z]+");
};

void OutlookHeaderType :: getThread(string txt){
	smatch m;
	regex thread ("Thread-[\a-zA-Z_0-9]+ ...+");
	if(regex_search(txt, m, thread)){
		for (auto x : m){
			cout<<x<<endl;
		}
	}
	else{
		cout<<"couldn't find!"<<endl;
	}
};

void OutlookHeaderType :: MS_Exchange(string txt){
	smatch m;
	regex msExchange ("X-MS-Exchange-Organization-SCL: -[0-9]{1}");
	if(regex_search(txt, m, msExchange)){
		for (auto x : m){
			cout<<x<<endl;
		}
	}
	else{
		cout<<"couldn't find!"<<endl;
	}
};

void OutlookHeaderType :: MS_Attach(string txt){
	smatch m;
	regex msAttach("X-MS-Has-Attach: [a-zA-Z_0-9]*");
	if(regex_search(txt, m, msAttach)){
		for (auto x : m){
			cout<<x<<endl;
		}
	}
	else{
		cout<<"couldn't find!"<<endl;
	}

};

void OutlookHeaderType :: language(string txt){
	smatch m;
	regex languageA("Accept-Language: [a-zA-Z]+-[A-Z]+");
	regex languageC("Content-Language: [a-zA-Z]+-[A-Z]+");
	if(regex_search(txt, m, languageA)){
		for (auto x : m){
			cout<<x<<endl;
		}
	}
	else{
		cout<<"couldn't find!"<<endl;
	}
	if(regex_search(txt, m, languageC)){
		for (auto x : m){
			cout<<x<<endl;
		}
	}
	else{
		cout<<"couldn't find!"<<endl;
	}
};

void OutlookHeaderType :: authenication(string txt){
	smatch m;
	regex authenicate("Authentication-Results: [\a-zA-Z_0-9]+dkim=[a-zA-Z]+");
	if(regex_search(txt, m, authenicate)){
		for (auto x : m){
			cout<<x<<endl;
		}
	}
	else{
		cout<<"couldn't find!"<<endl;
	}
};
