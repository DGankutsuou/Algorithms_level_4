#include "timelib.hpp"
#include "inputslib.h"

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
	cout << "_______________";
	cout << month_symbol;
	cout << "_______________\n";
	cout << "sun  mon  tue  wed  thu  fri  sat" << endl;
}

void	print_month_calender(short month, short year)
{
	print_header(get_month_symbol(month));
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
