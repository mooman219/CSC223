#include <istream>
#include <string>
#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

enum InputType{INTEGER, DOUBLE, ADD, SUB, MULT, DIV, MOD, POW, TAN, SIN, COS, FIXED, SCI};

void modeToPrint(char mode) {
	switch(mode) {
	case 'f':
		break;
	case 'e':
		break;
	default:
		break;
	}
}

int main() {
	char currentLine[50];
    ifstream inputFile;
    ofstream outputFile;
    inputFile.open("PFN.txt");
    outputFile.open("Output.txt");
    while(inputFile.getline(currentLine, 50)) {
    	for(int index = 0; currentLine[index] != '\0'; index++){
    		cout << currentLine[index];
    	}
    	cout << endl;
    }
	return 0;
}
