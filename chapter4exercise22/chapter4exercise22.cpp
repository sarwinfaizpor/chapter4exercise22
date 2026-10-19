#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int main()
{
	const double PLAN_A_PRICE = 39.99;
	const double PLAN_B_PRICE = 59.99;
	const double PLAN_C_PRICE = 79.99;
	const double PLAN_A_DATA = 2.0;
	const double PLAN_B_DATA = 8.0;
	const double EXTRA_RATE = 8.0;

	string name;
	char plan;
	double gigabytes;
	double billA, billB, total;

	cout << "Enter customer name: ";
	getline(cin, name);
	cout << "Enter your plan (A, B, or C): ";
	cin >> plan;
	if (plan == 'a')
		plan = 'A';
	else if (plan == 'b')
		plan = 'B';
	else if (plan == 'c')
		plan = 'C';

	if (plan != 'A' && plan != 'B' && plan != 'C')
	{
		cout << "Invalid plan." << endl;
		return 0;
	}

	cout << "Enter gigabytes used: ";
	cin >> gigabytes;

	if (!cin || gigabytes < 0)
	{
		cout << "Invalid data usage." << endl;
		return 0;
	}
	billA = PLAN_A_PRICE;
	if (gigabytes > PLAN_A_DATA)
	{
		billA += (gigabytes - PLAN_A_DATA) * EXTRA_RATE;
	}

	billB = PLAN_B_PRICE;
	if (gigabytes > PLAN_B_DATA)
	{
		billB += (gigabytes - PLAN_B_DATA) * EXTRA_RATE;
	}

	if (plan == 'A')
		total = billA;
	else if (plan == 'B')
		total = billB;
	else
		total = PLAN_C_PRICE;

	cout << fixed << setprecision(2);
	cout << "\nMonthly Bill" << endl;
	cout << "Customer: " << name << endl;
	cout << "Plan: " << plan << endl;
	cout << "Gigabytes used: " << gigabytes << endl;
	cout << "Total amount due: $" << total << endl;

	if (plan == 'A')
	{
		if (billA > billB)
		{
			cout << "Savings with Plan B: $"
				<< billA - billB << endl;
		}

		if (billA > PLAN_C_PRICE)
		{
			cout << "Savings with Plan C: $"
				<< billA - PLAN_C_PRICE << endl;
		}
	}
	else if (plan == 'B')
	{
		if (billB > PLAN_C_PRICE)
		{
			cout << "Savings with Plan C: $"
				<< billB - PLAN_C_PRICE << endl;
		}
	}
	return 0;
}
