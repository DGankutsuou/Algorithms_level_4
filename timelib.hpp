#include <iostream>
using namespace std;

namespace time
{
	bool	is_leap_year(unsigned short year)
	{
		return (year % 400 == 0 || (year % 100 != 0 && year % 4 == 0));
	}

	short	number_of_days_in_year(short year)
	{
		return (is_leap_year(year) ? 366 : 365);
	}

	short	number_of_hours_in_year(short year)
	{
		return (number_of_days_in_year(year) * 24);
	}

	int	number_of_minutes_in_year(short year)
	{
		return (number_of_hours_in_year(year) * 60);
	}

	int	number_of_seconds_in_year(short year)
	{
		return (number_of_minutes_in_year(year) * 60);
	}
}
