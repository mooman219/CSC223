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

void writeMonth(int a[], int monthNumber);

void getInput(int a[], int rainAmount);

void monthlyTotal(int& sum);

void drawbar(const int asterisks[], int monthNumber);

void drawScaleLine(int n);

void statistics(int a[], int stats);

int main() {
    /**
     * Write to output
     */
    ofstream outputFile("rainOutput.txt");
    if (outputFile.is_open()) {
        outputFile << "This is a line.\n";
        outputFile << "This is another line.\n";
        outputFile.close();
    } else {
        cout << "Unable to open file";
    }

    /**
     * Read input
     */
    string line;
    ifstream inputFile("rainInput.txt");
    if (inputFile.is_open()) {
        while (getline(inputFile, line)) {
            cout << line << endl;
        }
        inputFile.close();
    } else {
        cout << "Unable to open file";
    }
}

