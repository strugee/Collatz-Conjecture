// Collatz Conjecture Project
// Written by Alex Jordan
// Version 0.1 alpha

#include <iostream>
#include <cstdlib>
using namespace std;

// To enable or disable features just modify these variables
bool SingleNumberModeEnabled = true;
bool RangeModeEnabled = true;
bool ShowWorkAllowed = true;

// In case we call ShowWorkEnabled instead of ShowWorkAllowed
bool ShowWorkEnabled = ShowWorkAllowed;

void printmodehelp() {
	// If only single mode is enabled
	if (SingleNumberModeEnabled == true && RangeModeEnabled == false) {
		cout << "\nYou can only use single-number mode.\nSingle-number mode will iterate for a number of your choosing, stop and ask for a new number of iterations, then repeat until it gets to one.";
		cout << "\nSingle-number mode is called by typing \"single\" without the quotes.\n\n";
	}
	// If only range mode is enabled
	if (RangeModeEnabled == true && SingleNumberModeEnabled == false) {
		cout << "\nYou can only use range mode.\nRange mode will test a range of numbers of your choosing. However, it will not ask for a number of iterations and will run until it completes.";
		cout << "\nRange mode is called by typing \"range\" without the quotes.\n\n";
	}
	// If both range mode and single mode are enabled
	if (SingleNumberModeEnabled == true && RangeModeEnabled == true) {
		// print general info
		cout << "You can use single-number mode or range mode.\n";
		// print single-number info
		cout << "\nSingle-number mode will iterate for a number of your choosing, stop and ask for a new number of iterations, then repeat until it gets to one.";
		cout << "\nSingle-number mode is called by typing \"single\" without the quotes.\n\n";
		// print range mode info
		cout << "\nRange mode will test a range of numbers of your choosing. However, it will not ask for a number of iterations and will run until it completes.";
		cout << "\nRange mode is called by typing \"range\" without the quotes.\n\n";
	}
}

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
			cout << number << "\n\n";
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
	long int bottomnumber;
	long int topnumber;
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
		// Define variables (it has to be done inside the do instead of when they're declared
		// because if the user uses the program a second time by saying "y" at the end, the variables need to be reset
		totaliterations = 0;
		showworkvalid = false;
		modeishelp = true;
		modeisvalid = false;
		
		cout << "\n";
		do {
			do {
				cout << "Select mode (type help for available options): ";
				cin >> mode;
				if (mode == "help") {
					printmodehelp();
					modeisvalid = true;
				} else if (mode == "single" && SingleNumberModeEnabled == true) {
					modeishelp = false;
					modeisvalid = true;
				} else if (mode == "range" && RangeModeEnabled == true) {
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
			
			if (ShowWorkAllowed == true) {
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
			}
				
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
		
		if (mode == "range") {
			cout << "Please be aware that range mode will not ask for a number of iterations. This means that the only way to stop it from running (in case a number actually doesn't work with the Collatz Conjecture) is to kill it.";
			cout << "\nIs this OK? To continue, type yes; to abort, type anything else: ";
			string rangeconfirmation;
			cin >> rangeconfirmation;
			if (rangeconfirmation == "y" || rangeconfirmation == "yes") {
				cout << "\nOK, thanks for confirming.\n";
			} else {
				mode = "void";
				cout << "\nRange mode aborted.\n";
			}
		}
		
		if (mode == "range") {
			cout << "\nPick the bottom number: ";
			cin >> bottomnumber;
			cout << "\nPick the top number: ";
			cin >> topnumber;
			if (bottomnumber > topnumber) {
				cout << "The bottom number is larger than the top number. Switching numbers.";
				// bn2tn is bottom number to top number
				long int bn2tn = bottomnumber;
				// tn2bn is top number to bottom number
				long int tn2bn = topnumber;
				tn2bn = bottomnumber;
				bn2tn = topnumber;
				cout << "The new bottom number is " << bottomnumber << ". The new top number is " << topnumber << ".";
			}
			
			if (ShowWorkEnabled == true) {
				// Ask if they want to show work
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
						cout << "\nInvalid input; try again. ";
					}
				} while (showworkvalid == false);
			}
			
			// Iterate on the number range
			for (long int bottomnumbernew = bottomnumber; bottomnumbernew != topnumber + 1; bottomnumbernew++) {
				cout << "\nWorking...\n";
				cout << "Testing " << bottomnumbernew << ".\n";
				number = bottomnumbernew;
				iterations = 0;
				if (number != 1) {
					number = calculate(number, showwork);
					iterations++;
				} else {
					cout << "We got to 1 in " << iterations << " iterations while testing the number " << bottomnumbernew << ".\n";
					cout << "Testing next number.\n";
				}
			}
			cout << "Done. All the numbers seem to follow the Collatz Conjecture.\n";
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
	
	cout << "Bye!\n";
	cout << "Collatz Conjecture calculator terminated.";
	return 0;
}