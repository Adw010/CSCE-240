// Antonio Turner Homework 5
// CSCE 240

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <regex>
#include "./FactorialMath.cpp"
using namespace std;

bool holder = false;
string cap;

bool isNumber(string num)
{
    for (int i = 0; i < num.length(); i++)
    {
        if (isdigit(num[i]) == false)
        {
            return false;
        }
    }
    return true;
}

int main()
{
    FactorialMath x;
    string input;
    string input2;
    long long n = 0;
    long long b = 0;
    long long choice = 0;
    cout << "Would you like to do the Factorial or Combinational Math?" << endl;
    cout << "Enter 1 for Factorial. Enter 2 for Combinational." << endl;
    cin >> choice;

    if (choice == 1)
    {
        cout << "Please enter a number for your factorial: ";
        cin >> input;
        if (isNumber(input) == true)
        {
            n = stoi(input);
            if (n < 0)
            {
                cout << "Error, the number entered should not be a negative." << endl;
                main();
            }
            else if (n == 0)
            {
                cout << "Factorial of " << n << " is 1." << endl;
            }
            else if (n == 1)
            {
                cout << "Factorial of " << n << " is 1." << endl;
            }
            else if (n >= 21)
            {
                cout << "Sorry this laptop cannot process 21 and over factorial due to bit size." << endl;
                main();
            }
            else if (n > 0)
            {
                x.math(n);
            }
            else
            {
                cout << "Please just enter one positive number." << endl;
                main();
            }
        }
        else
        {
            cout << "Please just enter one positive number." << endl;
            main();
        }
    }
    else if (choice == 2)
    {
        cout << "Please enter the first number for your combinational analysis: ";
        cin >> input;
        cout << "Please enter the second number for your combinational analysis: ";
        cin >> input2;
        if (isNumber(input2) == true && isNumber(input) == true)
        {
            b = stoi(input2);
            n = stoi(input);
            int checking = n + 1;
            if (b > 0 && b < n)
            {

                if (n < 0)
                {
                    cout << "Error, the number entered should not be a negative." << endl;
                    main();
                }
                else if (n == 0)
                {
                    cout << "Combinational of " << n << " and " << b << " is 1." << endl;
                }
                else if (n == 1)
                {
                    cout << "Combinational of " << n << " and " << b << " is " << b << "." << endl;
                }
                else if (n >= 21)
                {
                    cout << "Sorry this laptop cannot process 21 and over factorial due to bit size." << endl;
                    main();
                }
                else if (n > 0)
                {
                    x.combinational(n, b);
                }
                else
                {
                    cout << "Please enter a postive number for a and b." << endl;
                    main();
                }
            }
            else if (b == 0)
            {
                cout << "Combinational of " << n << " and " << b << " is 1." << endl;
            }
            else if (b == 1)
            {
                cout << "Combinational of " << n << " and " << b << " is " << n << "." << endl;
            }
            else if (b == n){
                cout << "Combination of " << n << " and " << b << " is 1." << endl;
            }
            else if (b > n)
            {
                cout << "Sorry the second number cannot be larger than the first." << endl;
                main();
            }
            else
            {
                cout << "Please enter a postive number for a and b." << endl;
                main();
            }
        }
        else
        {
            cout << "Please enter a postive number for a and b." << endl;
            main();
        }
    }
    else
    {
        cout << "Error, please choose 1 or 2." << endl;
    }
}
