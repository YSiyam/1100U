

#include "stdafx.h"
#include <cmath> //this library is so we can use pow( , )
#include <iostream>
using namespace std;

//this program is used to display the monthly and total payment for each interest rate starting from 5% to 8%
int main()
{
	double loan, monthly, total, ans1, ans2, combined, interestfinal, lifepayments, loanperiod; //this is where I declare my variables

	//this is where I get my loan
	cout << "please enter the loan amount: " << endl;
	cin >> loan;
	//this is where I get my loan period
	cout << "Please enter the loan period: " << endl;
	cin >> loanperiod;

	//this forloop uses the interest rate as a variable to keep going, all calculations are done in the loop
	for (double interestrate = 5.00; interestrate <= 8; interestrate = interestrate + 0.125)
	{
		interestfinal = (interestrate / 100) / 12; //this is used to get an interest rate that we will use in the equations
		lifepayments = loanperiod * 12; //this the number of payments over the life of the loan or loanperiod;

		ans1 = interestfinal * pow(1 + interestfinal, lifepayments); //this is the top half of the monthly mortage formula pow is used to calculate to the power of
		ans2 = pow(1 + interestfinal, lifepayments) - 1; //this is the bottom half of the monthly mortage formula pow is used to calculate to the power of
		combined = ans1 / ans2; //this combines ans1 and ans2 like in the formula

		monthly = loan * combined; //this completes the formula by multiplying the loan with the combined ans1 and ans2

		total = lifepayments * monthly; //this gives me the total amount currently due!

		cout << "your interest rate is: " << interestrate << " and your monthly payment is: " << monthly << " and your Total is currently: " << total << endl;
	}
	system("pause");
    return 0;
}

