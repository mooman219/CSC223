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
void yearStatistics(int& currentBestYear, int& currentBestTotal, int month, int total);

int main() {
    /**
     * Declare the variables that we will be using.
     */

	int month[14];
	int year[14];
	int monthTotal[14];
	int months = 0;
	int years = 0;
	int monthTotals = 0;
    int totalRain = 0;
    int totalRainA = 0;
    int totalRainB = 0;
    int totalRainC = 0;
    int bestYear = 1;
    int bestYearTotal = 0;
    int x;
    int y;
    int z;

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
    while (inputFile >> years>> months>> monthTotals)
    {
    	year[x]=years;

    	month[y]=months;

    	monthTotal[z]=monthTotals;

        if(years==2000)
        {
        	totalRainA= totalRainA + monthTotal[z];
        }
        else if(years==2001)
        {
        	totalRainB= totalRainB + monthTotal[z];
        }
        else
		{
			totalRainC= totalRainC + monthTotal[z];
		}


        outputFile << years << writeMonth(month[y]) << " | " << drawBar(monthTotal[z]) << " ~ " << monthTotal[z] << " in" << endl;
        yearStatistics(bestYear, bestYearTotal, years, monthTotals);

        x++;
        y++;
        z++;

    }

    outputFile << getFooter();
    outputFile << "The total rain amount was " << totalRain << " inches." << endl;
    outputFile << "The best Year had " << bestYearTotal << " inches and was " << writeMonth(bestYear);

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
    return "              |______________________________________________\n              | ****1****2****3****4****5****6****7****8****9\n";
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
void yearStatistics(int& currentBestMonth, int& currentBestTotal, int theYear, int total) {
    if (total > currentBestTotal) {
        currentBestTotal = total;
        currentBestMonth = theYear;
    }
}
