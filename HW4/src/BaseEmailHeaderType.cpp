/*
 * BaseEmailHeaderType.cpp
 *
 *  Created on: Feb 26, 2022
 *      Author: Aweso
 */

#include "./BaseEmailHeaderType.h"
#include <regex>
#include <string>
#include <fstream>
#include <iostream>


using namespace std;

BaseEmailHeaderType :: ~BaseEmailHeaderType(){};

BaseEmailHeaderType :: BaseEmailHeaderType(){
	regex received ("Received: .+");
	regex date ("Date: [a-zA-Z]{3}, [0-9]{2} [a-zA-Z]{3} [0-9]{4} [0-9:]+ [+0-9]+");
	regex header ("[\a-zA-Z]+ Header");
	regex from("From: .+");
	regex message("Message-ID: .+");
	regex subject ("Subject: .+");
	regex cc("C[C|c]: [\a-zA-Z]+ <[a-zA-Z_0-9]+@[a-zA-Z.]+>");
	regex content ("Content-Type: .+");
	regex to ("To: .+");
	regex contentTransfer("Content-Transfer-Encoding:.+");
};

void BaseEmailHeaderType :: getReceived(string txt){
	smatch m;
	regex received ("Received: .+");
	if(regex_search(txt, m, received)){
		for (auto x : m){
			cout<<x<<endl;
		}
	}
	else{
		cout<<"couldn't find!"<<endl;
	}
};

void BaseEmailHeaderType :: getMessage(string txt){
	smatch m;
	regex message("Message-ID: .+");
	if(regex_search(txt, m, message)){
		for (auto x : m){
			cout<<x<<endl;
		}
	}
	else{
		cout<<"couldn't find!"<<endl;
	}
};

void BaseEmailHeaderType :: getFrom(string txt){
	smatch m;
	regex from ("From: .+");
	if(regex_search(txt, m, from)){
		for (auto x : m){
			cout<<x<<endl;
		}
	}
	else{
		cout<<"couldn't find!"<<endl;
	}
};

void BaseEmailHeaderType :: getDate(string txt){
	smatch m;
	regex date ("Date: [a-zA-Z]{3}, [0-9]{2} [a-zA-Z]{3} [0-9]{4} [0-9:]+ [+0-9]+");
	if(regex_search(txt, m, date)){
		for (auto x : m){
			cout<<x<<endl;
		}
	}
	else{
		cout<<"couldn't find!"<<endl;
	}
};

void BaseEmailHeaderType :: getSubject(string txt){
	smatch m;
	regex subject ("Subject: .+");
	if(regex_search(txt, m, subject)){
		for (auto x : m){
			cout<< x <<endl;
		}
	}
	else{
		cout<<"couldn't find!"<<endl;
	}
};

void BaseEmailHeaderType :: getHeader(string inputfile){};

void BaseEmailHeaderType :: getContentType(string txt){
	regex content("Content-Type: .+");
	smatch m;
	if(regex_search(txt, m, content)){
		for (auto x : m){
			cout<<x<<endl;
		}
	}
	else{
		cout<<"couldn't find!"<<endl;
	}
};

void BaseEmailHeaderType :: getTo(string txt){
	smatch m;
	regex to ("To: .+");
	if(regex_search(txt, m, to)){
		for (auto x : m){
			cout<<x<<endl;
		}
	}
	else{
		cout<<"couldn't find!"<<endl;
	}
};

void BaseEmailHeaderType :: getCC(string txt){
	smatch m;
	regex cc("C[C|c]: [\a-zA-Z]+ <[a-zA-Z_0-9]+@[a-zA-Z.]+>");
	if(regex_search(txt, m, cc)){
		for (auto x : m){
			cout<<x<<endl;
		}
	}
	else{
		cout<<"couldn't find!"<<endl;
	}
};



