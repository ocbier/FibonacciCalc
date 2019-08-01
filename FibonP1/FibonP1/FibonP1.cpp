// FibonP1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <string>
#include <regex>

using namespace std;


/**
*  Recursively calculates the Fibonacci number Fn, where n = i for the first call of fibon1().
*  Calculation is done using n1 as the first term and n2 as the second term. Therefore, n1 is Fj-2 and
*  n2 is Fj-1 for term j in the Fibonacci sequence.
*
**/
int fibon1(int n1, int n2, int i)
{
	if (i < 2)
	{
		return i;
	}

	/*Base case for recursion when there are 2 items in the sequence before Fi.*/
	if (i == 2)
	{
		return n1 + n2;
	}

	return fibon1(n2, n1 + n2, i - 1);                                         //Recursively call fibon1 to calcualte next number in sequence.
}


/*Returns positive */
int getFibInput()
{
	cout << "Enter a positive integer n or negative integer to exit: " << endl;
	string input;
	regex pattern("-?\\d+");                                                    //Matches positive or negative integer input.

	cin >> input;                                                              //Attempt to read numeric input as a string


	/*While input is not a valid integer, attempt to get valid input */
	while (!(regex_match(input, pattern)))
	{
		cout << "Invalid input. Please enter an integer >= 0 or a negative integer to exit:" << endl;
		cin >> input;
	}

	return stoi(input);                                                       //Return input string converted to integer.


}



int main()
{
	cout << "This program will calculate the Fibonacci number n." << endl;

	int userInput = getFibInput();

	while (userInput >= 0)
	{
		int fibN = fibon1(0, 1, userInput);                                    //Calculate the Fibonacci number using fibon1().
		cout << "F" << userInput << " = " << fibN << endl;
		userInput = getFibInput();                                                //Give option to another number or -1 to exit. 
	}

	cout << "closing" << endl;

		     
}




