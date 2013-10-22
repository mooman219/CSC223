#include <memory>
#include <string>
#include <iostream>
#include <fstream>
using namespace std;

/**
* This method takes in a month number and returns the name of that month.
*/
string writeMonth(int monthNumber);
/**
* This menthod takes in the number of inches and returns a string with 4 asterisks for
* each inch.
*/
string drawBar(int inches);
/**
* This method returns the footer for the graph. The footer includes the scale.
*/
string getFooter();
/**
* This method takes a pointer for the total rainfall so far and adds the monthAmount to it.
*/
void monthlyTotal(int& total, int monthAmount);
/**
* This method compares the currentBestTotal and the total. If the total is larger than the
* currentBestTotal, it changes the currentBestMonth to the month.
*/
void statistics(int& currentBestMonth, int& currentBestTotal, int month, int total);

int main() {
    /**
     * Declare the variables that we will be using.
     */
    int month = 0;
    int monthTotal = 0;
    int totalRain = 0;
    int bestMonth = 1;
    int bestMonthTotal = 0;

    /**
     * Open the files
     */
    ifstream inputFile;
    ofstream outputFile;
    inputFile.open("rainInput.txt");
    outputFile.open("rainOutput.txt");

    /**
     * Calculate the total rain and best month and print out the stats for the month.
     */
    while (inputFile >> month >> monthTotal) {
        outputFile << writeMonth(month) << " | " << drawBar(monthTotal) << " ~ " << monthTotal << " in" << endl;
        monthlyTotal(totalRain, monthTotal);
        statistics(bestMonth, bestMonthTotal, month, monthTotal);
    }
    outputFile << getFooter();
    outputFile << "The total rain amount was " << totalRain << " inches." << endl;
    outputFile << "The best month had " << bestMonthTotal << " inches and was " << writeMonth(bestMonth);

    /**
     * Close the files.
     */
    inputFile.close();
    outputFile.close();
    return 0;
}

/**
 * This method takes in a month number and returns the name of that month.
 */
string writeMonth(int monthNumber) {
    switch (monthNumber) {
    case 1:
        return "January  ";
    case 2:
        return "February ";
    case 3:
        return "March    ";
    case 4:
        return "April    ";
    case 5:
        return "May      ";
    case 6:
        return "June     ";
    case 7:
        return "July     ";
    case 8:
        return "August   ";
    case 9:
        return "September";
    case 10:
        return "October  ";
    case 11:
        return "November ";
    case 12:
        return "December ";
    default:
        return "Error    ";
    }
}

/**
 * This menthod takes in the number of inches and returns a string with 4 asterisks for
 * each inch.
 */
string drawBar(int inches) {
    string asterisks;
    for (int i = 0; i < inches; i++) {
        asterisks += "*****";
    }
    return asterisks;
}

/**
 * This method returns the footer for the graph. The footer includes the scale.
 */
string getFooter() {
    return "          |______________________________________________\n          | ****1****2****3****4****5****6****7****8****9\n";
}

/**
 * This method takes a pointer for the total rainfall so far and adds the monthAmount to it.
 */
void monthlyTotal(int& total, int monthAmount) {
    total += monthAmount;
}

/**
 * This method compares the currentBestTotal and the total. If the total is larger than the
 * currentBestTotal, it changes the currentBestMonth to the month.
 */
void statistics(int& currentBestMonth, int& currentBestTotal, int month, int total) {
    if (total > currentBestTotal) {
        currentBestTotal = total;
        currentBestMonth = month;
    }
}
