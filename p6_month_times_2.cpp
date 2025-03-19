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
	return (month == 2 ? (is_leap_year(year) ? 29 : 28)
		: (month <= 7 ? (month % 2 != 0 ? 31 : 30) : (month % 2 == 0 ? 31 : 30)));
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
	month = input::read_number_in_range(1, 12);
	cout << "The month [" << month << "]\n" << endl;
	cout << "Number of days: " << number_of_days_in_month(month, year) << "\n";
	cout << "Number of hours: " << number_of_hours_in_month(month, year) << "\n";
	cout << "Number of minutes: " << number_of_minutes_in_month(month, year) << "\n";
	cout << "Number of seconds: " << number_of_seconds_in_month(month, year) << endl;
	return (0);
}
