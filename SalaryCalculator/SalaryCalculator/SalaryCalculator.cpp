// SalaryCalculator.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

//this program calculates the wages for each type of employee given in the company and tells you the total for each at the end
int main()
{

	//this is where i initiliaze and declare some variables;
	int code, employees, hours, overtime, cinitial(250);
	double msalary, hsalary, csalary, psalary, mtotal(0), htotal(0), ctotal(0), ptotal(0), total(0), overtimepay, gross, itemprice, itemsmade;

	//this is to find out how many employees work for you
	cout << "how many employee's work for you? " << endl;
	cin >> employees;

	//for loop meant to go through the switch statement based on number of employees
	for (int x = 0; x < employees; x++) {

		cout << "please enter employee code: " << endl;
		cin >> code; //this tells the switch statement what case it will use

		switch (code) {

		case 1: //this case calculates a managers pay

			cout << "what is this managers weekly salary? " << endl;
			cin >> msalary; //this tells you this specific managers salary

			cout << "this managers salary is: " << endl
				<< msalary << endl; //this prints out this specific managers pay
			mtotal += msalary; //this adds this specific managers pay to the total salary paid to all managers

			break;

		case 2: //this case calculates a hourly employees pay
			cout << "what is this workers Hourly salary? " << endl;
			cin >> hsalary; //this tells you how much money the employee recieves per hour

			cout << "how many hours has this employee worked? " << endl; //this tells you the hours the employee worked
			cin >> hours;

			overtime = hours - 40; //this gets the overtime if it exists

			if (overtime > 0) { //if the overtime exists it calculates how much pay the employee recieves

				for (int i = 0; i <= overtime; i++) {

					double temp;

					temp = hsalary * 1.5; //this puts the payment for 1 overtime hour in temp
					overtimepay += temp; //this stores that 1 overtime hour in the whole overtimepay
				}
			}

			else { //this executes if there if the employee didn't do any overtime hours, it also makes sure that the hours don't change from -overtime

				cout << "this employee didn't do any overtime hours!" << endl;

				overtime = 0; //sets overtime to 0 so the calculation below doesn't give us the wrong number of hours
				overtimepay = 0; //sets overtime pay to 0
			}

			hours -= overtime; //this sets the hours depending on what the user put earlier up to 40 because overtime will keep it at 40
			hsalary *= hours; //this is the employee's salary without overtime pay
			hsalary += overtimepay; //this is the employee's salary with overtime pay

			cout << "this employee's salary is:" << endl
				<< hsalary << endl; //this prints out this specific employees salary
			htotal += hsalary; //this adds this specific employees salary to the total salary

			break;

		case 3: //this case calculates commission workers salary

			cout << "what is this gross weekly sale? " << endl;
			cin >> gross; //this gets the gross weekly sale from the user

			csalary = (0.057 * gross) + cinitial; //this calculates the the commision workers salary with the initial of 250 and 5.7% of the gross weekly sale

			cout << "this employee's salary is:" << endl
				<< csalary << endl; //this prints out this specifics employees salary
			ctotal += csalary; //this adds this specific employees salary into the total

			break;

		case 4: //this calculates a pieceworkers salary

			cout << "how much money does this employee recieve per item made? " << endl;
			cin >> itemprice; //this gets how much money per item the employee makes from the user

			cout << "how many items has this employee produced?" << endl;
			cin >> itemsmade; //this gets how many items were produced from the user

			psalary = itemprice * itemsmade; //this calculates the salary

			cout << "this employee's salary is" << endl
				<< psalary << endl; //this prints out this specific employees salary
			ptotal += psalary; //this adds this specific employees salary into the total

			break;

		default: //this executes if you did not put a valid employee code and terminates the program

			cout << "not a valid code, exiting program";
			system("pause");

			return EXIT_FAILURE;
		}
	}

	total = mtotal + htotal + ctotal + ptotal; //this gets the total money used on all your employees

											   //this prints each type of employees total salary along with the total in general
	cout << "Total Salary given to managers: " << mtotal << endl
		<< "Total Salary given to hourly workers: " << htotal << endl
		<< "Total Salary given to commision workers: " << ctotal << endl
		<< "Total Salary given to pieceworkers: " << ptotal << endl
		<< "Total Salary Given: " << total << endl;

	system("pause");
	return 0;
}
