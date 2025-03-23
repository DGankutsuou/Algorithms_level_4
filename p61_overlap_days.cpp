#include "timelib.hpp"

short	count_overlaping_days1(tms::s_period period1, tms::s_period period2)
{
	if (!tms::does_periods_overlap(period1, period2))
		return (0);
	short	period1_length = tms::period_length_in_days(period1);
	short	period2_length = tms::period_length_in_days(period2);
	short	overlaped_days = 0;

	if (period1_length < period2_length)
	{
		while (tms::is_date1_before_date2(period1.start, period1.end))
		{
			if (tms::is_date_within_period(period2, period1.start))
				overlaped_days++;
			period1.start = tms::add_one_day_to_date(period1.start);
		}
	}
	else
	{
		while (tms::is_date1_before_date2(period2.start, period2.end))
		{
			if (tms::is_date_within_period(period1, period2.start))
				overlaped_days++;
			period2.start = tms::add_one_day_to_date(period2.start);
		}
	}
	return (overlaped_days);
}

short	count_overlaping_days2(tms::s_period period1, tms::s_period period2)
{
	short	overlaped_days = 0;

	if (!tms::does_periods_overlap(period1, period2))
		return (0);
	while (tms::is_date1_before_date2(period1.start, period1.end))
	{
		if (tms::is_date_within_period(period2, period1.start))
			overlaped_days++;
		period1.start = tms::add_one_day_to_date(period1.start);
	}
	return (overlaped_days);
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
		cout << "Overlaping days are: " << count_overlaping_days2(period1, period2) << endl;
	}
	else
		cout << "No, periods does not overlap" << endl;
	return (0);
}
