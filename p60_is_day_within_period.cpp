#include "timelib.hpp"

bool	is_day_within_period(tms::s_period period, tms::s_date date)
{
	e_cmparation	condition1;
	e_cmparation	condition2;

	condition1 = tms::compare_two_dates(date, period.end);
	condition2 = tms::compare_two_dates(date, period.start);
	return (!(condition1 == e_cmparation::after || condition2 == e_cmparation::before));
}

int	main(void)
{
	tms::s_period	period;
	tms::s_date		date;

	period = tms::read_period("Enter the period\n");
	date = tms::read_date("Enter the date\n");
	if (is_day_within_period(period, date))
		cout << "\nYes, the date is within the period" << endl;
	else
		cout << "\nNo, the date is not within the period" << endl;
	return (0);
}
