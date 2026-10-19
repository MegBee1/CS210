/* Name: Megan Brooks
   Date: 9/24/26
   Purpose: Build application that shows investment growth over time based on user input */



#include <iostream>
#include <iomanip>
#include "Investment.h" // Allow code to reference header file variables

using namespace std;

// Initialize member variables using constructor
Investment::Investment() {
	initialAmount = 0.0;
	monthlyDeposit = 0.0;
	annualInterestRate = 0.0;
	numberOfYears = 0;
}

// Get user input
void Investment::getUserInput() {
	cout << "**********************************" << endl;
	cout << "********** Data Input ************" << endl;
	cout << "**********************************" << endl;

	// Ask user for initial investment amount
	cout << "Initial Investment Amount: $";
	cin >> initialAmount;

	// Ask user for monthy deposit amount
	cout << "Monthly Deposit: $";
	cin >> monthlyDeposit;

	// Ask user for annual interest amount
	cout << "Annual Interest (percent): ";
	cin >> annualInterestRate;

	// Ask user for number of years
	cout << "Number of Years: ";
	cin >> numberOfYears;

	cout << endl;

	// Ask user to click enter to calculate final amounts
	cout << "Press Enter to continue...";
	cin.ignore();
	cin.get();
	cout << endl << endl;
}


// Report without monthly deposits
void Investment::displayReportWithoutDeposits() {
	double currentBalance = initialAmount;
	double yearlyInterest;
	double monthlyInterestRate = annualInterestRate / 100.0 / 12.0;

	cout << "   Balance and Interest Without Additional Monthly Deposits" << endl;
	cout << "============================================================" << endl;
	cout << setw(10) << "Year" << setw(20) << "Year End Balance" << setw(30) << "Year End Earned Interest" << endl;
	cout << "------------------------------------------------------------" << endl;


	// Loop through each year of interest
	for (int year = 1; year <= numberOfYears; ++year) {
		yearlyInterest = 0.0;

		// Loop through each month in current year
		for (int month = 1; month <= 12; ++month) {
			double interestForMonth = currentBalance * monthlyInterestRate; // Calculate interest earned for this month
			currentBalance += interestForMonth; // Add monthly interest to balance
			yearlyInterest += interestForMonth; // Track total interest earned for year
		}

		// Display year, ending balance and earned interest
		cout << setw(10) << year << setw(20) << fixed << setprecision(2) << currentBalance << setw(20) << fixed << setprecision(2) << yearlyInterest << endl;
	}

	cout << endl << endl;

}

// Report with monthly deposits
void Investment::displayReportWithDeposits() {
	double currentBalance = initialAmount;
	double yearlyInterest;
	double monthlyInterestRate = annualInterestRate / 100.0 / 12.0;

	cout << "   Balance and Interest With Additional Monthly Deposits" << endl;
	cout << "=========================================================" << endl;
	cout << setw(10) << "Year" << setw(20) << "Year End Balance" << setw(30) << "Year End Earned Interest" << endl;
	cout << "---------------------------------------------------------" << endl;

	// Loop through each year of investment 
	for (int year = 1; year <= numberOfYears; ++year) {
		yearlyInterest = 0.0; // Reset yearly interest and beginning of every year

		// Loop through each month in current year
		for (int month = 1; month <= 12; ++month) {

			
			currentBalance += monthlyDeposit; // Add monthly deposit

			double interestForMonth = currentBalance * monthlyInterestRate; // Calculate interest earned for month
			currentBalance += interestForMonth; // Add monthly interest to balance
			yearlyInterest += interestForMonth; // Collect total interest earned for the year
		}

		// Display year number, ending balance, and earned interest
		cout << setw(10) << year << setw(20) << fixed << setprecision(2) << currentBalance << setw(20) << fixed << setprecision(2) << yearlyInterest << endl;
	}

	cout << endl << endl;

}

