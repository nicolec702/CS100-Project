#ifndef __HELPER_FUNCTIONS__
#define __HELPER_FUNCTIONS__
#include<iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include <algorithm>
//----------------
int verifyIntInput(std::string input) // returns -1 if inproper input
{
    // erasing whitespace incase user enters " 1" instead of "1" by mistake
	input.erase(remove_if(input.begin(), input.end(), ::isspace), input.end());
	bool isNumber = true;
	int x;
	for (int i = 0; i < input.length(); i++) // checking each character in string
		if (!isdigit(input[i])) isNumber = false; // checking if all characters input are digits

	if (isNumber == true) // if string is an integer
	{
		std::stringstream num(input);
		num >> x; // storing string to an int
	}
	else x = -1; // if string is not an int return value of -2
	return x;
}

bool verifyStringInput(std::string input)
{
    bool isValid = true;
	if (isalpha(input[0])) // checking is name starts with a letter
	{
		for (int unsigned i = 0; i < input.length(); i++)
			if (!(isalnum(input[i]) || isspace(input[i]))) // checking is name is only alphanumeric and white space
				isValid = false;
	}
	else isValid = false;
	return isValid;
}

#endif