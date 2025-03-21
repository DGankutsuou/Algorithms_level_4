#include "timelib.hpp"

bool	date1_less_than_date2(tms::s_date date1, tms::s_date date2)
{
	bool	years_equal = (date1.year == date2.year);
	bool	months_equal = (date1.month == date2.month);
	bool	days_equal = (date1.day == date2.day);

	return (years_equal ? (months_equal ? days_equal : false) : false);
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
	if (date1_less_than_date2(date1, date2))
		cout << "Yes, date 1 is equal to date 2" << endl;
	else
		cout << "No, date 1 is not equal to date 2" << endl;
	return (0);
}
