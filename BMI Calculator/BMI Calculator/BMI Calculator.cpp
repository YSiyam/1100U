// BMI Calculator.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include <iostream>
/* This Program is meant to be a BMI calculator application
that reads the user’s weight in pound and height in feet and
inches, then calculates and displays the users’ body mass index. */
int main()
{

	//this is where i begin setup before going into the program
	double weight; //this is weight in pounds
	int heightf; //this is height in feet
	int heighti;  //this is height in inches
	int height; //this is the total height used in the bmi calculation
	double bmi;  //this is the persons BMI

				 //the two commands bellow enable the use of decimals, without them cout won't display decimals
	std::cout.precision(2);
	std::cout.setf(std::ios::fixed);

	//this is where the calculations will happen for the variables initiated above
	std::cout << "What is your weight in pounds? ";
	std::cin >> weight;

	std::cout << "What is your height in feet? ";
	std::cin >> heightf;

	std::cout << "What is your height in inches? ";
	std::cin >> heighti;

	height = (heightf * 12) + heighti;
	bmi = (weight * 703) / (height * height);

	//this section tells you what your BMI is and what you classify as

	std::cout << "your BMI is: " << bmi << std::endl; //this tells you your bmi

													  /* these if statements only activate when
													  a certain condition has been met which is declared in the brackets*/

	if (bmi >= 18.5 && bmi <= 24.9)  //this is the normal BMI statement
	{
		std::cout << "you have a normal BMI \n";
	}

	if (bmi <= 18.5) //this is the underweight BMI statement
	{
		std::cout << "You are underweight \n";
	}

	if (bmi >= 25 && bmi <= 29.9) //this is the overweight BMI statement
	{
		std::cout << "you are overweight! \n";
	}

	if (bmi >= 30) //this is the obese BMI statement
	{
		std::cout << "you are obese! \n";
	}
	system("pause");

	return 0;
}