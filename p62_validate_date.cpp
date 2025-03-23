#include "timelib.hpp"

bool	is_date_valid(tms::s_date date)
{
	if (date.day > 31 || date.day < 1)
		return (false);
	if (date.month > 12 || date.month < 1)
		return (false);
	else if (date.day > tms::number_of_days_in_month(date.month, date.year))
		return (false);
	return (true);
}

int	main(void)
{
	tms::s_date	date;

	date = tms::read_date("Enter a date\n");
	cout << "Date 1: ";
	tms::print_date(date);
	if (is_date_valid(date))
		cout << "Yes, this date is valid" << endl;
	else
		cout << "No, this date is not valid" << endl;
	return (0);
}
