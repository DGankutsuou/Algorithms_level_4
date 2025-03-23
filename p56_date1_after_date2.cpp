#include "timelib.hpp"

bool	date1_after_date2(tms::s_date date1, tms::s_date date2)
{
	return (tms::is_date1_before_date2(date2, date1));
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
	if (date1_after_date2(date1, date2))
		cout << "Yes, date 1 is after date 2" << endl;
	else
		cout << "No, date 1 is not after date 2" << endl;
	return (0);
}
