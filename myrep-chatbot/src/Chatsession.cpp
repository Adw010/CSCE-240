#include "../../myrep-chatbot/src/headers/Chatsession.h"
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
    string path = "../../myrep-chatbot/Data/chat_sessions/";
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

    string path = "../../myrep-chatbot/Data/chat_sessions/";
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
    statfile.open("../../myrep-chatbot/Data/chat_sessions/chat_statistics.csv", fstream::app);
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

void Chatsession ::summary()
{
    int inputnum;
    string cname = "../../myrep-chatbot/Data/chat_sessions/chat_statistics.csv";

    vector<vector<string>> content;
    vector<string> row;
    string line, word;

    fstream file(cname, ios::in);
    if (file.is_open())
    {
        while (getline(file, line))
        {
            row.clear();
            inputnum++;
            stringstream str(line);

            while (getline(str, word, ','))
                row.push_back(word);
            content.push_back(row);
        }
    }
    else
    {
        cout << "Could not open the file\n";
    }

    for (int i = 0; i < content.size(); i++) // print whole
    {
        for (int j = 0; j < content[i].size(); j++)
        {
            cout << content[i][j] << " ";
        }
        cout << "\n";
    }
    file.close();
    inputnum--;
    cout << "Would you like a full summary, showchat, showchat summary or end? Press 1, 2, 3 or 4." << endl;
    int outputnum;
    cin >> outputnum;
    digit = std::isdigit(outputnum);
    if (digit = true)
    {
        if (outputnum == 1)
        {

            cout << "You selected to see the total stats: " << endl;
            for (int i = 1, j = 1; i < content.size(); i++) // get user session number
            {
                int convert = stoi(content[i][j]);
                usersess = usersess + convert;
            }
            for (int i = 1, j = 2; i < content.size(); i++) // get cpu session number
            {
                int convert = stoi(content[i][j]);
                cpusess = cpusess + convert;
            }
            for (int i = 1, j = 3; i < content.size(); i++) // get cpu session number
            {
                int convert = stoi(content[i][j]);
                timesess = timesess + convert;
            }
            cout << "Number of chats is: " << inputnum << "." << endl;
            cout << "Number of user chats is: " << usersess << "." << endl;
            cout << "Number of cpu chats is: " << cpusess << "." << endl;
            cout << "Total time from chats is about: " << timesess << " seconds." << endl;
        }
        else if (outputnum == 2)
        {

            cout << "Which chat log would you like to see? Note the limit is: " << inputnum << "." << endl;
            cin >> outputnum;
            digit = std::isdigit(outputnum);
            if (digit = true)
            {
                if (outputnum > inputnum)
                {
                    cout << "Error, there are only " << inputnum << " chats." << endl;
                    summary();
                }
                else if (outputnum == 0)
                {
                    cout << "Error, that is the title line." << endl;
                    summary();
                }
                else
                {
                    for (int i = 0; i < 1; i++)
                    {
                        for (int j = 0; j < content[i].size(); j++)
                        {
                            cout << content[outputnum][j] << " ";
                        }
                        cout << "\n";
                    }
                }
            }
            else
            {
                cout << "error" << endl;
                summary();
            }
        }
        else if (outputnum == 3)
        {
            cout << "Which chat summary would you like to see? Note the limit is " << inputnum << "." << endl;
            cin >> outputnum;
            digit = std::isdigit(outputnum);
            if (digit = true)
            {
                if (outputnum > inputnum)
                {
                    cout << "Error, there are only " << inputnum << " chats." << endl;
                }
                else if (outputnum == 0)
                {
                    cout << "Error, that is either the title line or not checkable." << endl;
                    summary();
                }
                else
                {
                    checking = content[outputnum][0];
                    printer(checking);
                }
            }
            else {
                cout << "error" << endl;
                summary();
            }
        }
        else if (outputnum == 4)
        {

            cout << "Thank you, the program will stop now." << endl;
            exit(EXIT_FAILURE);
        }
        else
        {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Sorry there was an error, we will go back." << endl;
            summary();
        }
    }
    else
    {
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "Bad input, starting over" << endl;
        summary();
    }
}

void Chatsession::printer(string inputfile)
{
    {

        ifstream inFile;
        string path = "../../myrep-chatbot/Data/chat_sessions/";
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
                if (newLine.empty())
                {
                    continue;
                }
                else
                {
                    stringstream series(newLine);
                    while (series >> words)
                    {
                        if (holder == newLine)
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
            }
        }
        inFile.close();
    }
}