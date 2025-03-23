#include "timelib.hpp"

short	count_overlaping_days1(tms::s_period period1, tms::s_period period2)
{
	if (tms::does_periods_overlap(period1, period2))
	{
		if (tms::compare_two_dates(period1.start, period2.start) == e_cmparation::after)
			return (tms::difference_between_two_dates(period1.start, period2.end));
		else
			return (tms::difference_between_two_dates(period2.start, period1.end));
	}
	return (0);
}

short	count_overlaping_days1(tms::s_period period1, tms::s_period period2)
{
	if (tms::does_periods_overlap(period1, period2))
	{
		if (tms::compare_two_dates(period1.start, period2.start) == e_cmparation::after)
			return (tms::difference_between_two_dates(period1.start, period2.end));
		else
			return (tms::difference_between_two_dates(period2.start, period1.end));
	}
	return (0);
}

int	main(void)
{
	tms::s_period	period1;
	tms::s_period	period2;

	period1 = tms::read_period("Enter first period\n");
	period2 = tms::read_period("Enter second period\n");
	if (tms::does_periods_overlap(period1, period2))
	{
		cout << "Yes, periods overlap" << endl;
		cout << "Overlaping days are: " << count_overlaping_days1(period1, period2) << endl;
	}
	else
		cout << "No, periods does not overlap" << endl;
	return (0);
}
