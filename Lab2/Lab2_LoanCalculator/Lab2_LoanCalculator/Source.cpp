/*
 Ben Staffan &
 Due: 9-26-2013
 Program is intended to ask user for loan amount, monthly balance,
 and interest rate. Then uses the information to give total interest, number of months
 it will take to pay off the loan, annualized interest rate, and percentage of the annual interest to the loan.

 */

#include <iostream>

using namespace std;

void alternate() {
    double originalLoanAmount;
    double loanAmount;
    double userMonthlyPayment;
    double userYearlyInterestRate;
    double monthlyInterestRate;
    double monthlyMiniumPayment;
    int totalMonths = 0;
    double totalInterestPaid = 0;
    double tempInterest;
    double tempPrinciple;
    double annulizedInterest;
    double percentAnnualInterest;

    // Get the loan
    cout << "Loan Amount: $";
    cin >> loanAmount;
    originalLoanAmount = loanAmount;
    //

    // Get the yearly interest rate
    cout << "Yearly Interest Rate: ";
    cin >> userYearlyInterestRate;
    //

    monthlyInterestRate = userYearlyInterestRate / 12;
    monthlyMiniumPayment = loanAmount * monthlyInterestRate;

    // Get the monthly payment
    cout << "You need a minimum monthly payment of [" << monthlyMiniumPayment << "$]" << endl;
    do {
        cout << "Monthly Payent: $";
        cin >> userMonthlyPayment;
    } while (userMonthlyPayment < monthlyMiniumPayment);
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

    annulizedInterest = totalInterestPaid / (totalMonths / 12.0);
    percentAnnualInterest = (annulizedInterest / originalLoanAmount)*100;

    cout << endl << "Number of months to payoff loan: " << totalMonths << endl;
    cout << "Total interest paid: $" << totalInterestPaid << endl;
    cout << "Annulized Interest: $" << annulizedInterest << endl;
    cout << "Percent of the annualized interest from the loan: " << percentAnnualInterest << "%" << endl;

    // Restart code
    cout << "If you would like to coninute, enter the numeber 1: ";
    cin >> totalMonths;
    if (totalMonths == 1) {
        cout << endl << "The program is re-running." << endl;
        alternate();
    } else {
        cout << endl << "The program will now exit.";
    }
    //
}

int main() {
    alternate();
    /**
     double loanAmount;
     double monthlyPayment;
     double yearInterestRate;
     double interestRate;
     double monthlyInterest;
     double monthlyBalance;
     double currentBalance;
     double principle;
     double nomPayoff = 0;
     double totalInterest =0;
     double anInterest;
     double perInterest;
     bool rerun;

     //Input/Output*************************************************************
     cout << "Please enter your loan amount.";
     cin >> loanAmount;
     //Setting up balance also for use in while statement later
     monthlyBalance = loanAmount;

     cout << "Please enter what you would like your monthly payment to be. \n"
     << " Make sure it is over the minimum payment.";
     cin >> monthlyPayment;
     cout << "Please enter the percent interest (ie if 10% enter 10.)";
     cin >> yearInterestRate;

     if (yearInterestRate < 0)
     {
     cout << "Please re-enter the percent interest (ie if 10% enter 10.)";
     cin >> yearInterestRate;

     }

     cout << "Loan Amount: " << loanAmount << "\n";
     cout << "Interest Rate: " << yearInterestRate << "% \n";
     cout << "Monthly Balance     Monthly Payment     Interest     Principle \n";
     //*************************************************************************

     //Calculations*************************************************************
     interestRate = ((yearInterestRate/100)/12);

     while (monthlyBalance > 0)
     {
     nomPayoff++;
     currentBalance = monthlyBalance;
     //Finding interest rates
     monthlyInterest = (monthlyBalance*interestRate);
     totalInterest = (totalInterest + monthlyInterest);

     // if statement for final month where monthly payment might be higher than money owed
     if (monthlyPayment < monthlyBalance)
     {
     monthlyBalance = (monthlyBalance - monthlyPayment + monthlyInterest);

     principle = (monthlyPayment - monthlyInterest);
     }

     else
     {
     monthlyPayment = monthlyBalance + monthlyInterest;

     monthlyBalance = (monthlyBalance - monthlyPayment + monthlyInterest);

     principle = (monthlyPayment - monthlyInterest);
     }

     //Inner Loop Output****************************************************************

     cout << "\n"
     << nomPayoff << "     "
     << currentBalance << "     "
     << monthlyPayment << "     "
     << monthlyInterest << "     "
     << principle << "     ";
     //*********************************************************************************
     }
     cout << "\n Number of months to pay off loan: "
     << nomPayoff << ".";
     cout << "\n Total Interest: $"
     << totalInterest << ".";



     cout << "\n Would you like to run again?" ;
     cin >> rerun;

     return 0;
     /**/
}

