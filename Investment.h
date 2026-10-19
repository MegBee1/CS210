#ifndef INVESTMENT_H
#define INVESTMENT_H 

class Investment {
private:
	double initialAmount;
	double monthlyDeposit;
	double annualInterestRate;
	int numberOfYears;

public:

	// Constructor
	Investment();

	// Get input from user
	void getUserInput();

	// Display report without monthly deposits
	void displayReportWithoutDeposits();

	// Display report with monthly deposits
	void displayReportWithDeposits();
};

#endif 
