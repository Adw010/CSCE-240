#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <regex>
#include "./FactorialMath.h"
#include <chrono>
using namespace std;

FactorialMath ::~FactorialMath(){};

FactorialMath ::FactorialMath()
{
}

void FactorialMath::math(long long numberenter)
{
    cout << "FactorialFun " << numberenter << endl;
    auto start = std::chrono::steady_clock::now();
    long long answer = 1;
    answer = factorial(numberenter);
    auto end = std::chrono::steady_clock::now();
    auto elapsed_time = end - start;
    std::chrono::duration<double> diff_in_seconds = end - start;
    cout << "Factorial of " << numberenter << " is " << answer << "." << endl;
    cout << "Time for processing: " << diff_in_seconds.count() << " seconds." << endl;
   
}

long long FactorialMath::factorial(long long numberenter)
{
    long long answer = 1;
    for (long long i = 1; i <= numberenter; i++)
    {
        answer = answer * i;
    }
    return answer;
}

long long FactorialMath::combinational(long long numberenter, long long number)
{
    cout << "FactorialFun " << numberenter << " " << number << endl;
    long long answer = 1;
    long long a = 0;
    long long b = 0;
    long long c = numberenter - number;
    auto start = std::chrono::steady_clock::now();
    a = factorial(numberenter);
    b = factorial(number);
    c = factorial(c);
    answer = (a / (b * c));
    auto end = std::chrono::steady_clock::now();
    auto elapsed_time = end - start;
    std::chrono::duration<double> diff_in_seconds = end - start;
    cout << "Combinational Analysis is " << answer << "." << endl;
    cout << "Time for processing: " << diff_in_seconds.count() << " seconds." << endl;
    
    return answer;
}