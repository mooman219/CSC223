/*
 Ben Staffan & Joe Cumbo
 Due: 9-26-2013
 Program is intended to ask user for loan amount, monthly balance,
 and interest rate. Then uses the information to give total interest, number of months
 it will take to pay off the loan, annualized interest rate, and percentage of the annual interest to the loan.
 */

#include <iostream>

using namespace std;

void calculateLoan() {
    double originalLoanAmount;
    double loanAmount;
    double userMonthlyPayment;
    double userYearlyInterestRate;
    double monthlyInterestRate;
    double monthlyMinimumPayment;
    int totalMonths = 0;
    double totalInterestPaid = 0;
    double tempInterest;
    double tempPrinciple;
    double annualizedInterest;
    double percentAnnualInterest;

    // Get the loan amout from the user
    cout << "Loan Amount: $";
    cin >> loanAmount;
    originalLoanAmount = loanAmount;
    //

    // Get the yearly interest rate from the user
    cout << "Yearly Interest Rate: ";
    cin >> userYearlyInterestRate;
    //

    monthlyInterestRate = userYearlyInterestRate / 12;
    monthlyMinimumPayment = loanAmount * monthlyInterestRate;

    // Get the monthly payment from the user. Make sure that the
    // amount they enter is above the minimum monthly payment.
    cout << "You need a minimum monthly payment of [" << monthlyMinimumPayment << "$]" << endl;
    do {
        cout << "Monthly Payent: $";
        cin >> userMonthlyPayment;
    } while (userMonthlyPayment < monthlyMinimumPayment);
    //

    // Output what the user submitted
    cout << endl << "Loan Amount: $" << loanAmount << endl;
    cout << "Interest Rate: " << userYearlyInterestRate << "%" << endl;
    //

    cout << "Month \t Monthly-Balance \t Monthly-Payment \t Interest \t Principle" << endl;

    while (loanAmount > 0) {
        // Calculate interest, principle, and the monthly payment
        totalMonths++;
        tempInterest = loanAmount * monthlyInterestRate;
        if (userMonthlyPayment > loanAmount + tempInterest) {
            userMonthlyPayment = loanAmount + tempInterest;
        }
        tempPrinciple = userMonthlyPayment - tempInterest;
        totalInterestPaid += tempInterest;
        //

        // Display the current month, current loan amount, monthly payment, interest, and the principle
        cout << totalMonths << "  \t $" << loanAmount << " \t\t $" << userMonthlyPayment << " \t\t\t $" << tempInterest << " \t$" << tempPrinciple << endl;

        loanAmount = (loanAmount - userMonthlyPayment) + tempInterest;
    }

    annualizedInterest = totalInterestPaid / (totalMonths / 12.0);
    percentAnnualInterest = (annualizedInterest / originalLoanAmount) * 100;

    cout << endl << "Number of months to payoff loan: " << totalMonths << endl;
    cout << "Total interest paid: $" << totalInterestPaid << endl;
    cout << "Annulized Interest: $" << annualizedInterest << endl;
    cout << "Percent of the annualized interest from the loan: " << percentAnnualInterest << "%" << endl;

    // Restart code
    cout << "If you would like to coninute, enter the numeber 1: ";
    cin >> totalMonths;
    if (totalMonths == 1) {
        cout << endl << "The program is re-running." << endl;
        calculateLoan();
    } else {
        cout << endl << "The program will now exit.";
    }
    //
}

int main() {
    calculateLoan();
}

