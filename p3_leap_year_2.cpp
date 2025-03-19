#include <iostream>
#include "inputslib.h"
using namespace std;

bool	is_leap_year(unsigned short year)
{
	return (year % 400 == 0 || (year % 100 != 0 && year % 4 == 0));
}

int	main(void)
{
	unsigned short	year;

	year = input::read_positive_number("Enter a year: ");
	if (is_leap_year(year))
		cout << year << " is a leap year" << endl;
	else
		cout << year << " is not a leap year" << endl;
	return (0);
}