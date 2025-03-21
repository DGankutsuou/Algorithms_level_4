#include "timelib.hpp"

short	difference_between_two_dates(tms::s_date date1, tms::s_date date2, bool include_last_day)
{
	if (tms::is_date1_less_than_date2)
}

int	main(void)
{
	tms::s_date	date1;
	tms::s_date	date2;

	date1 = tms::read_date("Enter date 1\n");
	cout << "Date 1: ";
	tms::print_date(date1);
	date2 = tms::read_date("Enter date 2\n");
	cout << "Date 2: ";
	tms::print_date(date2);
	cout << endl;
	return (0);
}
