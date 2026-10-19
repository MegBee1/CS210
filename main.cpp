#include <iostream>
#include "Investment.h" // Allow code to reference header file variables 

using namespace std;

int main() {

	// Create investment object
	Investment myInvestment;

	// Get input from user
	myInvestment.getUserInput();

	// Display reports
	myInvestment.displayReportWithoutDeposits();
	myInvestment.displayReportWithDeposits();

	// Exit program
	return 0; 
}