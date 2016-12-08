// RockPaperScissors.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdlib.h>
#include <time.h>
#include <iostream>
using namespace std;

int ai() { //this gets the ai's choice

	int aichoice;
	time_t t;
	srand((unsigned)time(&t)); //this is the random seed so you can use rand() multiple times

	aichoice = rand() % 3 + 1; //this generates a random number from 1-3 and stores it in aichoice

	return aichoice; //this returns aichoice back to main()
}


int user() { //this gets the users choice

	int userchoice = 4; //preset to 4 so the while loop below works
	while (userchoice < 1 || userchoice > 3) { // this while loop makes sure the user puts a number from 1 - 3
		cout << "type 1 for rock, 2 for paper or 3 for scissors?" << endl << endl; //asks the user for rock, paper, or scissors
		cin >> userchoice; //this stores the userchoice in cin

		if (userchoice < 1 || userchoice > 3) { //this if statemnt simply informs the user that he didn't meet the requirements of a number between 1-3
			cout << "that is not a valid option, try again" << endl << endl;
		}
	}

	return userchoice; //returns the users choice back to main()

}



void count(int total, int aicount, int usercount) { //simple functiion that tells you the total number of rounds played and how many times you and the computer won
	cout << "the total number of rounds you played is: " << total << endl << endl; //tells you total rounds played
	cout << "you won a total of " << usercount << " rounds" << endl << endl; //tells you how many rounds you won
	cout << "the computer won a total of " << aicount << " rounds" << endl << endl; //tells you how many rounds you lost
	if (usercount > aicount) { //tells you if you are the winner if you did win...
		cout << "you are the winner!" << endl;
}
	else { //tells you that the computer is the winner if you lost...
		cout << "the computer is the winner!" << endl;
	}
}


int main() //where the magic happens :)
{
	int userchoice, aichoice, total(0), retry(1), aicount(0), usercount(0); //this is where i declared the variables
	cout << "~~~ Welcome to the world of rock paper scissors!" << endl; // fancy intro.exe
	cout << "you will be playing a computer, the rules are simple!" << endl;
	cout << "simply choose 1 for rock, 2 for paper, 3 for scissors" << endl;
	cout << "and you will see what the computer chose and who won." << endl;
	cout << "you can play as many rounds as you would like, but becareful" << endl;
	cout << "this game is highly addictive!!!!" << endl;
	cout << "Take a 30 minute break after every 10 minutes of gameplay," << endl;
	cout << "Good Luck! ~~~~" << endl;
	system("pause"); //abuse of system("pause")

	while (retry != 0) { //while loop for however many rounds the user would like to play
		aichoice = ai(); //gets the ai's choice from the ai function
		userchoice = user(); //gets the users choice from the user function
		
		/*if statements that tell you what the computer chose*/
		if (aichoice == 1) { cout << "the computer chose rock" << endl << endl; }
		else if (aichoice == 2) { cout << "the computer chose paper" << endl << endl; }
		else if (aichoice == 3) { cout << "the computer chose scissors" << endl << endl; }

		/*if statements that tell you who won between you and the computer*/
		if (aichoice == 3 && userchoice == 1) { cout << "rock beats scissors, you win!" << endl << endl; usercount++; }
		else if (aichoice == 1 && userchoice == 2) { cout << "paper beats rock, you win!" << endl << endl; usercount++; }
		else if (aichoice == 2 && userchoice == 3) { cout << "scissors beats paper, you win!" << endl << endl; usercount++; }
		else if (aichoice == 2 && userchoice == 1) { cout << "paper beats rock, you lose!" << endl << endl; aicount++; }
		else if (aichoice == 1 && userchoice == 3) { cout << "rock beats scissors, you lose!" << endl << endl; aicount++; }
		else if (aichoice == 3 && userchoice == 2) { cout << "scissors beats paper, you lose!" << endl << endl; aicount++; }
		else { cout << "you chose the same thing, its a tie!" << endl << endl; } //this is if you tied

		
			cout << "would you like to play another round? (type 1 to play again and 0 to exit)" << endl; //properly asks the user if he/she would like to fight the mighty computer
			cin >> retry; //gets the response to either continue playing or close the program and give you the number of rounds played

			
		
		total++; //adds to the total every loop
	}


	count(total, aicount, usercount); //puts the total in count to display it to the user
	system("pause");
    return 0;
	
}

