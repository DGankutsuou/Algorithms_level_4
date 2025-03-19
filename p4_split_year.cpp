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

s_year	count_year_times(short year)
{
	s_year	t_year;

	t_year.year = year;
	if (is_leap_year(year))
	{
		t_year.days = 366;
		t_year.is_leap = true;
	}
	else
		t_year.days = 365;
	t_year.hours = t_year.days * 24;
	t_year.minutes = t_year.hours * 60;
	t_year.seconds = t_year.minutes * 60;
	return (t_year);
}

void	print_year_times(s_year t_year)
{
	cout << "The year [" << t_year.year << "]\n" << endl;
	cout << "Number of days: " << t_year.days << "\n";
	cout << "Number of hours: " << t_year.hours << "\n";
	cout << "Number of minutes: " << t_year.minutes << "\n";
	cout << "Number of seconds: " << t_year.seconds << endl;
}

short	number_of_days_in_year(short year)
{
	if (is_leap_year(year))
		return (366);
	else
		return (365);
}

short	number_of_hours_in_year(short year)
{
	return (number_of_days_in_year(year) * 24);
}

int	number_of_minutes_in_year(short year)
{
	return (number_of_hours_in_year(year) * 60);
}

int	number_of_seconds_in_year(short year)
{
	return (number_of_minutes_in_year(year) * 60);
}

int	main(void)
{
	// s_year			t_year;
	unsigned short	year;

	year = input::read_positive_number("Enter a year: ");
	// t_year = count_year_times(year);
	// print_year_times(t_year);
	cout << "The year [" << year << "]\n" << endl;
	cout << "Number of days: " << number_of_days_in_year(year) << "\n";
	cout << "Number of hours: " << number_of_hours_in_year(year) << "\n";
	cout << "Number of minutes: " << number_of_minutes_in_year(year) << "\n";
	cout << "Number of seconds: " << number_of_seconds_in_year(year) << endl;
	return (0);
}