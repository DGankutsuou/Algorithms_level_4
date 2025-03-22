#include "timelib.hpp"

enum e_cmparation {before = -1, equal, after};

e_cmparation	compare_two_dates(tms::s_date date1, tms::s_date date2)
{
	if (tms::is_date1_equal_to_date2(date1, date2))
		return (e_cmparation::equal);
	else if (tms::is_date1_before_date2(date1, date2))
		return (e_cmparation::before);
	return (e_cmparation::after);
}

int	main(void)
{
	tms::s_date	date1;
	tms::s_date	date2;

	date1 = tms::read_date("Enter date 1\n");
	cout << "Date 1: ";
	tms::print_date(date1);
	date2 = tms::read_date("\nEnter date 2\n");
	cout << "Date 2: ";
	tms::print_date(date2);
	cout << endl;
	cout << "Coparation result: " << (short)compare_two_dates(date1, date2);
	cout << endl;
	return (0);
}
