// salescontest.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

//this application uses a while statement to determine and print the largest number of 10 positive numbers input by the user.
int main()
{

	//this is where I initialize my variables
	int counter = 1;
	double number = 0; //set as double because of limits on ints
	double largest = 0; //same reason as above ^

	//this is the program itself
	std::cout << "you will enter 10 numbers and I will return the largest one! \n"; //tells the user what is going on

	while (counter < 11) //this loop is to make sure that 10 numbers are put
	{
		while (number <= 0) //this makes sure that only numbers above 0 are put, if the user puts a number less than 0 the while loop repeats
		{
			std::cout << "enter a number greater than 0 \n";
			std::cin >> number;
			std::cin.clear();

			if (number <= 0) { //this tells the user that negative numbers aren't allowed if he puts a number less than 0
				std::cout << "negative numbers and 0 are not allowed \n";
			}
		}

		if (largest <= number) //this puts the user inputted number in largest if it is larger than the preexisting number
		{
			largest = number;
		}
		number = 0; //this resets number to 0 to re-execute the while loop after adding a counter
		std::cout << "this was attempt number: " << counter << std::endl; //this tells the user what attempt he is at (max 10)
		counter++; //this adds an "attempt" so the program doesn't go on an infinite loop
	}
	std::cout << " \n \n \n \n \n the largest number you entered is:   " << largest << std::endl; //this displays the largest number after the program is done
	system("pause");

	return 0;
}