#include "timelib.hpp"
#include "inputslib.h"

tms::s_date	add_days_to_date(tms::s_date date, short number_of_days)
{
	tms::s_date	new_date = date;

	if (date.day != 1 || date.month != 1)
	{
		number_of_days += tms::get_day_order_in_year(date.day, date.month, date.year);
		new_date.day = 1;
		new_date.month = 1;
	}
	while (number_of_days > 365)
	{
		if (tms::is_leap_year(new_date.year))
		{
			number_of_days -= 366;
			new_date.year++;
		}
		else
		{
			number_of_days -= 365;
			new_date.year++;
		}
	}
	new_date = tms::get_date_from_day_order_in_year(number_of_days, new_date.year);
	return (new_date);
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
