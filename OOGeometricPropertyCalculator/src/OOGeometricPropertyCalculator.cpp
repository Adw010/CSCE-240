// CSCE 240
#include "./Circle.cpp"
#include "./Rectangle.cpp"
#include "./Triangle.cpp"
#include "./Shape.cpp" 
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
using namespace std;

string newLine;
string error = "Sorry, there was an error";
int line2;
int line3;
int line4;
int function1 = 0;
double area;
double perimeter;


int main()
{

    ifstream newFile("input.txt");
    if (newFile.is_open())
    {
        cout << "We have the file ready." << endl;
    }
    else
    {
        cout << "Please fix your file." << endl;
    }
    string newLine;

    while (getline(newFile, newLine))
    {
        newFile >> line2 >> line3 >> line4;
    }
    newFile.close();

    for_each(newLine.begin(), newLine.end(), [](char &c)
             { c = ::tolower(c); });

    cout << newLine << endl;

    cout << " If you would like the Area, you must enter 1. If you would like the Perimeter, you must enter 2." << endl;
    cin >> function1;

    if (function1 == 1)
    {
        ofstream outputFile;
        outputFile.open("output.txt");

        Rectangle rect = Rectangle();
        Triangle tria = Triangle();
        Circle circ = Circle();

        if (newLine == "rectangle")
        {
            area = rect.getArea(line2, line3);
            outputFile << "The area is " << area << endl;
        }
        else if (newLine == "triangle")
        {
            tria.getErrorMessage();
            outputFile << error << endl;
        }
        else if (newLine == "circle")
        {
            area = circ.getArea(line2, line3);
            outputFile << "The area is " << area << endl;
        }
        else
        {
            tria.getErrorMessage();
            outputFile << error << endl;
        }
        outputFile.close();
        cout << "Input recieved. Check your output file." << endl;
    }

    else if (function1 == 2)
    {
        ofstream outputFile;
        outputFile.open("output.txt");

        Rectangle rect = Rectangle();
        Triangle tria = Triangle();
        Circle circ = Circle();

        if (newLine == "rectangle")
        {
            perimeter = rect.getPerimeter(line2, line3, line4);
            outputFile << "The perimeter is " << perimeter << endl;
        }
        else if (newLine == "triangle")
        {
            perimeter = tria.getPerimeter(line2, line3, line4);
            outputFile << "The perimeter is " << perimeter << endl;
        }
        else if (newLine == "circle")
        {
            perimeter = circ.getPerimeter(line2, line3, line4);
            outputFile << "The perimeter is " << perimeter << endl;
        }
        else
        {
            tria.getErrorMessage();
        }
        outputFile.close();
        cout << "Input recieved. Check your output file." << endl;
    }
    else {
        cout << error << endl;
    }
}
