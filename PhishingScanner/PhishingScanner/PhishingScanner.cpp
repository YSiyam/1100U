// Yazan Siyam 100622746
// Pam Hammer 100622255

#include "stdafx.h"
#include <iostream>
#include <string>
#include <fstream>
#include <iosfwd>

using namespace std;

void intro(); //just a fancy intro
void getWords(string[]); //this function gets the words given from words.txt
void scanner(string[], int[]); //this function is in charge of scanning the emails
void getscores(int[]); //this function prints the scores in a .txt
void top(int[]); //this function prints out the top scores

//the one globalvariable I need
int howmany; //this is to ask you how many emails you want to scan so you don't have to painfully go through all 1387 of them

int main()
{
	 intro(); //just calls the intro function
	 cout << "how many emails would you like to scan? max: 1387" << endl; //this asks you how many emails you want to scan
	 cin >> howmany; //stores the answer in howmany the global variable from earlier

	 if (howmany > 1387) {	 howmany = 1387; } //makes sure you don't exceed 1387 emails therefore crashing the program

	 int emails = howmany; //setting emails as whatever the cout you gave us is
	 int scores[1378] = { 0 }; //sets an array up with 1378 '0's

	string phishing[20]; //sets up an array up where phishing words will be stored
	getWords(phishing); //puts phishing in the getWords function to store the words from words.txt

	scanner(phishing, scores); //calls the function to test and store the results
	getscores(scores); //calls the function getscores
	top(scores); //calls the function top

    return 0;
}

void intro() {
	cout << "welcome to phishing scanner 2016, \n please input emails and we will scan it for you and give you a score! \n Have fun!" << endl; //just an intro for the program
	system("PAUSE");
}

void getWords(string words[]) {  //this is the getwords function explained earlier

	ifstream file; //this is to read files
	file.open("words.txt"); //this opens the file
	
	if (file.is_open()) { //if statement to that goes if the file has been opened correctly
		for (int w = 1; w >= 19; w++) { //if statement that gets the 19 words from the text document
			getline(file, words[w]); //gets the words in each line
		}
	}
	else { //this happens if the program can't open the words.txt document
		cout << "can't open words.txt" << endl;
			system("PAUSE");
		exit(1);
	}
	file.close(); //closes the file that was opened previously
}

void scanner(string words[], int scores[]) { //this is in charge of scanning the emails
	ifstream file; //this is to read files
	string fileName; //this holds the name of the file
	string line; //initializes string line

	int finder; //intializes int finder which is in charge of finding
	int t = 0; //intializes int t which is is short for time

	for (int e = 0; e < howmany; e++) { //this for loop is in charge of ensuring you go through all the emails
		fileName = to_string(e) + ".txt"; //this is in charge of changing the name of the file
		file.open(fileName); //opens the file

		int lnum = 1; //initializes and sets lnum which is in charge of counting the line number

		if (file.is_open()) { //if loop that activates if the file is opened
			while (!file.eof()) { //reads everything till the line ends
				getline(file, line); //gets the line and stores it in line

				for (int w = 0; w < 20; w++) { //this runs through all the words gotten
					finder = 0; //sets finder to 0
					t = 0; //sets t to 0

					finder = line.find(words[w], finder); //sets finder to the first time the phishing word is found

					while (finder != string::npos) { // this finds all the phshing words if it found the first one
						finder = line.find(words[w], finder); //goes to the next time the phishing word is found

						if (finder != string::npos) { // this if statement happens if the word is found again
							finder++; //increases finder to start looking for the next word
							t++; //increases the number of times it is found
						}
					}

					if (t != 0) { //this happens if there was a word found
						cout << words[w] << " found " << t << " times on line #" << lnum << " on email #" << e << endl;
						scores[e] += ((w + 1) * t); //updates scores
					}
				}
				lnum++; //increases the line number
			}
		}
		else { //this happens if the file didn't open
			cout << "can't open the email" << endl;
			system("PAUSE");
			exit(1);
		}
		file.close(); //closes the file

	}

	return;
}

void getscores(int scores[]) { //this stores the results in scores.txt
	
	ofstream file("scores.txt"); //ofstream that creates and writes to scores.txt

	if (file.is_open()) { //does stuff if the file is open
		for (int x = 0; x < howmany; x++) { //for loop that goes as long as x is less than howmany
			file << to_string(x) << ".txt" << endl; //prints stuff to the .txt
			file << "score: " << scores[x] << endl; //prints more stuff to the .txt
		}

		
	}
	else { //another else loop that closes the program if it doesn't work
		cout << "can't open file" << endl;
		system("PAUSE");
		exit(1);
	}
	file.close(); //closes the file
	return;
}
	
void top(int scores[]) { //this prints out the top scores
	int topscores[5] = { 0 }; //makes an array called topscores
	int topscore; //makes a int called topscore
	int x; //makes int x

	cout << "These are your top 5 scores:" << endl; //this is a cout
	for (int t = 0; t < 5; t++) { //a for loop that goes up to 5 times for the top 5 scores
		topscore = 0; //sets topscore as 0
		
		for (int e = 0; e < howmany; e++) { //for loop that goes through the emails to get the top score
			if (scores[e] > scores[topscore]) { //if loops that activates if it found a higher score
				topscore = e; //sets topscore to e
				x = e; //sets x to e too
			}
		}
			topscores[t] = scores[topscore]; // sets scores[topscore] and puts it in topscores[t]
			scores[topscore] = 0; //sets scores to 0

			cout << x << ".txt's score is: "<< topscores[topscore] << endl; //prints out the top 5
		
			system("PAUSE");
	}
	return;
}