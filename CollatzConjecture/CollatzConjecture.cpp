// Collatz Conjecture Project
// Written by Alex Jordan
// Version 0.1 alpha

#include <iostream>
#include <cstdlib>
using namespace std;

int calculate(long int number) {
	bool IsEven;
	if (number % 2== 0) {
		IsEven = true;
	} else {
		IsEven = false;
	}
	if (IsEven == true) {
		number = number / 2;
	}
	if (IsEven == false) {
		number = number * 3;
		number = number++;
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
	bool showwork;
	bool showworkvalid = false;
	bool gottoone = false;
	
	cout << "Welcome to the Collatz Conjecture calculator.\nPlease pick a number: ";
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
		
		cout << "\nWorking...\n";
		while (iterationstogo != iterations && iterationstogo > iterations && gottoone == false) {
			number = calculate(number);
			iterations++;
			totaliterations++;
			if (number == 1) {
				cout << "Yep, we got to 1. It took " << totaliterations << " iterations. Your original number was " << originalnumber << ".";
				gottoone = true;
			}
		}
	} while (number != 1);
	
	cout << "\nBye!";
	return 0;
}