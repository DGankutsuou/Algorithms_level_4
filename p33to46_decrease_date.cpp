#include "timelib.hpp"
#include "inputslib.h"

tms::s_date	decrease_one_day_from_date1(tms::s_date date)
{
	if (date.day == 1)
	{
		if (date.month == 1)
		{
			date.year--;
			date.month = 12;
			date.day = 31;
		}
		else
		{
			date.month--;
			date.day = tms::number_of_days_in_month(date.month, date.year);
		}
	}
	else
	{
		date.day--;
	}
	return (date);
}

tms::s_date	decrease_x_days_from_date1(tms::s_date date, int x)
{
	short	counter = 0;

	while (counter < x)
	{
		date = decrease_one_day_from_date1(date);
		counter++;
	}
	return (date);
}

tms::s_date	decrease_one_week_from_date1(tms::s_date date)
{
	short	counter = 0;

	while (counter < 7)
	{
		date = decrease_one_day_from_date1(date);
		counter++;
	}
	return (date);
}

tms::s_date	decrease_x_weeks_from_date1(tms::s_date date, int x)
{
	short	counter = 0;

	while (counter < x)
	{
		date = decrease_one_week_from_date1(date);
		counter++;
	}
	return (date);
}

tms::s_date	decrease_one_month_from_date1(tms::s_date date)
{
	short	days;

	date.month--;
	if (date.month == 0)
	{
		date.month = 12;
		date.year--;
	}
	days = tms::number_of_days_in_month(date.month, date.year);
	if (date.day > days)
	{
		date.day = days;
	}
	return (date);
}

tms::s_date	decrease_x_months_from_date1(tms::s_date date, int x)
{
	short	counter = 0;

	while (counter < x)
	{
		date = decrease_one_month_from_date1(date);
		counter++;
	}
	return (date);
}

tms::s_date	decrease_one_year_from_date1(tms::s_date date)
{
	date.year--;
	return (date);
}

tms::s_date	decrease_x_years_from_date1(tms::s_date date, int x)
{
	short	counter = 0;

	while (counter < x)
	{
		date = decrease_one_year_from_date1(date);
		counter++;
	}
	return (date);
}

tms::s_date	decrease_x_years_from_date1_faster(tms::s_date date, int x)
{
	date.year -= x;
	return (date);
}

tms::s_date	decrease_one_decade_from_date1(tms::s_date date)
{
	date.year -= 10;
	return (date);
}

tms::s_date	decrease_x_decades_from_date1(tms::s_date date, int x)
{
	short	counter = 0;

	while (counter < x)
	{
		date = decrease_one_decade_from_date1(date);
		counter++;
	}
	return (date);
}

tms::s_date	decrease_x_decades_from_date1_faster(tms::s_date date, int x)
{
	date.year -= x * 10;
	return (date);
}

tms::s_date	decrease_one_century_from_date1(tms::s_date date)
{
	date.year -= 100;
	return (date);
}

tms::s_date	decrease_one_millemuim_from_date1(tms::s_date date)
{
	date.year -= 1000;
	return (date);
}

int	main(void)
{
	tms::s_date	date;

	date = tms::read_date("Enter Date: \n");
	tms::print_date(date);
	date = decrease_one_day_from_date1(date);
	cout << "Increased by one day: ";
	tms::print_date(date);
	date = decrease_x_days_from_date1(date, 10);
	cout << "Increased by ten days: ";
	tms::print_date(date);
	date = decrease_one_week_from_date1(date);
	cout << "Increased by one week: ";
	tms::print_date(date);
	date = decrease_x_weeks_from_date1(date, 10);
	cout << "Increased by ten weeks: ";
	tms::print_date(date);
	date = decrease_one_month_from_date1(date);
	cout << "Increased by one month: ";
	tms::print_date(date);
	date = decrease_x_months_from_date1(date, 5);
	cout << "Increased by five months: ";
	tms::print_date(date);
	date = decrease_one_year_from_date1(date);
	cout << "Increased by one year: ";
	tms::print_date(date);
	date = decrease_x_years_from_date1(date, 10);
	cout << "Increased by ten years: ";
	tms::print_date(date);
	date = decrease_x_years_from_date1_faster(date, 10);
	cout << "Increased faster by ten years: ";
	tms::print_date(date);
	date = decrease_one_decade_from_date1(date);
	cout << "Increased by one decade: ";
	tms::print_date(date);
	date = decrease_x_decades_from_date1(date, 10);
	cout << "Increased by ten decades: ";
	tms::print_date(date);
	date = decrease_x_decades_from_date1_faster(date, 10);
	cout << "Increased faster by ten decades: ";
	tms::print_date(date);
	date = decrease_one_century_from_date1(date);
	cout << "Increased by one century: ";
	tms::print_date(date);
	date = decrease_one_millemuim_from_date1(date);
	cout << "Increased by one millemuim: ";
	tms::print_date(date);
	return (0);
}
