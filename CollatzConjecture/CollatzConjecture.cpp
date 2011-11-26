// Collatz Conjecture Project
// Written by Alex Jordan
// Version 0.1 alpha

#include <iostream>
#include <cstdlib>
using namespace std;

int calculate(long int number, bool showwork) {
	bool IsEven;
	if (number % 2== 0) {
		IsEven = true;
		if (showwork == true) {
			cout << "\nThe number is even.\n";
		}
	} else {
		IsEven = false;
		if (showwork == true) {
			cout << "The number is odd.\n";
		}
	}
	if (IsEven == true) {
		if (showwork == true) {
			cout << number << " / 2 = ";
		}
		number = number / 2;
		if (showwork == true) {
			cout << number << "\n";
		}
	}
	if (IsEven == false) {
		if (showwork == true) {
			cout << number << " * 3 = ";
		}
		number = number * 3;
		if (showwork == true) {
			cout << number << "\n";
			cout << number << " + 1 = ";
		}
		number = number++;
		if (showwork == true) {
			cout << number << "\n";
		}
	}
	return number;
}

int main() {
	long int number;
	long int originalnumber;
	long int iterations;
	long int totaliterations;
	long int iterationstogo;
	string showworkstring;
	string mode;
	bool showwork;
	bool showworkvalid = false;
	bool useagain;
	bool modeishelp;
	bool modeisvalid;
	
	// Welcome!
	cout << "Welcome to the Collatz Conjecture calculator.";
	
	do {
		totaliterations = 0;
		showworkvalid = false;
		modeishelp = true;
		modeisvalid = false;
		
		cout << "\n";
		do {
			do {
				cout << "Select mode (help for available options): ";
				cin >> mode;
				if (mode == "help") {
					cout << "You can only use single-number mode at this point.\nSingle-number mode will iterate for a number of your choosing, stop and ask a new number of iterations, then repeat until it gets to one.";
					cout << "\nSingle-number mode is called by typing \"single\".\n";
					modeisvalid = true;
				} else if (mode == "single") {
					modeishelp = false;
					modeisvalid = true;
				}
			} while (modeishelp == true);
			if (modeisvalid = false) {
				cout << "\nInput is invalid; try again. ";
			}
		} while (modeisvalid = false);
		
		if (mode == "single") {
			cout << "\nPlease pick a number: ";
			cin >> number;
			originalnumber = number;
			cout << "\nThanks. ";
			
			do {
				cout << "Show work? y/n: ";
				cin >> showworkstring;
				if (showworkstring == "y") {
					showwork = true;
					showworkvalid = true;
				} else if (showworkstring == "n") {
					showwork = false;
					showworkvalid = true;
				} else {
					cout << "Invalid input; try again. ";
				}
			} while (showworkvalid == false);
			
			do {
				cout << "\nEnter number of iterations to go before stopping and asking again: ";
				cin >> iterationstogo;
				iterations = 0;
				
				cout << "\nWorking...\n";
				while (iterationstogo != iterations && iterationstogo > iterations && number != 1) {
					number = calculate(number, showwork);
					iterations++;
					totaliterations++;
					if (number == 1) {
						cout << "Yep, we got to 1. It took " << totaliterations << " iterations. Your original number was " << originalnumber << ".";
					}
				}
			} while (number != 1);
		}
			
		// Ask if user wants to use again
		cout << "\nDo you want to use this again? y/n: ";
		string useagainstring;
		cin >> useagainstring;
		bool useagainvalid;
		do {
			useagainvalid = false;
			if (useagainstring == "y") {
				useagain = true;
				useagainvalid = true;
			} else if (useagainstring == "n") {
				useagain = false;
				useagainvalid = true;
			} else {
				cout << "\nInvalid input; try again.";
			}
		} while (useagainvalid = false);
	} while (useagain == true);
	
	cout << "Bye!";
	return 0;
}