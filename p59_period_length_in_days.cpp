#include "timelib.hpp"

int	period_length_in_days(tms::s_period period, bool include_last_day = false)
{
	return (tms::difference_between_two_dates(period.start, period.end, include_last_day));
}

int	main(void)
{
	tms::s_period	period;

	period = tms::read_period("Enter the period\n");
	cout << "Period length in days: " << period_length_in_days(period) << endl;
	cout << "Period length in days with last day: " << period_length_in_days(period, true) << endl;
	return (0);
}
