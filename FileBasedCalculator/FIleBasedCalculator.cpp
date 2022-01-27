//CSCE 240

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {

	double a; //variable for answer
	string badInput = "I do not understand your operand.";
	bool inputFailure = false;

	ifstream inFile; //variable for file
	inFile.open("input.txt"); //opens file for input

	if (inFile.fail()) {
		cerr << "No file to open or couldn't open" << endl;
		exit(1);
	}//error catcher

	double y, z; //variables for numbers
	string x;//variables for operand

	inFile >> x >> y >> z; //assigns lines to variables

	cout << "First number: " << y << endl; //prints number 1
	cout << "Second number: " << z << endl;//prints number 2

	if (x == "add" || x == "Add") {
		a = y + z;
	}//looks for add

	else if (x == "subtract" || x == "Subtract") {
			a = y - z;
	}//looks for subtract

	else if (x == "multiply" || x == "Multiply") {
			a = y * z;
	}//looks for multiply

	else if (x == "divide" || x == "Divide") {
			a = y/z;
	}//looks for divide

	else {

		inputFailure = true;

	}


	cout << "Calculator function is: " << x << endl; //prints
	cout << "Final number is: " << a << endl; //prints final number

	inFile.close();//closes file

	std::ofstream outFile {"output.txt"};//calls file for edit

	outFile << "The result of " << x << "ing " << y << " and " << z << " is below." << std::endl;//prints sentence to new file
	outFile << a << std::endl;//prints answer to new file

	outFile.close();//closes output file

	return 0;
}


