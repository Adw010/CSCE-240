#include "../../prog5-sessionlogger/src/headers/Chatsession.h"
#include <stdio.h>
#include <stdlib.h>
#include <regex>
#include <string>
#include <fstream>
#include <iostream>
#include <chrono>
#include <iomanip>
#include <ctime>
using namespace std;

Chatsession ::~Chatsession(){};

Chatsession ::Chatsession(){};

void Chatsession ::counter(string inputfile)
{
    ifstream inFile;
    string path = "../../prog5-sessionlogger/Data/chat_sessions/";
    string extension = ".txt";
    path += inputfile;
    path += extension;
    inFile.open(path);
    if (inFile.fail())
    {
        cout << "failed" << endl;
    }
    else
    {
        while (getline(inFile, newLine))
        {
            stringstream series(newLine);
            while (series >> words)
            {
                if (words == "CPU")
                {
                    outputnumto++;
                }
                else if (words == "User")
                {
                    inputnumto++;
                }
                else
                {
                }
            }
        }
    }
}

void Chatsession ::noteOutput(string typing, string str)
{

    string path = "../../prog5-sessionlogger/Data/chat_sessions/";
    string extension = ".txt";
    path += str;
    path += extension;
    ofstream outputfile;
    outputfile.open(path, fstream::app);
    outputfile << typing << "\n"
               << endl;
    outputfile.close();
}

void Chatsession ::timeStart()
{
    start;
}

void Chatsession ::timeEnd(string file)
{
    ofstream statfile;
    auto end = std::chrono::steady_clock::now();
    auto elapsed_time = end - start;
    std::chrono::duration<double> diff_in_seconds = end - start;
    statfile.open("../../prog5-sessionlogger/Data/chat_sessions/chat_statistics.csv", fstream::app);
    std::string stating = file;
    stating += ",";
    stating += std::to_string(inputnumto);
    stating += ",";
    stating += std::to_string(outputnumto);
    stating += ",";
    stating += std::to_string(diff_in_seconds.count());
    statfile << stating << endl;
    statfile.close();
}
