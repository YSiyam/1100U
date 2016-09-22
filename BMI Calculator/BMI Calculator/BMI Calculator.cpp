// BMI Calculator.cpp : Defines the entry point for the console application.

#include "stdafx.h"
#include <iostream>


/* This Program is meant to be a BMI calculator application 
that reads the user’s weight in pound and height in feet and
inches, then calculates and displays the users’ body mass index. */
int main()
{

	//this is where I begin setup before going into the program

	double weight, bmi; //this is weight in pounds and their BMI
	int heighti, heightf; //this is the total height used in the bmi calculation
	

	//the two commands bellow enable the use of decimals, without them cout won't display decimals

	std::cout.precision(2); //the number in the bracket is how many decimals there will be in the number, this case 2
	std::cout.setf(std::ios::fixed); 
	
	//this is where the calculations will happen for the variables initiated above

	std::cout << "What is your weight in pounds? ";
	std::cin >> weight;

	std::cout << "What is your height in feet and inches? ";
	std::cin >> heightf;
	std::cin >> heighti;

	heighti = (heightf * 12) + heighti;
	bmi = (weight * 703) / (heighti * heighti);
	
	
	//this section tells you what your BMI is and what you classify as

    std::cout << "your BMI is: " << bmi << std::endl; //this tells you your bmi

	/* these if statements only activate when
	a certain condition has been met which is declared in the brackets*/

	if ((bmi >= 18.5) && (bmi <= 24.9))  //this is the normal BMI statement
	{ 
		std::cout << "you have a normal BMI \n";
	}

	if (bmi <= 18.5) //this is the underweight BMI statement
	{
		std::cout << "You are underweight \n";
	}

	if ((bmi >= 25) && (bmi <= 29.9)) //this is the overweight BMI statement
	{
		std::cout << "you are overweight! \n";
	}

	if (bmi >=30) //this is the obese BMI statement
	{
		std::cout << "you are obese! \n";
	}

	system("pause");

    return 0;
}