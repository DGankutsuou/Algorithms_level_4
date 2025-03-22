#include "timelib.hpp"
#include "inputslib.h"
#include <iomanip>

string	get_month_symbol(short month)
{
	string	symbol[12] = {
		"jan", "feb", "mar", "apr",
		"may", "jun", "jul", "aug",
		"sep", "oct", "nov", "dec"
	};

	return (symbol[month - 1]);
}

void	print_header(string month_symbol)
{
	cout << "\n  _______________";
	printf ("%s", month_symbol.c_str());
	cout << "_______________\n";
	cout << "  sun  mon  tue  wed  thu  fri  sat" << endl;
}

void	print_month_calender(short month, short year)
{
	short	day_idx;
	short	number_of_days;

	print_header(get_month_symbol(month));
	day_idx = tms::get_day_order_in_year(1, month, year);
	number_of_days = tms::number_of_days_in_month(month, year);
	for (int i = 0; i < day_idx; i++)
	{
		cout << "     ";
	}
	for (int i = 1; i <= number_of_days; i++)
	{
		// cout << right << setw(3) << i << "  ";
		printf ("%5d", i);
		if (day_idx == 6)
		{
			cout << "\n";
			day_idx = 0;
			continue ;
		}
		day_idx++;
	}
	cout << "\n" << endl;
}

int	main(void)
{
	short	year;
	short	month;

	year = input::read_positive_number("Enter a year: ");
	month = input::read_number_in_range("Enter a month ", 1, 12);
	print_month_calender(month, year);
	return (0);
}
