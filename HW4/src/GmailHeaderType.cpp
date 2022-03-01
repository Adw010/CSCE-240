/*
 * GmailHeaderType.cpp
 *
 *  Created on: Feb 27, 2022
 *      Author: Aweso
 */

#include "./GmailHeaderType.h"
#include <regex>
#include <string>
#include <iostream>
#include <fstream>

using namespace std;

GmailHeaderType :: GmailHeaderType(){
	regex to("To: [a-zA-Z_0-9.-]*[] <[a-zA-Z_0-9.]+@[a-zA-Z]+[.][edu|com]+>");
	regex deliverTo("Delivered-To:.+");
	regex source("X-Google-Smtp-Source: .+");
	regex mime("MIME-Version: .+");
	regex rTo("Reply-To: .+");
};

GmailHeaderType :: ~GmailHeaderType(){};

void GmailHeaderType :: encoding(string txt){
	smatch m;
	regex contentTransfer("Content-Transfer-Encoding:.+");
	if(regex_search(txt, m, contentTransfer)){
		for (auto x : m){
			cout<<x<<endl;
		}
	}
	else{
		cout<<"couldn't find!"<<endl;
	}
};

void GmailHeaderType :: getsource(string txt){
	smatch m;
	regex source("X-Google-Smtp-Source: .+");
	if(regex_search(txt, m, source)){
		for (auto x : m){
			cout<<x<<endl;
		}
	}
	else{
		cout<<"couldn't find!"<<endl;
	}
};

void GmailHeaderType :: mime(string txt){
	smatch m;
	regex mime("MIME-Version: .+");
	if(regex_search(txt, m, mime)){
		for (auto x : m){
			cout<<x<<endl;
		}
	}
	else{
		cout<<"couldn't find!"<<endl;
	}
};

void GmailHeaderType :: replyTo(string txt){
	smatch m;
	regex rTo("Reply-To: .+");
	if(regex_search(txt, m, rTo)){
		for (auto x : m){
			cout<<x<<endl;
		}
	}
	else{
		cout<<"couldn't find!"<<endl;
	}
};

void GmailHeaderType :: getTo(string txt){
	smatch m;
	regex to("To: [a-zA-Z_0-9.-]*[] <[a-zA-Z_0-9.]+@[a-zA-Z]+[.][edu|com]+>");
	if(regex_search(txt, m, to)){
		for (auto x : m){
			cout<<x<<endl;
		}
	}
	else{
		cout<<"couldn't find!"<<endl;
	}
};

void GmailHeaderType :: deliverTo(string txt){
	smatch m;
	regex deliverTo("Delivered-To:.+");
	if(regex_search(txt, m, deliverTo)){
		for (auto x : m){
			cout<<x<<endl;
		}
	}
	else{
		cout<<"couldn't find!"<<endl;
	}
};


