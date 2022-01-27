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

	double y, z, w; //variables for numbers
	string x, v;//variables for operand

	inFile >> x >> y >> z >> w; //assigns lines to variables

	cout << "Would you like to perform the area or perimeter?" <<endl;
	cin >> v;

	if (v == "area" || v == "Area") {

		if (x == "rectangle" || x == "Rectangle") {
				a = y * z;
		}//looks for rectangle area

		else if (x == "triangle" || x == "Triangle") {
					cout << "you cannot do the area of the triangle in c++"<< endl;
		}//looks for triangle area

		else if (x == "circle" || x == "Circle") {
					a = 3.14 * (y * y);
		}//looks for circle area

		else {

			inputFailure = true;

		}
		if (inputFailure == true) {

				cout << "Please enter rectangle, Rectangle, Circle, circle, Triangle or triangle" <<endl;
		}
		else {
			cout << "Below is the " << v << " for a " << x << endl;
			cout << "Calculator function is: " << v << endl; //prints
			cout << v << " is: " << a << endl; //prints final number

			inFile.close();//closes file

			std::ofstream outFile {"output.txt"};//calls file for edit

			outFile << "The result of " << x << " and " << v << " is below." << std::endl;//prints sentence to new file
			outFile << a << std::endl;//prints answer to new file

			outFile.close();//closes output file
		}

	}
	else if (v == "Perimeter" || v == "perimeter") {

			if (x == "rectangle" || x == "Rectangle") {
					a = (y + z) * 2;
			}//looks for rectangle area

			else if (x == "triangle" || x == "Triangle") {
					a = (y + z) + w;
			}//looks for triangle area

			else if (x == "circle" || x == "Circle") {
						a = 3.14 * (y * 2);
			}//looks for circle area


			else {

					inputFailure = true;

			}

			if (inputFailure == true) {

					cout << "Please enter rectangle, Rectangle, Circle, circle, Triangle or triangle" <<endl;
				}
				else {
				cout << "Below is the " << v << " for a " << x << endl;
				cout << "Calculator function is: " << v << endl; //prints
				cout << v << " is: " << a << endl; //prints final number

				inFile.close();//closes file

				std::ofstream outFile {"output.txt"};//calls file for edit

				outFile << "The result of " << x << " and " << v << " is below." << std::endl;//prints sentence to new file
				outFile << a << std::endl;//prints answer to new file

				outFile.close();//closes output file
				}

		}

	else {
		cout << "invalid input. please say perimeter, Perimeter, Area or area." << endl;
	}


	return 0;
}




