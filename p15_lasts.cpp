#include "timelib.hpp"

bool	is_last_day_in_month1(tms::s_date date)
{
	return (date.day == tms::number_of_days_in_month(date.month, date.year));
}

bool	is_last_month_in_year1(tms::s_date date)
{
	return (date.month == 12);
}

int	main(void)
{
	tms::s_date	date;

	date = tms::read_date("Enter date \n");
	cout << "Date: ";
	tms::print_date(date);
	if (is_last_day_in_month1(date))
		cout << "Yes, this is last day in this month" << endl;
	else
		cout << "No, this is not last day in this month" << endl;
	if (is_last_month_in_year1(date))
		cout << "Yes, this is last month in this year" << endl;
	else
		cout << "No, this is not last month in this year" << endl;
	return (0);
}
