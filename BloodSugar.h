// Matthew R Hanley
// Project 1: "Blood Sugar"
// COSC 2030
// BloodSugar.h

struct day
{
	double readings[10];
	int size = 10;
};

struct week
{
	day days[7];
};

day getDay(int dayCounter)
{
	day today;
	if (dayCounter < 7)
	{
		today = week1.days[dayCounter];
	}
	else
	{
		today = week2.days[dayCounter - 7];
	}
	return today;
}

double daySum(day thisday)
{
	double sum = 0;
	for (int index = 0; index < thisday.size; index++)
	{
		sum += thisday.readings[index];
	}
	return sum;
}

double dayMax(day thisday)
{
	double max = 0;
	for (int index = 0; index < thisday.size; index++)
	{
		if (thisday.readings[index] > max)
		{
			max = thisday.readings[index];
		}
	}
	return max;
}

double dayMin(day thisday)
{
	double min = 0;
	for (int index = 0; index < thisday.size; index++)
	{
		if (thisday.readings[index] > min)
		{
			min = thisday.readings[index];
		}
	}
	return min;
}

int dayValid(day thisday)
{
	int index = 0;
	while (thisday.readings[index] != 0)
	{
		index++;
	}
	return index;
}

double weekSum(week thisweek)
{
	double sum = 0;
	for (int index = 0; index < 7; index++)
	{
		sum += daySum(thisweek.days[index]);
	}
	return sum;
}

double weekMax(week thisweek)
{
	double max = 0;
	for (int index = 0; index < 7; index++)
	{
		if (dayMax(thisweek.days[index]) > max)
		{
			max = dayMax(thisweek.days[index]);
		}
	}
	return max;
}

double weekMin(week thisweek)
{
	double min = 0;
	for (int index = 0; index < 7; index++)
	{
		if (dayMin(thisweek.days[index]) > min)
		{
			min = dayMin(thisweek.days[index]);
		}
	}
	return min;
}

int weekValid(week thisweek)
{
	int valid = 0;
	for (int index = 0; index < 7; index++)
	{
		valid += dayValid(thisweek.days[index]);
	}
	return valid;
}

int greatestDelta(week thisweek)
{
	int index = 0;
	int diff = 0;
	int maxdiff = 0;
	int maxday;
	double diffday1 = 0;
	double diffday2 = 0;
	while (index < 6)
	{
		diffday1 = daySum(thisweek.days[index]);
		diffday2 = daySum(thisweek.days[index + 1]);
		diff = diffday1 - diffday2;
		if (diff < 0)
		{
			diff = diff - (2 * diff);
		}
		if (diff > maxdiff)
		{
			maxdiff = diff;
			maxday = index;
		}
		index++;
	}
	return maxday;
}
