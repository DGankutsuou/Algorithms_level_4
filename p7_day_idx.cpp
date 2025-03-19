#include <iostream>
#include "inputslib.h"
using namespace std;

short	day_idx(short day, short month, short year)
{
	short	a;
	short	y;
	short	m;
	short	d;

	a = (14 - month) / 12;
	y = year - a;
	m = month + 12 * a - 2;
	d = (day + y + y / 4 - y / 100 + y / 400 + (31 * m) / 12) % 7;
	return (d);
}

string	day_name(short index)
{
	string	week_days[7] = {
		"Sunday",
		"Monday",
		"Tuesday",
		"Wednesday",
		"Thursday",
		"Friday",
		"Saturday"
	};

	return (week_days[index]);
}

int	main(void)
{
	short	month;
	short	day;
	short	year;

	year = input::read_number("Enter the year: ");
	month = input::read_number_in_range("Enter a month ", 1, 12);
	day = input::read_number_in_range("Enter a day ", 1, 31);
	cout << "The day index is: " << day_idx(day, month, year) << endl;
	cout << "The day is: " << day_name(day_idx(day, month, year)) << endl;
	return (0);
}
