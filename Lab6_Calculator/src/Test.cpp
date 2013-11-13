#include <new>
#include <iostream>
#include <cctype>
#include <cstdlib>
#include <fstream>
#include <string>
#include <math.h>

using namespace std;

/**Pre/Post**************************************************************
 *Pre: takes in a char value from the array currentLine. Runs through If*
 *Pre: statement and counting and tallying the word count.				*												*
 * 																		*
 *Post:Returns an int total word count.									*																	*
 ***********************************************************************/

int getTotalWords(char const (& currentLine)[16]);
/**Pre/Post**************************************************************
 *Pre: Takes in a char value from the array, and also an int value for  *
 *Pre: desired word length. Then makes a new array through the char*    *
 *Pre: word pointer.													*
 *																		*
 *Post: Calculates the word number and returns a double.				*																*																		*
 ***********************************************************************/

char * getWord(char const (& currentLine)[16], int const & desiredWord);

/**Pre/Post**************************************************************
 *Pre: Will take in char value and check for what kind of operand is	*
 *Pre: being used, then will put the operand back in PFN form.			*
 * 																		*
 *Post:returns an oppropriate operand for the case 						*
 * 																		*
 ***********************************************************************/
double calculateTwo(char const (& currentLine)[16]);

/**Pre/Post**************************************************************
 *Pre: Inputs a char value to determine the function that will be taken *
 *Pre:  on the number in the line.										*
 * 																		*
 *Post: Returns a double of the number run through the trig function.	*
 * 																		*
 ***********************************************************************/
double calculateOne(char const (& currentLine)[16]);

/**Pre/Post**************************************************************
 *Pre: Takes in a char and processes what form to print out as, 		*
 *Pre: fixed or scientific.												*
 * 																		*
 *Post: returns e ,f , or ? to be used in the main program to show 		*
 *Post: the final letter in main. 										*
 ***********************************************************************/
char modeToPrint(char const (& currentLine)[16]);

/**Pre/Post**************************************************************
 * Pre: Takes a char from the array and a double and puts it in a for   *
 * loop.																*
 * 																		*
 * Post: Outputs the line and number in console.						*
 ***********************************************************************/

void print(char const (& currentLine)[16], const double & number);

/**Pre/Post**************************************************************
 *Pre: takes in a char value from the array currentLine. Runs through If*
 *Pre: statement and counting and tallying the word count.				*												*
 * 																		*
 *Post:Returns an int total word count.									*																	*
 ***********************************************************************/
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

/**Pre/Post**************************************************************
 *Pre: Takes in a char value from the array, and also an int value for  *
 *Pre: desired word length. Then makes a new array through the char*    *
 *Pre: word pointer.													*
 *																		*
 *Post: Calculates the word number and returns a double.				*																*																		*
 ***********************************************************************/
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

/**Pre/Post**************************************************************
 *Pre: Will take in char value and check for what kind of operand is	*
 *Pre: being used, then will put the operand back in PFN form.			*
 * 																		*
 *Post:returns an oppropriate operand for the case 						*
 * 																		*
 ***********************************************************************/
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

/**Pre/Post**************************************************************
 *Pre: Inputs a char value to determine the function that will be taken *
 *Pre:  on the number in the line.										*
 * 																		*
 *Post: Returns a double of the number run through the trig function.	*
 * 																		*
 ***********************************************************************/
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

/**Pre/Post**************************************************************
 *Pre: Takes in a char and processes what form to print out as, 		*
 *Pre: fixed or scientific.												*
 * 																		*
 *Post: returns e ,f , or ? to be used in the main program to show 		*
 *Post: the final letter in main. 										*
 ***********************************************************************/
char modeToPrint(char const (& currentLine)[16]) {
    switch(tolower(getWord(currentLine, 0)[0])) {
    case 'f':
        cout << std::fixed;
        return 'f';
    case 'e':
        cout << std::scientific;
        return 'e';
    default:
        return '?';
    }
}

/**Pre/Post**************************************************************
 * Pre: Takes a char from the array and a double and puts it in a for   *
 * loop.																*
 * 																		*
 * Post: Outputs the line and number in console.						*
 ***********************************************************************/

void print(char const (& currentLine)[16], const double & number) {
    for(int i = 0; currentLine[i + 1] != '\0'; i++) {
        cout << currentLine[i];
    }
    cout << "    = " << number;
}

/**Pre/Post**************************************************************
 * 	The main function, it takes all the info the other functions		*
 * 	It will then print out the currentLine and following output.		*
 *  Finally as always it will return 0 to end the program				*
 * 																		*
 * 																		*
 * 																		*
 ***********************************************************************/
int main() {
    char currentLine[16];
    ifstream inputFile;
    ofstream outputFile;
    inputFile.open("PFN.txt");
    while(inputFile.getline(currentLine, 16)) {
        switch(getTotalWords(currentLine)) {
        case 3:
            print(currentLine, calculateTwo(currentLine));
            break;
        case 2:
            print(currentLine, calculateOne(currentLine));
            break;
        case 1:
            cout << modeToPrint(currentLine);
            break;
        default:
            break;
        }
        cout << endl;
    }
    return 0;
}
