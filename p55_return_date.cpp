#include "timelib.hpp"

tms::s_date	calculate_vacation_end(tms::s_date start, short vacation_days)
{
	tms::s_date	end;

	end = start;
	while (vacation_days)
	{
		if (tms::is_business_day(end))
			vacation_days--;
		end = tms::add_one_day_to_date(end);
	}
	return (end);
}

int	main(void)
{
	tms::s_date	date1;
	tms::s_date	date2;
	short		vacation_days;

	date1 = tms::read_date("\nEnter vacation start date\n");
	cout << "Vacation start: ";
	tms::print_date(date1);
	cout << "\n";
	vacation_days = input::read_positive_number("Enter vacation period: ");
	date2 = calculate_vacation_end(date1, vacation_days);
	cout << "\nVacation end: ";
	tms::print_date(date2);
	return (0);
}
