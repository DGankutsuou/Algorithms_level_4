#include <iostream>
#include "inputslib.h"
using namespace std;

struct s_year
{
	short	year;
	bool	is_leap = false;
	short	days;
	int		hours;
	int		minutes;
	int		seconds;
};

bool	is_leap_year(unsigned short year)
{
	return (year % 400 == 0 || (year % 100 != 0 && year % 4 == 0));
}

short	number_of_days_in_month(short month, short year)
{
	short	number_of_days[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	return (month == 2 ? (is_leap_year(year) ? 29 : 28)
		: number_of_days[month - 1]);
}

short	number_of_hours_in_month(short month, short year)
{
	return (number_of_days_in_month(month, year) * 24);
}

int	number_of_minutes_in_month(short month, short year)
{
	return (number_of_hours_in_month(month, year) * 60);
}

int	number_of_seconds_in_month(short month, short year)
{
	return (number_of_minutes_in_month(month, year) * 60);
}

int	main(void)
{
	unsigned short	year;
	unsigned short	month;

	year = input::read_positive_number("Enter a year: ");
	month = input::read_number_in_range("Enter a month ", 1, 12);
	cout << "The month [" << month << "]\n" << endl;
	cout << "Number of days: " << number_of_days_in_month(month, year) << "\n";
	cout << "Number of hours: " << number_of_hours_in_month(month, year) << "\n";
	cout << "Number of minutes: " << number_of_minutes_in_month(month, year) << "\n";
	cout << "Number of seconds: " << number_of_seconds_in_month(month, year) << endl;
	return (0);
}
