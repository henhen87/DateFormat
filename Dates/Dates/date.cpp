#include "stdafx.h"
#include <iostream>
#include <algorithm>

#include "date.h"
using std::cout;
using std::cin;
int global;

Date::Date() : month("January"), day(1), year(2001) {}

Date::Date(string m, int d, int y) 
{
	if (!validateDate(m, d, y))
	{
		Date();
	}
	else
	{
		month = m;
		day = d;
		year = y;
	}
}

bool Date::validateDate(string m, int d, int y)
{
	cout << "size is " << sizeof(monthStrAbbrev) / sizeof(monthStrAbbrev[0]) << endl;;
	int index = NULL;

	for (int x = 0; x < 11; x++)
	{
		string mAbr = monthStr[x].substr (0, 3);
		transform(mAbr.begin(), mAbr.end(), mAbr.begin(), (int(*) (int)) tolower);
		cout << "Abbr: " << mAbr << endl;
		if (m == mAbr)
		{
			index = x;
			global = x;
			cout << "x " << x << "global " << global << endl;
			if (d < 1 || d > monthDays[x])
			{
				return false;
			}
			if (y < MIN_YEAR || y > MAX_YEAR)
			{
				return false;
			}
			break;
		}
	}
	if (index == NULL)
	{
		return false;
	}
	else
	{
		return true;
	}
}

void Date::print(DateFormat type)
{
	if (type == mdy1)
	{
		cout << global + 1 << "/" << day << "/" << year << endl;
	}
	else if (type == mdy2)
	{
		cout << monthStr[global] << day + ", " << year << endl;
	}
	else if (type == ymd1)
	{
		cout << year + "-" << (global + 1) + "-" << day << endl;
	}
	else if (type = ymd2)
	{
		cout << year + "-" << month + "-" << day << endl;
	}
}