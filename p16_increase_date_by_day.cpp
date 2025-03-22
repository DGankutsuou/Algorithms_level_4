#include "timelib.hpp"
#include "inputslib.h"

tms::s_date	add_one_day_to_date1(tms::s_date date)
{
	if (tms::is_last_day_in_month(date))
	{
		if (tms::is_last_month_in_year(date))
		{
			date.year++;
			date.month = 1;
			date.day = 1;
		}
		else
		{
			date.month++;
			date.day = 1;
		}
	}
	else
	{
		date.day++;
	}
	return (date);
}

int	main(void)
{
	tms::s_date	date;

	date = tms::read_date("Enter Date: \n");
	tms::print_date(date);
	date = add_one_day_to_date1(date);
	cout << "After increasing it by one day" << endl;
	tms::print_date(date);
	return (0);
}
