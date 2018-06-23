#pragma once

#include <iostream>
#include <string>
using namespace std;

/*Add more constants if needed*/
#ifndef DATE_H
#define DATE_H

enum DateFormat { mdy1, mdy2, ymd1, ymd2 };
const int MIN_YEAR = 1900;
const int MAX_YEAR = 2020;
const string monthStr[] =   //alternative:  const char monthStr[] [15]=
{ "January", "February", "March", "April", "May", "June",
"July", "August", "September", "October", "November",
"December" };
const string monthStrAbbrev[] =  //not strictly necessary, but helpful
{ "jan", "feb", "mar", "apr", "may", "jun",
"jul", "aug", "sep", "oct", "nov",
"dec" };
const int monthDays[] =
{ 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };


class Date {
private:
	string month;
	int day, year;
	bool validateDate(string, int, int);
	Date();
public:
	Date(string, int, int);
	void print(DateFormat type);
};
#endif // !DATES_H
