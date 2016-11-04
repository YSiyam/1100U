// learntomath.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
using namespace std;


void startup() //informs the user of what the program does and what the user should do
{
	cout << "                            welcome to the CAI                                       " << endl;
	cout << "this program is designed to assist you with learning multiplication" << endl;
	cout << "I will now ask you as many multiplication questions as you would like. " << endl;
	cout << "you will be asked after every correct question if you would like to exit." << endl;
	cout << " answer with Y or N when asked if you would like to, GOOD LUCK!" << endl << endl << endl;

	system("pause");
	
}

int calc(int x, int y) //this takes x and y from the main() function and uses them in the calculations in this function
{
	int ans, userinput = 9999; 
	ans = x * y; //this presets the answer from the random numbers before the user attempts the question
	while (userinput != ans) //while loop to keep asking the user the question till the user gets it right
	{
		cout << "what is: " << x << " * " << y << endl;
		cin >> userinput; //stores the users answer in user input

		if (userinput == ans) { cout << "Very Good!" << endl; } //this informs the user that he got the answer right if he put it in correctly
		
		else {	cout << "No. Please try again." << endl;	} //this informs the user that he got the answer wrong if he put it in wrong
	}

	return ans;
}

void final(int total) { //this tells the user how many questions he did in total
	cout << "you took a total of: " << total << " questions, great job!" << endl;
}




int main()
{
	int x, y, total = 0;
	char response = 'y'; //this is to ask the user a yes or no question
	time_t t; //this sets time_t to t which is used to initialize the random seed
	startup(); //this calls upon the startup function which tells the user what is going on
	

	srand((unsigned)time(&t)); //this initializes the random seed generator so it doesn't repeat the same random number generated at the beginning
	while (response != 'n') //this makes it so the user can answer as many questions as he would like and turn off if he answers n
	{
		x = rand() % 10 + 1; //this generates a random number from 0 - 10
		y = rand() % 10 + 1; 

		calc(x, y); //this takes the random numbers above and puts them in the calc function

		cout << "would you like to do another question? (y/n)" << endl; //this asks you if you would like to do another question and stores it in a char
		cin >> response;

		total++; //this counts how many questions the user completed
	}

	final(total); //this puts the total number of questions in the final function


	system("pause");
    return 0;
}





