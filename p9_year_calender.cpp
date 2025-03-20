#include "timelib.hpp"
#include "inputslib.h"

void	print_year_calender_header(short year)
{
	cout << "\n  _________________________________\n";
	cout << "            Calender . " << year << "            ";
	cout << "\n  _________________________________" << endl;
}

void	print_year_calender(short year)
{
	print_year_calender_header(year);
	for (int m = 1; m <= 12; m++)
	{
		tms::print_month_calender(m, year);
	}
}

int	main(void)
{
	short	year;

	year = input::read_positive_number("Enter a year: ");
	print_year_calender(year);
	return (0);
}
