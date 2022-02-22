#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <regex>
using namespace std;

int main()
{
	string district, words, str, newLine, searching, holder, districtse;
	int wordnum = 0;
	int personalCount = 0;
	int committeeCount = 0;
	int sponsoredCount = 0;
	int votingCount = 0;
	int serviceCount = 0;
	int line_count = 0;
	int storage = 0;
	char ch = 'A';
	string option1 = "Contact";
	int contactType = 0;
	string contactLine;
	string option6 = "Personal";
	int personalType = 0;
	string personalLine;
	string option2 = "Committee";
	int committeeType = 0;
	string committeeLine;
	string option3 = "Sponsored";
	int sponsoredType = 0;
	string sponsoredLine;
	string option4 = "Voting";
	int votingType = 0;
	string votingLine;
	string option5 = "Service";
	int serviceType = 0;
	string serviceLine;
	bool error = false;
	int type;

	std::cout << "What is your district? Please provide as District__.txt exactly with numbers inplace of lines. Be careful of capitalization." << endl;
	cin >> district;
	districtse = "../../prog2-processor/Data/";
	districtse += district;

	ifstream inFile;		 // variable for file
	inFile.open(districtse); // opens file for input

	if (inFile.fail())
	{
		cerr << "No file to open or couldn't open. Please restart" << endl;
		exit(1);
	} // error catcher

	std::cout << "What topic would you like to search?" << endl;
	std::cout << "Contact for (1) Contact Information." << endl;
	std::cout << "Committee for (2) Committee Assignments." << endl;
	std::cout << "Sponsored for (3) Sponsored Bills in the House." << endl;
	std::cout << "Voting for (4) Voting Record." << endl;
	std::cout << "Service for (5) Service in the Public Office." << endl;
	std::cout << "Personal for (6) Personal Information." << endl;
	std::cout << "If you do not enter as shown, it will break." << endl;
	cin >> searching;
	std::cout << " " << endl;

	std::cout << "Would you like to print an entire type (enter 1 for this option) or a specific category of a type? (enter 2 for this option)"
		 << endl;
	cin >> type;

	if (type == 1)
	{

		if (searching == option1)
		{
			std::cout << "Contact Information details are below:" << endl;
		}
		else if (searching == option2)
		{
			std::cout << "Committee Assignments details are below:" << endl;
		}
		else if (searching == option3)
		{
			std::cout << "Sponsored Bills in the House details are below:" << endl;
		}
		else if (searching == option4)
		{
			std::cout << "Voting Record details are below:" << endl;
		}
		else if (searching == option5)
		{
			std::cout << "Service in the Public Office details are below:" << endl;
		}
		else if (searching == option6)
		{
			std::cout << "Personal Information details are below:" << endl;
		}
		else
		{
			std::cout << "You have encountered an error." << endl;
			error = true;
		}
		if (error != true)
		{
			while (getline(inFile, newLine))
			{ // gets lines
				if (newLine.empty())
				{
					continue; // sends back if line is empty
				}
				else
				{
					stringstream series(newLine);
					while (series >> words)
					{ // takes in line as string
					sponsoredCount++;
					votingCount++;
					serviceCount++;
					personalCount++;

						if (searching == option1)
						{
							if (error != true)
							{
								if (holder == newLine)
								{
									continue;
								}
								else if (newLine == "Committee Assignments")
								{
									error = true;
									continue;
								}
								else
								{
									std::cout << newLine << endl;
									holder = newLine;
								}
							}
						}
						else if (searching == option2)
						{
							line_count++;
							if (error != true)
							{
								if (holder == newLine)
								{
									continue;
								}
								else if (line_count <= 52)
								{
									continue;
								}
								else if (newLine == "Sponsored Bills in the House")
								{
									error = true;
									continue;
								}
								else
								{
									std::cout << newLine << endl;
									holder = newLine;
								}
							}
						}
						else if (searching == option3)
						{
							line_count++;
							if (error != true)
							{
								if (holder == newLine)
								{
									continue;
								}
								else if (line_count <= 66)
								{
									continue;
								}
								else if (words == "Voting")
								{
									error = true;
									continue;
								}
								else
								{
									std::cout << newLine << endl;
									holder = newLine;
								}
							}
						}
						else if (searching == option4)
						{
							std::cout << "comes in here " << votingCount << endl;
							std::cout << "comes in here " << words << endl;
							line_count++;
							if (error != true)
							{
								if (holder == newLine)
								{
									continue;
								}
								else if (line_count <= 79)
								{
									continue;
								}
								else if (words == "Service")
								{
									error = true;
									continue;
								}
								else
								{
									std::cout << newLine << endl;
									holder = newLine;
								}
							}
						}
						else if (searching == option5)
						{
							line_count++;
							if (error != true)
							{
								if (holder == newLine)
								{
									continue;
								}
								else if (line_count <= 87)
								{
									continue;
								}
								else if (words == "Personal")
								{
									error = true;
									continue;
								}
								else
								{
									std::cout << newLine << endl;
									holder = newLine;
								}
							}
						}
						else if (searching == option6)
						{
							line_count++;
							if (error != true)
							{
								if (holder == newLine)
								{
									continue;
								}
								else if (line_count <= 104)
								{
									continue;
								}
								else
								{
									std::cout << newLine << endl;
									holder = newLine;
								}
							}
						}
						else
						{
							continue;
						}
					}
				}
			}
		}
		inFile.close();
	}
	if (type == 2)
	{
		std::ofstream outFile{"../../prog2-processor/Doc/test_output.txt"};

		if (searching == option1)
		{
			std::cout << "What category in Contact would you like to see: " << endl;
			std::cout << "Type 1 for name. " << endl;
			std::cout << "Type 2 for region. " << endl;
			std::cout << "Type 3 for business address. " << endl;
			std::cout << "Type 4 for home address. " << endl;
			std::cout << "Type 5 for business phone. " << endl;
			std::cout << "Type 6 for home phone." << endl;
			cin >> contactType;

			while (getline(inFile, newLine))
			{ // gets lines
				if (newLine.empty())
				{
					continue; // sends back if line is empty
				}
				else
				{
					stringstream series(newLine);
					while (series >> words)
					{ // takes in line as string
						if (error != true)
						{
							if (holder == newLine)
							{
								continue;
							}
							else if (newLine == "Committee Assignments")
							{
								error = true;
								continue;
							}
							else
							{
								contactLine += newLine;
								contactLine += "\n";
								holder = newLine;
							}
						}
						else
						{
							continue;
						}
					}
				}
			}
			if (contactType == 1)
			{
				regex searchFile("Representative [\a-zA-Z_0-9]+?[\r\n]");
				smatch matching;
				if (regex_search(contactLine, matching, searchFile))
				{
					for (auto find : matching)
					{
						outFile << "The name is: " << endl;
						outFile << find << endl;
					}
				}
			}
			else if (contactType == 2)
			{
				regex searchFile("District [0-9]* [-] [\a-zA-Z]*?[\r\n]");
				smatch matching;
				if (regex_search(contactLine, matching, searchFile))
				{
					for (auto find : matching)
					{
						outFile << "The Region is:" << endl;
						outFile << find << endl;
					}
				}
			}
			else if (contactType == 3)
			{
				regex searchFile("Columbia Address[\r\n]+[\a-zA-Z]+Columbia [0-9]{5}");
				smatch matching;
				if (regex_search(contactLine, matching, searchFile))
				{
					for (auto find : matching)
					{
						outFile << "The Business Address is:" << endl;
						outFile << find << endl;
					}
				}
			}
			else if (contactType == 4)
			{
				regex searchFile("Home Address [\a-zA-z]+ [0-9]{5}");
				smatch matching;
				if (regex_search(contactLine, matching, searchFile))
				{
					for (auto find : matching)
					{
						outFile << "The Home Address is:" << endl;
						outFile << find << endl;
					}
				}
			}
			else if (contactType == 5)
			{
				regex searchFile("Business Phone [(][0-9]*[)] [0-9]+[-][0-9]{4}");
				smatch matching;
				if (regex_search(contactLine, matching, searchFile))
				{
					for (auto find : matching)
					{
						std::cout << find << endl;
						outFile << "The name is: " << endl;
						outFile << find << endl;
					}
				}
			}
			else if (contactType == 6)
			{
				regex searchFile("Home Phone [(][0-9]*[)] [0-9]+[-][0-9]{4}");
				smatch matching;
				if (regex_search(contactLine, matching, searchFile))
				{
					for (auto find : matching)
					{
						std::cout << find << endl;
						outFile << "The name is: " << endl;
						outFile << find << endl;
					}
				}
			}
			else
			{
				std::cout << "Error, please start again" << endl;
			}
		}
		else if (searching == option2)
		{
			while (getline(inFile, newLine))
			{ // gets lines
				if (newLine.empty())
				{
					continue; // sends back if line is empty
				}
				else
				{
					stringstream series(newLine);
					while (series >> words)
					{

						if (searching == option2)
						{
							line_count++;
							if (error != true)
							{
								if (holder == newLine)
								{
									continue;
								}
								else if (line_count <= 52)
								{
									continue;
								}
								else if (newLine == "Sponsored Bills in the House")
								{
									error = true;
									continue;
								}
								else
								{
									committeeLine += newLine;
									committeeLine += "\n";
									holder = newLine;
								}
							}
						}
					}
				}
			}
			outFile << "Committee Line only has two outputs so they are printed below" << endl;
			outFile << committeeLine << endl;
		}
		else if (searching == option3)
		{
			while (getline(inFile, newLine))
			{ // gets lines
				if (newLine.empty())
				{
					continue; // sends back if line is empty
				}
				else
				{
					stringstream series(newLine);
					while (series >> words)
					{ // takes in line as string
						if (searching == option3)
						{
							line_count++;
							if (error != true)
							{
								if (holder == newLine)
								{
									continue;
								}
								else if (line_count <= 64)
								{
									continue;
								}
								else if (words == "Voting")
								{
									error = true;
									continue;
								}
								else
								{
									sponsoredLine += newLine;
									sponsoredLine += "\n";
									holder = newLine;
								}
							}
						}
					}
				}
			}
			std::cout << "Sponsored Bills in the House details are below:" << endl;
			std::cout << sponsoredLine << endl;
		}
		else if (searching == option4)
		{
			while (getline(inFile, newLine))
			{ // gets lines
				if (newLine.empty())
				{
					continue; // sends back if line is empty
				}
				else
				{
					stringstream series(newLine);
					while (series >> words)
					{ // takes in line as string
						if (searching == option4)
						{
							line_count++;
							if (error != true)
							{
								if (holder == newLine)
								{
									continue;
								}
								else if (line_count <= 79)
								{
									continue;
								}
								else if (words == "Service")
								{
									error = true;
									continue;
								}
								else
								{
									votingLine += newLine;
									votingLine += "\n";
									holder = newLine;
								}
							}
						}
					}
				}
			}
			outFile << "Voting Record details are below:" << endl;
			outFile << votingLine << endl;
		}
		else if (searching == option5)
		{
			while (getline(inFile, newLine))
			{ // gets lines
				if (newLine.empty())
				{
					continue; // sends back if line is empty
				}
				else
				{
					stringstream series(newLine);
					while (series >> words)
					{ // takes in line as string
						if (searching == option5)
						{
							line_count++;
							if (error != true)
							{
								if (holder == newLine)
								{
									continue;
								}
								else if (line_count <= 87)
								{
									continue;
								}
								else if (words == "Personal")
								{
									error = true;
									continue;
								}
								else
								{
									serviceLine += newLine;
									serviceLine += "\n";
									holder = newLine;
								}
							}
						}
					}
				}
			}
			outFile << "Service in the Public Office details are below:" << endl;
			outFile << serviceLine << endl;
		}
		else if (searching == option6)
		{
			std::cout << "Personal Information details are below:" << endl;
			std::cout << "Type 1 for marriage information." << endl;
			std::cout << "Type 2 for birth information." << endl;
			std::cout << "Type 3 for children information." << endl;
			std::cout << "Type 4 for fraternity." << endl;
			std::cout << "Type 5 for parents." << endl;
			cin >> personalType;
			while (getline(inFile, newLine))
			{ // gets lines
				if (newLine.empty())
				{
					continue; // sends back if line is empty
				}
				else
				{
					stringstream series(newLine);
					while (series >> words)
					{ // takes in line as string
						if (searching == option6)
						{
							line_count++;
							if (error != true)
							{
								if (holder == newLine)
								{
									continue;
								}
								else if (line_count <= 104)
								{
									continue;
								}
								else
								{
									personalLine += newLine;
									personalLine += "\n";
									holder = newLine;
								}
							}
						}
					}
				}
			}
			if (personalType == 1)
			{
				regex searchFile("Marr[\a-zA-Z]+?[,]");
				smatch matching;
				if (regex_search(personalLine, matching, searchFile))
				{
					for (auto find : matching)
					{
						std::cout << find << endl;
						outFile << "The name is: " << endl;
						outFile << find << endl;
					}
				}
			}
			if (personalType == 2)
			{
				regex searchFile("Born [\a-zA-Z]*?[\r\n]");
				smatch matching;
				if (regex_search(personalLine, matching, searchFile))
				{
					for (auto find : matching)
					{
						std::cout << find << endl;
						outFile << "The birth information is: " << endl;
						outFile << find << endl;
					}
				}
			}
			if (personalType == 3)
			{
				regex searchFile("\\w+(?=\\s+children)[\a-zA-Z]*?[\r\n]");
				smatch matching;
				if (regex_search(personalLine, matching, searchFile))
				{
					for (auto find : matching)
					{
						std::cout << find << endl;
						outFile << "The children are: " << endl;
						outFile << find << endl;
					}
				}
			}
			if (personalType == 4)
			{
				regex searchFile("\\w+(?=.*Frat)[\a-zA-Z]*?[\r\n]");
				smatch matching;
				if (regex_search(personalLine, matching, searchFile))
				{
					for (auto find : matching)
					{
						std::cout << find << endl;
						outFile << "The fraternity he joined is: " << endl;
						outFile << find << endl;
					}
				}
			}
			if (personalType == 5)
			{
				regex searchFile("\\w+(?=.*late)[\a-zA-Z]*?[\r\n]");
				smatch matching;
				if (regex_search(personalLine, matching, searchFile))
				{
					for (auto find : matching)
					{
						outFile << "The parents are: " << endl;
						outFile << find << endl;
					}
				}
			}
		}
		else
		{
			std::cout << "You have encountered an error." << endl;
			error = true;
		}
		outFile.close();
	}
}