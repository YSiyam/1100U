// SalaryCalculator.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;


int main()
{
	int code, hours, overtime;
	double msalary, hsalary, csalary, psalary, mtotal, htotal, ctotal, ptotal, total, overtimepay;
	switch (code) {
	case 1:
		cout << "what is this managers weekly salary? " << endl;
		cin >> msalary;
		cout << "this managers salary is: " << msalary << endl;
		mtotal += msalary;

		break;
	case 2:
		cout << "what is this workers Hourly salary? " << endl;
		cin >> hsalary;
		cout << "how many hours has this employee worked? " << endl;
		cin >> hours;
		overtime = hours - 40;
		
		if (overtime > 0) {
			for (int i = 0; i <= overtime; i++) {
				int temp;
				temp = hsalary * 1.5;
				overtimepay += temp;
				

			}
			
		}
		else {
			cout << "this employee did not do any overtime hours!" << endl;
			overtime = 0;
			overtimepay = 0;
		}
		hours -= overtime;
		hsalary *= hours;
		hsalary += overtimepay;

		cout << "this employee's salary is:" << hsalary << endl;
		htotal += hsalary;

		break;
	case 3:
		
		break;
	case 4:

		break;
	default:
		cout << "not a valid code, exiting program";
		return EXIT_FAILURE;
	}
    return 0;
}

