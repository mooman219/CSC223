#include <new>
#include <iostream>
#include <cctype>
#include <cstdlib>
#include <fstream>
#include <string>
#include <math.h>

using namespace std;

int getTotalWords(char const (& currentLine)[16]) {
    int indexLine = 0;
    int totalWords = 0;
    while(currentLine[indexLine] != '\0') {
        if(isspace(currentLine[indexLine])) {
            totalWords++;
        }
        ++indexLine;
    }
    return totalWords;
}

char * getWord(char const (& currentLine)[16], int const & desiredWord) {
    char* word = new char[16];
    int indexLine = 0;
    int indexChar = 0;
    int indexWord = 0;
    while(currentLine[indexLine] != '\0') {
        if(isspace(currentLine[indexLine])) {
            indexWord++;
        } else if(desiredWord == indexWord) {
            word[indexChar] = currentLine[indexLine];
            indexChar++;
        }
        ++indexLine;
    }
    return word;
}

double calculateTwo(char const (& currentLine)[16]) {
    double firstNumber = atof(getWord(currentLine, 0));
    double secondNumber = atof(getWord(currentLine, 1));
    switch(getWord(currentLine, 2)[0]) {
    case '+':
        return firstNumber + secondNumber;
    case '-':
        return firstNumber - secondNumber;
    case '*':
        return firstNumber * secondNumber;
    case '/':
        return firstNumber / secondNumber;
    case '%':
        return static_cast<int>(firstNumber) % static_cast<int>(secondNumber);
    case '^':
        return pow(firstNumber, secondNumber);
    default:
        return 0;
    }
}

double calculateOne(char const (& currentLine)[16]) {
    double number = atof(getWord(currentLine, 0));
    switch(tolower(getWord(currentLine, 1)[0])) {
    case 't':
        return tan(number);
    case 'c':
        return cos(number);
    case 's':
        return sin(number);
    default:
        return 0;
    }
}

char modeToPrint(char const (& currentLine)[16]) {
    switch(tolower(getWord(currentLine, 0)[0])) {
    case 'f':
        cout.setf(cout.cur);
        return 'f';
    case 'e':
        cout.setf(cout.scientific);
        return 'e';
    default:
        return '?';
    }
}

int main() {
    char currentLine[16];
    ifstream inputFile;
    ofstream outputFile;
    inputFile.open("PFN.txt");
    while(inputFile.getline(currentLine, 16)) {
        switch(getTotalWords(currentLine)) {
        case 3:
            cout << currentLine << "  == " << calculateTwo(currentLine);
            break;
        case 2:
            cout << currentLine << "  == " << calculateOne(currentLine);
            break;
        case 1:
            cout << currentLine << "  == " << modeToPrint(currentLine);
            break;
        default:
            break;
        }
        cout << endl;
    }
    return 0;
}
