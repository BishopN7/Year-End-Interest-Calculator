#include "airgead_banking_app.h"
#include <iostream>
#include <cmath>   // Calculate several math functions
#include <iomanip> // Output formatting

int main() {
	double initialInvestment, annualInterestRate, futureValue, monthlyDeposit;
	double futureValueWithoutDeposits;
	int numYears;

	// Display a welcome message 
	std::cout << "******************************************************" << '\n';
	std::cout << "* Welcome to the Airgead Investment Bank Calculator! *" << '\n';
	std::cout << "******************************************************" << '\n';

	// Initial Investment do-while loop
	bool validInput = false;
	do {
		std::cout << "Please enter your initial investment amount (in dollars): " << '\n';
		std::cin >> initialInvestment;

		// Conditional if investment is less than 0
		if (initialInvestment < 0) {
			std::cout << "Error! Please enter a non-negative value (in dollars)" << '\n';
		}
		else {
			validInput = true;
		}
	} while (!validInput);

	// Annual interest rate do-while loop
	validInput = false;
	do {
		std::cout << "Enter the annual interest rate (decimal percentage): " << '\n';
		std::cin >> annualInterestRate;

		// Conditional for the annual interest rate
		if (annualInterestRate <= 0 || annualInterestRate > 1) {
			std::cout << "Error! Please enter a proper interest that is between 0 and 1 (e.g., 0.02 for 2%)" << '\n';
		}
		else {
			validInput = true;
		}
	} while (!validInput);

	// Number of years do-while loop
	validInput = false;
	do {
		std::cout << "Enter the number of years for the investment: " << '\n';
		std::cin >> numYears;

		// Conditional for number of years
		if (numYears < 0) {
			std::cout << "Error! Please enter a positive number in years " << '\n';
		}
		else {
			validInput = true;
		}
	} while (!validInput);

	// Monthly Deposit do-while loop
	validInput = false;
	do {
		std::cout << "Enter your monthly deposit (in dollars): " << '\n';
		std::cin >> monthlyDeposit;

		// Conditional for monthly deposit
		if (monthlyDeposit < 0) {
			std::cout << "Error! Please enter a positive value for your monthly deposit." << '\n';
		}
		else {
			validInput = true;
		}
	} while (!validInput);

	// Display without monthly deposits
	std::cout << std::fixed << std::setprecision(2);
	std::cout << '\n' << "----------------------------------------------------------";
	std::cout << '\n' << "Balance and Interest Without Additional Monthly Deposits";
	std::cout << '\n' << "----------------------------------------------------------";
	std::cout << '\n' << "                                                          " << '\n';
	std::cout << "   " << std::setw(5) << "Year" << std::setw(27) << "Year End Balance" << std::setw(27) << "Year End Earned Interest" << '\n';

	for (int currentYear = 1; currentYear <= numYears; ++currentYear) {
		// Calculate future value without deposits within the loop
		double futureValueWithoutDeposits = initialInvestment * pow(1 + annualInterestRate, currentYear);  // Calculate for each year
		double interestEarnedWithoutDeposits = futureValueWithoutDeposits - initialInvestment;

		// Display correct values
		std::cout << std::setw(5) << currentYear << std::setw(20) << "$" << futureValueWithoutDeposits << std::setw(20) << "$" << interestEarnedWithoutDeposits << '\n';
	}


	// Display with the monthly deposits
	std::cout << std::fixed << std::setprecision(2);
	std::cout << '\n' << "----------------------------------------------------------";
	std::cout << '\n' << "Balance and Interest With Additional Monthly Deposits";
	std::cout << '\n' << "----------------------------------------------------------";
	std::cout << '\n' << "                                                          " << '\n';
	std::cout << "   " << std::setw(5) << "Year" << std::setw(27) << "Year End Balance" << std::setw(27) << "Year End Earned Interest" << '\n';

	// Initialize futureValueWithDeposits outside the loop
	double futureValueWithDeposits = initialInvestment;

	for (int currentYear = 1; currentYear <= numYears; ++currentYear) {
		// Calculate year-end values with deposits
		for (int monthlyDeposit = 1; monthlyDeposit <= 12; ++monthlyDeposit) {
			futureValueWithDeposits += monthlyDeposit;
			futureValueWithDeposits *= (1 + annualInterestRate / 12);
		}

        // Calculate interest earned with deposits
		double interestEarnedWithDeposits = futureValueWithDeposits - initialInvestment;

		// Display year and calculated values
		std::cout << std::setw(5) << currentYear << std::setw(20) << "$" << futureValueWithDeposits << std::setw(20) << "$" << interestEarnedWithDeposits << '\n';
	}

	    
	// Prompt the user if they want to make another calculation
	char choice;
	std::cout << "Do you want to make another calculation? (y/n): " << '\n';
	std::cin >> choice;

	// Switch statement for (y/n)
	switch (choice) {
	case 'y':
	case 'Y':
		main();
		break;
	case 'n':
	case 'N':
		// Display a thank you and goodbye message if 'n' or 'N' is entered
		std::cout << "Thank you for using the Airgead Banking Calculator. Have a nice day!" << '\n';
		break;
	default:
		std::cout << "Invalid choice! Please enter either 'y' or 'n' to proceed." << '\n';
	}

	return 0;

}