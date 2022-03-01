/*
 * EmailInformationExtractor.cpp
 *
 *  Created on: Feb 25, 2022
 *      Author: Aweso
 */
#include "./BaseEmailHeaderType.cpp"
#include "./GmailHeaderType.cpp"
#include "./OutlookHeaderType.cpp"
#include <iostream>
#include <algorithm>
#include <fstream>
#include <string>
#include <regex>

using namespace std;

bool error = false;

string readinputFile(string inputfile)
{
	ifstream input;
	input.open(inputfile, ios::in);
	// error handling
	if (input.is_open())
	{
		cout << "File successfully opened" << endl;
	}
	else
	{
		cout << "File did not open sorry!" << endl;
		error = true;
	}
	// loop through each line and concatenate
	string line;
	string text;
	while (getline(input, line))
	{
		text += line;
		text += "\n";
	}
	input.close();
	return text;
}

string toLower(string conversion){
	for_each(conversion.begin(), conversion.end(), [](char & c) {
        c = ::tolower(c);
    });

	return conversion;

}

int main()
{

	BaseEmailHeaderType b;
	GmailHeaderType g;
	OutlookHeaderType o;

	
	cout << "Please enter the email txt file. Ensure the file is listed as _____.txt " << endl;
	
	string inputfile;
	cin >> inputfile;

	
	toLower(inputfile);

	string txt;
	string newfilename;
	newfilename = "../../HW4/data/";
	newfilename += inputfile;
	txt = readinputFile(newfilename);

	if (error != true)
	{

		
		cout << "Please enter header name " << endl;
		string header;
		cin >> header;
		toLower(header);
		if (header == "gmail")
		{
			// gmail
			cout << "Please enter part name: delivered-to, reply, mime, content-transfer, source, CC, received, to, from, date, subject, and content-type " << endl;
			string part;
			cin >> part;
			toLower(part);
			if (part == "date")
			{
				b.getDate(txt);
			}
			else if (part == "subject")
			{
				b.getSubject(txt);
			}
			else if (part == "content-type")
			{
				b.getContentType(txt);
			}
			else if (part == "from")
			{
				b.getFrom(txt);
			}
			else if (part == "to")
			{
				g.getTo(txt);
			}
			else if (part == "received")
			{
				b.getReceived(txt);
			}
			else if (part == "CC" || part == "cc")
			{
				b.getCC(txt);
			}
			else if (part == "source")
			{
				g.getsource(txt);
			}
			else if (part == "content-transfer")
			{
				g.encoding(txt);
			}
			else if (part == "mime")
			{
				g.mime(txt);
			}
			else if (part == "reply")
			{
				g.replyTo(txt);
			}
			else if (part == "delivered-to")
			{
				g.deliverTo(txt);
			}
			else
			{
				cout << "Could not find the part name" << endl;
			}
		}
		else if (header == "microsoft")
		{
			// microsoft
			cout << "Please enter part name: authenication or auth, language, ms-attach, ms-exchange, message-id, thread, CC, received, to, from, content-type, subject, and date" << endl;
			string part;
			cin >> part;
			toLower(part);
			if (part == "date")
			{
				b.getDate(txt);
			}
			else if (part == "subject")
			{
				b.getSubject(txt);
			}
			else if (part == "content-type")
			{
				b.getContentType(txt);
			}
			else if (part == "from")
			{
				b.getFrom(txt);
			}
			else if (part == "to")
			{
				b.getTo(txt);
			}
			else if (part == "received")
			{
				b.getReceived(txt);
			}
			else if (part == "CC" || part == "cc")
			{
				b.getCC(txt);
			}
			else if (part == "Thread" || part == "thread")
			{
				o.getThread(txt);
			}
			else if (part == "message-id")
			{
				b.getMessage(txt);
			}
			else if (part == "ms-exchange")
			{
				o.MS_Exchange(txt);
			}
			else if (part == "ms-attach")
			{
				o.MS_Attach(txt);
			}
			else if (part == "language")
			{
				o.language(txt);
			}
			else if (part == "auth" || part == "authenication")
			{
				o.authenication(txt);
			}
			else
			{
				cout << "Could not find the part name" << endl;
			}
		}
		else
		{
			cout << "Please type gmail or microsoft for the header!" << endl;
		}
	}
	else
	{
		cout << "Program will now end. Thank you." << endl;
	}
}
