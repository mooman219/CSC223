/*
 Ben Staffan & Joe Cumbo
 Due: 9-26-2013
 Program Description:
 */

#include <iostream>
#include <fstream>
#include <string>
#include <cmath>

using namespace std;
const int MONTHS_IN_YEAR = 12;

/**
 * input month with an integer and then writes month as a string
 */
void writeMonth(int monthNumber, string monthName);

void getInput(int monthNumber, int rainAmount);

void monthlyTotal(int sum, int rainAmount);

void drawbar(const int asterisks, string monthName);

void drawScaleLine(int n);

void statistics(int stats);

int main()
{
    /**
    * Read input
    */
    string line;
    ifstream inputFile("rainInput.txt");
    if (inputFile.is_open())
    {
        while (getline(inputFile, line))
        {
            cout << line << endl;

        }
        inputFile.close();
    }
    else
    {
        cout << "Unable to open file";
    }
    /**
    * Write to output
    */
    ofstream outputFile("rainOutput.txt");
    if (outputFile.is_open())
    {
        outputFile << "This is a line.\n";
        outputFile << "This is another line.\n";
        outputFile.close();
    }
    else
    {
        cout << "Unable to open file";
    }
}

void writeMonth(int monthNumber, string monthName)
{
    switch (monthNumber)
    {
    case 1: monthName = "January";
        break;
    case 2: monthName = "February";
        break;
    case 3: monthName = "March";
        break;
    case 4: monthName = "April";
        break;
    case 5: monthName = "May";
        break;
    case 6: monthName = "June";
        break;
    case 7: monthName = "July";
        break;
    case 8: monthName = "August";
        break;
    case 9: monthName = "September";
        break;
    case 10: monthName = "October";
        break;
    case 11: monthName = "November";
        break;
    case 12: monthName = "December";
        break;
   }
}

void getInput(int monthNumber, int rainAmount)
{
    
}


void monthlyTotal(int sum, int rainAmount)
{
    sum = 0;
    sum = sum + rainAmount;

}

void drawBar(const int asterisks, string monthName, int monthNumber)
{


    for (monthNumber; monthNumber <= MONTHS_IN_YEAR; monthNumber++)
    {
        cout << monthName;
        drawScaleLine(asterisks);
    }
}

void drawScaleLine(int n)
{
    for (int count = 1; count <= n; count++)
        cout << "*";

}

void statistics(int stats)
{
}