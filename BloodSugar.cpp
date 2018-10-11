// Matthew R Hanley
// Project 1: "Blood Sugar"
// COSC 2030
// BloodSugar.cpp

#include "BloodSugar.h"
#include <iostream>
#include <array>


using std::cin;
using std::cout;
using std::endl;
using std::string;

week week1 = { 1 };
week week2 = { 2 };
int daycounter = 0;

int main()
{
	string input;
	cout << "Blood Sugar Monitoring System" << endl;
	cout << "--------------------------------------------------------------------------------" << endl;
	cout << "Directions:" << endl;
	cout << "Enter only positive numerical values for blood sugar readings." << endl;
	cout << "Enter 'D' or 'Day' to view a daily summary." << endl;
	cout << "Enter 'W' or 'Week' to view a weekly summary." << endl;
	cout << "Enter 'N' or 'Next' to increment to the next day." << endl;
	cout << "--------------------------------------------------------------------------------" << endl;
	cout << "Begin entering values for day " << daycounter << ": " << endl;
	
	int test = daySum(week1.days[1]);
	cout << "test: " << test;



	system("pause");
	return 0;
}
