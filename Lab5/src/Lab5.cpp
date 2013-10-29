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
void yearlyTotal(int& total, int yearAmount);
/**
* This method compares the currentBestTotal and the total. If the total is larger than the
* currentBestTotal, it changes the currentBestMonth to the month.
*/
void yearStatistics(int& curretnBestYear, int& currentBestYearTotal, int year, int total);
/**
 * This method gives the monthly stats for the
 */
void monthStatistics(int (&years)[3], int& currentBestMonthYear, int& currentBestMonth, int& currentBestMonthTotal, int year, int month, int total);

int main() {
    /**
     * Declare the variables that we will be using.
     */
    int lastYear = -1;
    int bestMonth = 0;
    int bestMonthYear = 0;
    int bestMonthTotal = 0;
    int bestYear = 1;
    int bestYearTotal = 0;
    int maxYear = -1;
    int yearTotal[3];

    int currentYear = 0;
    int currentMonth = 0;
    int currentMonthTotal = 0;

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
    while (inputFile >> currentYear >> currentMonth >> currentMonthTotal) {
    	if(lastYear != currentYear) {
    		maxYear++;
    		outputFile << currentYear << " ";
    	} else {
    		outputFile << "\t ";
    	}
    	outputFile << writeMonth(currentMonth) << " | " << drawBar(currentMonthTotal) << " ~ " << currentMonthTotal << " in" << endl;
    	monthStatistics(yearTotal, bestMonthYear, bestMonth, bestMonthTotal, currentYear, currentMonth, currentMonthTotal);
    	yearStatistics(bestYear, bestYearTotal, currentYear, yearTotal[maxYear]);
    	lastYear = currentYear;
    }
    outputFile << getFooter();
    for(int index = 0; index <= maxYear; index++) {
    	outputFile << "The total for " << index + 2000 << " was " << yearTotal[index] << "." << endl;
    }
    outputFile << "The best month had " << bestMonthTotal << " for the year " << bestMonthYear << " with the total rainfall of " << writeMonth(bestMonth) << endl;
    outputFile << "The best Year of " << bestYear << " had " << bestYearTotal << " inches.";

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
    return "               |___________________________________________________\n               | ****1****2****3****4****5****6****7****8****9****10\n";
}

/**
 * This method takes a pointer for the total rainfall so far and adds the monthAmount to it.
 */
void yearlyTotal(int& total, int yearAmount) {
    total += yearAmount;
}

/**
 * This method compares the currentBestTotal and the total. If the total is larger than the
 * currentBestTotal, it changes the currentBestMonth to the month.
 */
void yearStatistics(int& curretnBestYear, int& currentBestYearTotal, int year, int total) {
    if (total > currentBestYearTotal) {
    	curretnBestYear = year;
    	currentBestYearTotal = total;
    }
}

/**
 * This method compares the currentBestTotal and the total. If the total is larger than the
 * currentBestTotal, it changes the currentBestMonth to the month.
 */
void monthStatistics(int (&years)[3], int& currentBestMonthYear, int& currentBestMonth, int& currentBestMonthTotal, int year, int month, int total) {
	if(years[year - 2000] < 0) {
		years[year - 2000] = 0;
	}
	years[year - 2000] += total;
    if (total > currentBestMonthTotal) {
        currentBestMonthTotal = total;
        currentBestMonthYear = year;
        currentBestMonth = month;
    }
}
