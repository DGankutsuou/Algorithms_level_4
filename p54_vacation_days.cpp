#include "timelib.hpp"

short	calculate_vacation_days1(tms::s_date start, tms::s_date end)
{
	short	counter = 0;

	while (tms::is_date1_less_than_date2(start, end))
	{
		if (tms::is_business_day(start))
			counter++;
		start = tms::add_one_day_to_date(start);
	}
	return (counter);
}

int	main(void)
{
	tms::s_date	date1;
	tms::s_date	date2;

	date1 = tms::read_date("\nEnter vacation start date\n");
	cout << "Vacation start: ";
	tms::print_date(date1);
	date2 = tms::read_date("\nEnter vacation end date\n");
	cout << "Vacation end: ";
	tms::print_date(date2);
	cout << endl;
	cout << "Vacation priod is: " << calculate_vacation_days1(date1, date2);
	cout << endl;
	return (0);
}
