#include "timelib.hpp"

struct	s_period
{
	tms::s_date	start;
	tms::s_date	end;
};

s_period	read_period(string message)
{
	s_period	period;

	cout << message;
	period.start = tms::read_date("\nEnter start date\n");
	period.end = tms::read_date("\nEnter end date\n");
	cout << endl;
	return (period);
}

bool	does_periods_overlap1(s_period period1, s_period period2)
{
	if (!tms::is_date1_after_date2(period1.start, period2.start))
	{
		if (!tms::is_date1_before_date2(period1.end, period2.start))
			return (true);
	}
	else
	{
		if (!tms::is_date1_before_date2(period2.end, period1.start))
			return (true);
	}
	return (false);
}

bool	does_periods_overlap2(s_period period1, s_period period2)
{
	e_cmparation	condition1;
	e_cmparation	condition2;

	condition1 = tms::compare_two_dates(period1.end, period2.start);
	condition2 = tms::compare_two_dates(period1.start, period2.end);
	if (condition1 == e_cmparation::before || condition2 == e_cmparation::after)
		return (false);
	return (true);
}

int	main(void)
{
	s_period	period1;
	s_period	period2;

	period1 = read_period("Enter first period\n");
	period2 = read_period("Enter second period\n");
	if (does_periods_overlap1(period1, period2))
		cout << "Yes, periods overlap" << endl;
	else
		cout << "No, periods does not overlap" << endl;
	cout << "______________________" << endl;
	if (does_periods_overlap2(period1, period2))
		cout << "Yes, periods overlap" << endl;
	else
		cout << "No, periods does not overlap" << endl;
	return (0);
}
