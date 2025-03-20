#include "timelib.hpp"
#include "inputslib.h"

short	days_number_to_date_in_year(short day, short month, short year)
{
	short	number_of_days = 0;

	for (int m = 1; m < month; m++)
	{
		number_of_days += tms::number_of_days_in_month(m, year);
	}
	number_of_days += day;
	return (number_of_days);
}

int	main(void)
{
	short	month;
	short	day;
	short	year;

	year = input::read_number("Enter the year: ");
	month = input::read_number_in_range("Enter a month ", 1, 12);
	day = input::read_number_in_range("Enter a day ", 1, 31);
	cout << "The number of days from the beginning of the year is: ";
	cout << days_number_to_date_in_year(day, month, year);
	return (0);
}
