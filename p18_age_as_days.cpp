#pragma warning(disable:4996)
#include "timelib.hpp"
#include <ctime>

short	difference_between_two_dates(tms::s_date date1, tms::s_date date2, bool include_last_day = false)
{
	short	difference = 0;

	if (tms::is_date1_less_than_date2(date1, date2))
	{
		while (!tms::is_date1_equal_to_date2(date1, date2))
		{
			date1 = tms::add_one_day_to_date(date1);
			difference++;
		}
		return (include_last_day ? ++difference : difference);
	}
	return (difference);
}

int	main(void)
{
	time_t	t = time(0);
	tm		*now = localtime(&t);
	tms::s_date	date1;
	tms::s_date	date2;

	date1 = tms::read_date("Enter your birthday\n");
	cout << "\n";
	cout << "Your birthday: ";
	tms::print_date(date1);
	date2.year = now->tm_year + 1900;
	date2.month = now->tm_mon + 1;
	date2.day = now->tm_mday;
	cout << "Current date: ";
	tms::print_date(date2);
	cout << endl;
	cout << "You have lived ";
	cout << difference_between_two_dates(date1, date2);
	cout << " days" << endl;
	//cout << "difference between the two dates including last day: ";
	//cout << difference_between_two_dates(date1, date2, true) << endl;
	return (0);
}
