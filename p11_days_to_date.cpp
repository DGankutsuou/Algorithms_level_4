#include "timelib.hpp"
#include "inputslib.h"

struct s_date
{
	short	day;
	short	month;
	short	year;
};

s_date	get_date_from_day_order_in_year(short number_of_days, short year)
{
	s_date	date;
	short	number_of_days_of_month;

	date.year = year;
	date.month = 1;
	while (true)
	{
		number_of_days_of_month = tms::number_of_days_in_month(date.month, year);
		if (number_of_days > number_of_days_of_month)
		{
			number_of_days -= number_of_days_of_month;
			date.month++;
		}
		else
		{
			date.day = number_of_days;
			break ;
		}
	}
	return (date);
}

void	print_date(s_date date)
{
	cout << date.day << "/" << date.month << "/" << date.year << endl;
}

int	main(void)
{
	short	month;
	short	day;
	short	year;
	short	number_of_days;
	s_date	date;

	year = input::read_number("Enter the year: ");
	month = input::read_number_in_range("Enter a month ", 1, 12);
	day = input::read_number_in_range("Enter a day ", 1, 31);
	number_of_days = tms::get_day_order_in_year(day, month, year);
	cout << "The number of days from the beginning of the year is: ";
	cout << number_of_days << endl;
	date = get_date_from_day_order_in_year(number_of_days, year);
	cout << "date for [" << number_of_days << "]: ";
	print_date(date);
	return (0);
}
