#include "timelib.hpp"

bool	date1_less_than_date2(tms::s_date date1, tms::s_date date2)
{
	short	date1_days = tms::get_day_order_in_year(date1.day, date1.month, date1.year);
	short	date2_days = tms::get_day_order_in_year(date2.day, date2.month, date2.year);
	bool	less_by_years = (date1.year < date2.year);
	bool	years_equal = (date1.year == date2.year);
	bool	less_by_days;

	less_by_days = date1_days < date2_days;
	return (less_by_years || (years_equal && less_by_days));
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
		cout << "Yes, date 1 is less than date 2" << endl;
	else
		cout << "No, date 1 is not less than date 2" << endl;
	return (0);
}
