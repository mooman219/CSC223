#include <istream>
#include <string>
#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

enum InputType {
    INTEGER,
    DOUBLE,
    ADD,
    SUB,
    MULT,
    DIV,
    MOD,
    POW,
    TAN,
    SIN,
    COS,
    FIXED,
    SCI,
    ERROR
};

void modeToPrint(char mode) {
    switch(tolower(mode)) {
    case 'f':
        break;
    case 'e':
        break;
    default:
        break;
    }
}

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

int main() {
    char currentLine[16];
    int maxWords = 0;
    ifstream inputFile;
    ofstream outputFile;
    inputFile.open("PFN.txt");
    while(inputFile.getline(currentLine, 16)) {
        maxWords = getTotalWords(currentLine);
        cout << "Words: " << maxWords << endl;
        for(int i = 0; i < maxWords; i++) {
            cout << getWord(currentLine, i) << " | ";
        }
        cout << endl;
    }
    return 0;
}
