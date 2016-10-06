// salescontest.cpp : Defines the entry point for the console application.
//name: Yazan Siyam
//ID: 100622746

#include "stdafx.h"
#include <iostream>
using namespace std;

//this application uses a while statement to determine and print the largest number of 10 positive numbers input by the user.
int main()
{

	//this is where I initialize my variables
	int counter = 1;
	double number = 0; //set as double because of limits on ints
	double largest = 0; //same reason as above ^

	//this is the program itself

	cout << "you will enter 10 numbers and I will return the largest one! \n"; //tells the user what is going on

	while (counter < 11) //this loop is to make sure that 10 numbers are put, nothing more and nothing less
	{
		while (number <= 0) //this makes sure that only numbers above 0 are put, if the user puts a number <= 0 the while loop repeats till it is >
		{
			cout << "enter a number greater than 0 \n";
			cin >> number;
			cin.clear(); //this helps prevent infinite loops

			if (number <= 0) { //this tells the user that negative numbers aren't allowed if he puts a number less than 0 just as an informative bit
				cout << "negative numbers and 0 are not allowed \n";
			}
		}

		if (largest <= number) //this puts the user inputted number in largest if it is larger than the pre-existing number
		{
			largest = number;
		}
		number = 0; //this resets number to 0 to re-execute the while loop after adding a counter
		cout << "this was attempt number: " << counter << endl; //this tells the user what attempt he is at (max 10)
		counter++; //this adds an "attempt" so the program doesn't go on an infinite loop
	}
	cout << " \n \n \n \n \n the largest number you entered is:   " << largest << endl; //this displays the largest number after the program is complete
	system("pause");

	return 0;
}