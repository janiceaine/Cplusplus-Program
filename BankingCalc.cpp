#include <iostream>
#include <iomanip>
#include "BankingCalc.h"

using namespace std; 

BankingCalc::BankingCalc() {
    initialInvest = 0;
    monthlyDep = 0;
    annInterest = 0;
    years = 0;
    months = 0;
    totalAmt = 0;
    interestAmt = 0;
    yearTotInterest = 0;

}

BankingCalc::BankingCalc(float t_initialInvest, float t_monthlyDep, float t_annInterest, float t_years) {
    initialInvest = t_initialInvest;
    monthlyDep = t_monthlyDep;
    annInterest = t_annInterest;
    years = t_years;
    months = 0;
    totalAmt = 0;
    interestAmt = 0;
    yearTotInterest = 0;
}

float BankingCalc::getInitInvest() {
    return initialInvest;
}

float BankingCalc::getMonthlyDep() {
    return monthlyDep;
}

float BankingCalc::getAnnualInterest() {
    return annInterest;
}

float BankingCalc::getYears() {
    return years;
}

float BankingCalc::getMonths() {
    return months;
}

float BankingCalc::getTotalAmt() {
    return totalAmt;
}

float BankingCalc::getInterestAmt() {
    return interestAmt;
}

float BankingCalc::getYearTotInterest() {
    return yearTotInterest;
}

void BankingCalc::dataInput() {
    cout << "********************************" << endl;
    cout << "********** Data Input **********" << endl;
    cout << "Initial Investment Amount: $";

    cin >> initialInvest;

    if (initialInvest < 0) {
        cout << "Initial investment amount cannot be less than $0" << endl;
        cout << "Initial Investment Amount: $";
        cin >> initialInvest;

    }

    cout << "Monthly Deposit: $";

    cin >> monthlyDep;

    if (monthlyDep < 0) {
        cout << "Monthly deposit amount cannot be less than $0" << endl;
        cout << "Monthly Deposit: $";
        cin >> monthlyDep;

    }

    cout << "Annual Interest: %";
    cin >> annInterest;

    cout << "Number of years: ";
    cin >> years;
    months = years * 12;

    system("PAUSE");
    system("CLS");

    totalAmt = initialInvest;
}

void BankingCalc::printReport() {
    // Implementation of printReport() function
    cout << " Balance and Interest Without Additional Monthly Deposits" << endl;
    cout << "================================================================" << endl;
    cout << "Year          Year End Balance          Year End Earned Interest" << endl;
    cout << "----------------------------------------------------------------" << endl;

    for (int i = 0; i < years; i++) {
        //Calculate yearly interest
        interestAmt = totalAmt * (annInterest / 100);
        //Calculate total at year's end
        totalAmt += interestAmt;
        //Prints results at a 2 decimal point precision
        cout << " " << (i + 1) << "\t\t$" << fixed << setprecision(2) << totalAmt << "\t\t\t$" << interestAmt << "\n";
    }

    totalAmt = initialInvest;
    //Display year data with monthly deposits from account owner
    cout << endl;
    cout << " Balance and Interest With Additional Monthly Deposits" << endl;
    cout << "=================================================================" << endl;
    cout << "Year          Year End Balance          Year End Earned Interest" << endl;
    cout << "-----------------------------------------------------------------" << endl;

    for (int i = 0; i < years; i++) {
        //Sets interest for the year at zero (for a new year)
        yearTotInterest = 0;
        for (int j = 0; j < 12; j++) {
            //Calculate monthly interest
            interestAmt = (totalAmt + monthlyDep) * ((annInterest) / 100 / 12);
            //Calculate interest at month's end
            yearTotInterest = yearTotInterest + interestAmt;
            //Calculate total for the month
            totalAmt += monthlyDep + interestAmt;
        }

        //Prints results at a 2 decimal point precision.
        cout << (i + 1) << "\t\t$" << fixed << setprecision(2) << totalAmt << "\t\t\t$" << yearTotInterest << "\n";
    }
}
