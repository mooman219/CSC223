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

/**
Loan Amount: $20000
Yearly Interest Rate: .1
You need a minimum monthly payment of [166.667$]
Monthly Payent: $1000

Loan Amount: $20000
Interest Rate: 0.1%
Month    Monthly-Balance Monthly-Payment Interest   Principle
1        $20000          $1000           $166.667   $833.333
2        $19166.7        $1000           $159.722   $840.278
3        $18326.4        $1000           $152.72    $847.28
4        $17479.1        $1000           $145.659   $854.341
5        $16624.8        $1000           $138.54    $861.46
6        $15763.3        $1000           $131.361   $868.639
7        $14894.7        $1000           $124.122   $875.878
8        $14018.8        $1000           $116.823   $883.177
9        $13135.6        $1000           $109.463   $890.537
10       $12245.1        $1000           $102.042   $897.958
11       $11347.1        $1000           $94.5593   $905.441
12       $10441.7        $1000           $87.014    $912.986
13       $9528.69        $1000           $79.4058   $920.594
14       $8608.1         $1000           $71.7342   $928.266
15       $7679.83        $1000           $63.9986   $936.001
16       $6743.83        $1000           $56.1986   $943.801
17       $5800.03        $1000           $48.3336   $951.666
18       $4848.36        $1000           $40.403    $959.597
19       $3888.77        $1000           $32.4064   $967.594
20       $2921.17        $1000           $24.3431   $975.657
21       $1945.52        $1000           $16.2126   $983.787
22       $961.729        $969.744        $8.01441   $961.729

Number of months to payoff loan: 22
Total interest paid: $1969.74
Annulized Interest: $1074.41
Percent of the annualized interest from the loan: 5.37203%
If you would like to coninute, enter the numeber 1:
 */
