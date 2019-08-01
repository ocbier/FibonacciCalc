// FibonP1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <string>
#include <regex>

using namespace std;


/**
*  Iteratively calculated the Fibonacci number Fn. 
* 
*  The int param n indicates the index of the desired Fibonacci number.
*
**/
int fibon2(int n)
{
	if (n < 2)
	{
		return n;
	}

	int n1 = 0;
	int n2 = 1;

	for (int i = 0; i < n - 1; i++)
	{
		int temp = n1;
		n1 = n2;
		n2 = temp + n2;
	}

	return n2;
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
	cout << "This program will calculate the Fibonacci number Fn iteratively." << endl;

	int userInput = getFibInput();

	while (userInput >= 0)
	{
		int fibN = fibon2(userInput);                                            //Calculate the Fibonacci number using fibon2().
		cout << "F" << userInput << "= " << fibN << endl;
		userInput = getFibInput();                                                //Give option to another number or -1 to exit. 
	}

	cout << "closing" << endl;


}




