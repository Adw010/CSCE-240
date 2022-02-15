#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

int main()
{
	string district, words, str, newLine;
	int wordnum = 0;
	int char_count = 0;
	int line_count = 0;

	cout << "What is your district? Please provide as District__.txt exactly with numbers inplace of lines. Be careful of capitalization." << endl;
	cin >> district;

	ifstream inFile;	   //variable for file
	inFile.open(district); //opens file for input

	if (inFile.fail())
	{
		cerr << "No file to open or couldn't open. Please restart" << endl;
		exit(1);
	} //error catcher

	while (getline(inFile, newLine)) //gets lines
	{
		line_count++; //counts number of line
		if (newLine.empty())
		{
			continue; //sends back if line is empty
		}
		else
		{
			stringstream series(newLine); //takes in line as string
			while (series >> words)	  // seperates the strings
			{
				wordnum += 1;							 //counts number of words
				for (int i = 0; i < words.length(); i++) //counts characters
				{
					char c = words[i];
					if (c != ' ')
					{
						char_count += 1;
					}
				}
			}
		}

		
	}
	inFile.close();
	std::ofstream outFile{"output.txt"}; //calls file for edit

	outFile << "The result of the file is below." << endl; //prints sentence to new file
	outFile << "line count = " << line_count << endl;
	outFile << "characters num = " << char_count << endl;
	outFile << "words number = " << wordnum << endl;

	outFile.close(); //closes output file
	cout << "line count = " << line_count << endl;
	cout << "characters num = " << char_count << endl;
	cout << "words number = " << wordnum << endl;
	return 0;
}
