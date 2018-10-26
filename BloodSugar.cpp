// Matthew R Hanley
// Project 1: "Blood Sugar"
// COSC 2030
// BloodSugar.cpp

//#include "BloodSugar.h"
#include "LinkedList.h"
#include <iostream>
#include <array>
#include <sstream>


using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::iostream;

List days[14];
double buffer;
string input;
bool finished = false;
int daycounter = 0;
int main()
{
	cout << "<<< Blood Sugar Monitoring System >>>" << endl << endl;
	cout << "--------------------------------------------------------------------------------" << endl;
	cout << "Directions:" << endl;
	cout << "Enter only positive numerical values for blood sugar readings." << endl;
	cout << "Enter 'D' or 'Day' to view a daily summary." << endl;
	cout << "Enter 'W' or 'Week' to view a weekly summary." << endl;
	cout << "Enter 'N' or 'Next' to increment to the next day." << endl;
	cout << "--------------------------------------------------------------------------------" << endl << endl;
	cout << "<<< Day 1 >>>" << endl << endl;
	
	while (finished == false)
	{
		cout << "Enter a blood sugar reading or command:" << endl;
		cin >> input;
		buffer = strtof((input).c_str(), 0);
		if (input == "N" || input == "Next")
		{
			daycounter++;
			if (daycounter > 13)
			{
				finished = true;
			}
			else
			{
				cout << endl << "<<< Day " << daycounter + 1 << " >>>" << endl << endl;
			}
		}
		else if (input == "D" || input == "Day")
		{
			cout << "--------------------------------------------------------------------------------" << endl;
			cout << "Summary for day " << daycounter + 1 << ":" << endl;
			cout << "Sum of blood sugar readings: " << days[daycounter].sum() << endl;
			cout << "Maximum of blood sugar readings: " << days[daycounter].max() << endl;
			cout << "Minimum of blood sugar readings: " << days[daycounter].min() << endl;
			cout << "Count of blood sugar readings: " << days[daycounter].size() << endl;
			cout << "--------------------------------------------------------------------------------" << endl;
		}
		else if (input == "W" || input == "Week")
		{
			int first = 0;
			int weekindex = 0;
			if (daycounter < 7)
			{
				first = 0;
				weekindex = 1;
			}
			else
			{
				first = 7;
				weekindex = 2;
			}
			double weeksum = 0;
			double weekmax;
			double weekmin;
			int weekcount = 0;
			int delta = 0;
			int greatest = 0;
			int diff = 0;
			int val1 = 0;
			int val2 = 0;
			
			
			weekmax = days[first].max();
			weekmin = days[first].min();
			delta = 0;
			for (int index = first; index < first + 7; index++)
			{
				weeksum += days[index].sum();
				weekcount += days[index].size();
				if (days[index].max() > weekmax)
				{
					weekmax = days[index].max();
				}
				if (days[index].min() < weekmin && days[index].min() > 0)
				{
					weekmin = days[index].min();
				}
			}
			for (int index = first; index < first + 6; index++)
			{
				val1 = days[index].size();
				val2 = days[index + 1].size();					
				diff = val1 - val2;
				if (diff < 0)
				{
					diff = diff * (-1);
				}
				if (diff > greatest)
				{
					greatest = diff;
					delta = index;
				}
			}

			cout << "--------------------------------------------------------------------------------" << endl;
			cout << "Summary for week " << weekindex << ":" << endl;
			cout << "Sum of blood sugar readings: " << weeksum << endl;
			cout << "Maximum of blood sugar readings: " << weekmax << endl;
			cout << "Minimum of blood sugar readings: " << weekmin << endl;
			cout << "Count of blood sugar readings: " << weekcount << endl;
			cout << "Greatest delta of readings was between day " << (delta + 1) - first << " and day " << (delta + 2) - first << "." << endl;
			cout << "--------------------------------------------------------------------------------" << endl;
		}
		
		else if (!cin.good())
		{
			cin.clear();
			cin.ignore();
		}
		else if (buffer >= 1)
		{
			days[daycounter].insertAsFirst(buffer);
		}
	}

	system("pause");
	return 0;
}
