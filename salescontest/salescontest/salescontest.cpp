// salescontest.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

//this application uses a while statement to determine and print the largest number of 10 positive numbers input by the user.
int main()
{
	int counter = 0;
	int number = 0;
	int largest = 0;

	while (counter < 10)
	{
		while (number <= 0) 
		{
			std::cout << "enter any number greater than 0 \n";
			std::cin >> number;
		}

		if (largest <= number) 
		{
			largest = number;
		}
		number = 0;
		counter++;
	}
	std::cout << "the largest number you entered is: " << largest << std::endl;
	system("pause");

    return 0;
}



