//    Name: BankingCalc.cpp
// Author : Janice Ainembabazi
//  Class : CS210-SNHU
//    Date: 02/11/2024

#include <iostream>
#include <iomanip>
#include "BankingCalc.h"

using namespace std;

int main() {
    BankingCalc calc;  // Creating an instance of the BankingCalc class

    calc.dataInput();  // getting the dataInput() method to get user input
    calc.printReport();  // getting the printReport() method to print the report

    return 0;
}
