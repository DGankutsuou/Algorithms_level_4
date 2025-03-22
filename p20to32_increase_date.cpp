#include "timelib.hpp"
#include "inputslib.h"

tms::s_date	add_x_days_to_date1(tms::s_date date, int x)
{
	short	counter = 0;

	while (counter < x)
	{
		date = tms::add_one_day_to_date(date);
		counter++;
	}
	return (date);
}

tms::s_date	add_one_week_to_date1(tms::s_date date)
{
	short	counter = 0;

	while (counter < 7)
	{
		date = tms::add_one_day_to_date(date);
		counter++;
	}
	return (date);
}

tms::s_date	add_x_weeks_to_date1(tms::s_date date, int x)
{
	short	counter = 0;

	while (counter < x)
	{
		date = add_one_week_to_date1(date);
		counter++;
	}
	return (date);
}

tms::s_date	add_one_month_to_date1(tms::s_date date)
{
	date.month++;
	if (date.month == 13)
	{
		date.month = 1;
		date.year++;
	}
	return (date);
}

tms::s_date	add_x_months_to_date1(tms::s_date date, int x)
{
	short	counter = 0;

	while (counter < x)
	{
		date = add_one_month_to_date1(date);
		counter++;
	}
	return (date);
}

tms::s_date	add_one_year_to_date1(tms::s_date date)
{
	date.year++;
	return (date);
}

tms::s_date	add_x_years_to_date1(tms::s_date date, int x)
{
	short	counter = 0;

	while (counter < x)
	{
		date = add_one_year_to_date1(date);
		counter++;
	}
	return (date);
}

tms::s_date	add_x_years_to_date1_faster(tms::s_date date, int x)
{
	date.year += x;
	return (date);
}

tms::s_date	add_one_decade_to_date1(tms::s_date date)
{
	date = add_x_years_to_date1_faster(date, 10);
	return (date);
}

tms::s_date	add_x_decades_to_date1(tms::s_date date, int x)
{
	short	counter = 0;

	while (counter < x)
	{
		date = add_one_decade_to_date1(date);
		counter++;
	}
	return (date);
}

tms::s_date	add_x_decades_to_date1_faster(tms::s_date date, int x)
{
	date.year += x * 10;
	return (date);
}

tms::s_date	add_one_century_to_date1(tms::s_date date)
{
	date = add_x_decades_to_date1(date, 10);
	return (date);
}

tms::s_date	add_one_millemuim_to_date1(tms::s_date date)
{
	for (int counter = 0; counter < 10; counter++)
	{
		date = add_one_century_to_date1(date);
	}
	return (date);
}

int	main(void)
{
	tms::s_date	date;

	date = tms::read_date("Enter Date: \n");
	tms::print_date(date);
	date = tms::add_one_day_to_date(date);
	cout << "Increased by one day: ";
	tms::print_date(date);
	date = add_x_days_to_date1(date, 10);
	cout << "Increased by ten days: ";
	tms::print_date(date);
	date = add_one_week_to_date1(date);
	cout << "Increased by one week: ";
	tms::print_date(date);
	date = add_x_weeks_to_date1(date, 10);
	cout << "Increased by ten weeks: ";
	tms::print_date(date);
	date = add_one_month_to_date1(date);
	cout << "Increased by one month: ";
	tms::print_date(date);
	date = add_x_months_to_date1(date, 5);
	cout << "Increased by five months: ";
	tms::print_date(date);
	date = add_one_year_to_date1(date);
	cout << "Increased by one year: ";
	tms::print_date(date);
	date = add_x_years_to_date1(date, 10);
	cout << "Increased by ten years: ";
	tms::print_date(date);
	date = add_x_years_to_date1_faster(date, 10);
	cout << "Increased faster by ten years: ";
	tms::print_date(date);
	date = add_one_decade_to_date1(date);
	cout << "Increased by one decade: ";
	tms::print_date(date);
	date = add_x_decades_to_date1(date, 10);
	cout << "Increased by ten decades: ";
	tms::print_date(date);
	date = add_x_decades_to_date1_faster(date, 10);
	cout << "Increased faster by ten decades: ";
	tms::print_date(date);
	date = add_one_century_to_date1(date);
	cout << "Increased by one century: ";
	tms::print_date(date);
	date = add_one_millemuim_to_date1(date);
	cout << "Increased by one millemuim: ";
	tms::print_date(date);
	return (0);
}
