/*
 Ben Staffan & Joe Cumbo
 Due: 9-26-2013
 Program is intended to ask user for loan amount, monthly balance,
 and interest rate. Then uses the information to give total interest, number of months
 it will take to pay off the loan, annualized interest rate, and percentage of the annual interest to the loan.
 */

#include <iostream>

using namespace std;

void intro();

double getLoanAmount();

double getYearlyInterestRate();

double getPaymentAmount(double monthlyMinimumPayment);

double calculateMinimumMonthlyPayment(double yearlyInterestRate, double loanAmount);

void calculateMonths(double loanAmount, double monthlyInterestRate, double monthlyPayment);

void displayResult(int totalMonths, double totalInterestPaid, double annualizedInterest, double percentAnnualInterest);

void restart();

int main() {
    intro();
    double userLoanAmount = getLoanAmount();
    double userYearlyInterestRate = getYearlyInterestRate();

    /**
     * Calculate the monthly interest rate from the yearly interest rate.
     * Also calculate the monthly minimum payment from the monthly interest rate.
     */
    double monthlyInterestRate = userYearlyInterestRate / 12;
    double monthlyMinimumPayment = calculateMinimumMonthlyPayment(userYearlyInterestRate, userLoanAmount);

    double userPaymentAmount = getPaymentAmount(monthlyMinimumPayment);

    /**
     * Output what the user submitted
     */
    cout << endl << "Loan Amount: $" << userLoanAmount << endl;
    cout << "Interest Rate: " << userYearlyInterestRate << "%" << endl;

    calculateMonths(userLoanAmount, monthlyInterestRate, userPaymentAmount);
    restart();
}

void intro() {
    cout << "This program will prompt the user for a loan amount, yearly interest rate, and monthly payment." << endl;
    cout << "It will then iterate though each month, displaying the status of the loan for each month" << endl;
    cout << "Once the program completes, it will display the total months to pay off the loan," << endl;
    cout << "the total interest paid, annualized interest, and percent of the annualized interest from the load." << endl;
}

/**
 * Get the loan amout from the user
 */
double getLoanAmount() {
    cout << "Loan Amount: $";
    double enteredLoanAmount;
    cin >> enteredLoanAmount;
    return enteredLoanAmount;
}

/**
 * Get the yearly interest rate from the user
 */
double getYearlyInterestRate() {
    cout << "Yearly Interest Rate: ";
    double enteredYearlyInterestRate;
    cin >> enteredYearlyInterestRate;
    return enteredYearlyInterestRate;
}

/**
 * Get the monthly payment from the user. Make sure that the
 * amount they enter is above the minimum monthly payment.
 */
double getPaymentAmount(double monthlyMinimumPayment) {
    double enteredMonthlyPayment;
    cout << "You need a minimum monthly payment of [" << monthlyMinimumPayment << "$]" << endl;
    do {
        cout << "Monthly Payent: $";
        cin >> enteredMonthlyPayment;
    } while (enteredMonthlyPayment < monthlyMinimumPayment);
    return enteredMonthlyPayment;
}

/**
 * This function takes a yearly interest rate and a loan amount and
 * returns the minimum monthly payment required to payoff the loan.
 */
double calculateMinimumMonthlyPayment(double yearlyInterestRate, double loanAmount) {
    return loanAmount * (yearlyInterestRate / 12.0);
}

/**
 * This function takes a loan amount, monthly interest rate, and a monthly payment.
 * The function then calculates and displays the status of the loan for each month
 * until the loan is paid off.
 */
void calculateMonths(double loanAmount, double monthlyInterestRate, double monthlyPayment) {
    int totalMonths = 0;
    double tempLoanAmount = loanAmount;
    double tempInterest = 0;
    double tempPrinciple = 0;
    double totalInterestPaid = 0;
    double annualizedInterest = 0;
    double percentAnnualInterest = 0;
    cout << "Month \t Monthly-Balance \t Monthly-Payment \t Interest \t Principle" << endl;
    /**
     * Continue while there is still loan to be repaid.
     */
    while (tempLoanAmount > 0) {
        /**
         * Calculate interest, principle, and the monthly payment
         */
        totalMonths++;
        tempInterest = tempLoanAmount * monthlyInterestRate;
        if (monthlyPayment > tempLoanAmount + tempInterest) {
            monthlyPayment = tempLoanAmount + tempInterest;
        }
        tempPrinciple = monthlyPayment - tempInterest;
        totalInterestPaid += tempInterest;

        /**
         * Display the current month, current loan amount, monthly payment, interest, and the principle
         */
        cout << totalMonths << "  \t $" << tempLoanAmount << " \t\t $" << monthlyPayment << " \t\t\t $" << tempInterest << " \t$" << tempPrinciple << endl;

        tempLoanAmount = (tempLoanAmount - monthlyPayment) + tempInterest;
    }

    annualizedInterest = totalInterestPaid / (totalMonths / 12.0);
    percentAnnualInterest = (annualizedInterest / loanAmount) * 100;

    displayResult(totalMonths, totalInterestPaid, annualizedInterest, percentAnnualInterest);
}

void displayResult(int totalMonths, double totalInterestPaid, double annualizedInterest, double percentAnnualInterest) {
    cout << endl << "Number of months to payoff loan: " << totalMonths << endl;
    cout << "Total interest paid: $" << totalInterestPaid << endl;
    cout << "Annualized Interest: $" << annualizedInterest << endl;
    cout << "Percent of the annualized interest from the loan: " << percentAnnualInterest << "%" << endl;
}

/**
 * Asks the user if they would like to restart the program.
 */
void restart() {
    int userAnswer = 0;
    cout << "If you would like to coninute, enter the numeber 1: ";
    cin >> userAnswer;
    if (userAnswer == 1) {
        cout << endl << "The program is re-running." << endl;
        main();
    } else {
        cout << endl << "The program will now exit.";
    }
}
