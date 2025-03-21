#include "timelib.hpp"
#include "inputslib.h"

tms::s_date	add_days_to_date(tms::s_date date, short number_of_days)
{
	short	month_days = 0;

	number_of_days += tms::get_day_order_in_year(date.day, date.month, date.year);
	date.month = 1;
	while (true)
	{
		month_days = tms::number_of_days_in_month(date.month, date.year);
		if (number_of_days > month_days)
		{
			number_of_days -= month_days;
			date.month++;
			if (date.month > 12)
			{
				date.year++;
				date.month = 1;
			}
		}
		else
		{
			date.day = number_of_days;
			break ;
		}
	}
	return (date);
}

int	main(void)
{
	short		number_of_days;
	tms::s_date	date;

	date.year = input::read_number("Enter the year: ");
	date.month = input::read_number_in_range("Enter a month ", 1, 12);
	date.day = input::read_number_in_range("Enter a day ", 1, 31);
	tms::print_date(date);
	number_of_days = input::read_positive_number("Enter the number of days to add: ");
	date = add_days_to_date(date, number_of_days);
	tms::print_date(date);
	return (0);
}
