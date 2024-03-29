/** FibonP2.cpp
 *
 *  Program iteratively calculates the Fibonacci number Fn, where n is an integer >= 0. Provides the requested
 *  number as output. 
 *
 *  Author: Oloff Biermann
 *  IDE: Microsoft Visual Studio 2017
 *  Compiler: Microsoft Visual C++ 14.16.27012.6
 *  OS: Microsoft Windows 10 version 1903
 *  Hardware: Alienware 15 R4 Intel i7 8750h (4.1 GHz) CPU with 16GB memory
 *
 *
 **/

#include "pch.h"
#include <iostream>
#include <string>
#include <regex>
#include <chrono>
#include <stdexcept>
#include <inttypes.h>

using namespace std;


/*
 * Returns integer input by user where value is 0 <= n <= 999.
 */
int getFibInput()
{
	cout << "Enter a positive integer n or negative integer to exit: " << endl;
	string input;
	regex pattern("-?\\d{1,3}");                                               //Matches positive or negative integer input, -999 <= n <= 999

	cin >> input;                                                              //Attempt to read numeric input as a string


	/*While input is not a valid integer, attempt to get valid input */
	while (!(regex_match(input, pattern)))
	{
		cout << "Invalid input. Please enter an integer 0 <= n <= 999 or a negative integer to exit:" << endl;
		cin >> input;
	}

	return stoi(input);                                                      //Return input string converted to integer.
}


uint64_t fibon2(int n)
{

	if (n < 2)
	{
		return n;
	}

	uint64_t n1 = 0;
	uint64_t n2 = 1;


	for (int i = 0; i < n - 1; i++)
	{
		/*If result of n1 + n2 > UINT64_MAX, the new value for n2 will not be correct. 
		This is because  the unsigned integer does not allow overflow. Instead, arithmetic 
		modulo 2^64 would be done to ensure result fits in 64 bits.*/
		if (n2 > UINT64_MAX - n1)
		{
			throw runtime_error("Error. Result too large to fit 64 bit unsigned integer.");
		}
		uint64_t temp = n1;
		n1 = n2;

		


		n2 = temp + n2;
	}

	return n2;

}




int main()
{
	int userInput = getFibInput();

	while (userInput >= 0)
	{
		try
		{
			uint64_t fibN = fibon2(userInput);                                          //Calculate the Fibonacci number using fibon1().
			cout << "F" << userInput << " = " << fibN << endl;
		}
		catch (runtime_error& ex)
		{
			cerr << ex.what() << endl;
		}

		userInput = getFibInput();                                                        //Give option to another number or -1 to exit. 
	}

	cout << "closing..." << endl;


}