#include <memory>
#include <string>
#include <iostream>
#include <fstream>
using namespace std;

string getMonth(int monthNumber) {
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

string getAsterisks(int inches) {
    string asterisks;
    for (int i = 0; i < inches; i++) {
        asterisks += "*****";
    }
    return asterisks;
}

string getFooter() {
    return "          |______________________________________________\n          | ****1****2****3****4****5****6****7****8****9\n";
}

void calculateTotalRain(int& total, int monthAmount) {
    total += monthAmount;
}

void calculateBestMonth(int& currentBestMonth, int& currentBestTotal, int month, int total) {
    if (total > currentBestTotal) {
        currentBestTotal = total;
        currentBestMonth = month;
    }
}

int main() {
    int month = 0;
    int monthTotal = 0;
    int totalRain = 0;
    int bestMonth = 1;
    int bestMonthTotal = 0;
    ifstream inputFile;
    ofstream outputFile;

    inputFile.open("rainInput.txt");
    outputFile.open("rainOutput.txt");
    while (inputFile >> month >> monthTotal) {
        cout << getMonth(month) << " | " << getAsterisks(monthTotal) << " ~ " << monthTotal << " in" << endl;
        calculateTotalRain(totalRain, monthTotal);
        calculateBestMonth(bestMonth, bestMonthTotal, month, monthTotal);
    }

    cout << getFooter();
    cout << "The total rain amount was " << totalRain << " inches." << endl;
    cout << "The best month had " << bestMonthTotal << " inches and was " << getMonth(bestMonth);
    inputFile.close();
    outputFile.close();
    return 0;
}
