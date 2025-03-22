#include "timelib.hpp"

void	swap_dates(tms::s_date &date1, tms::s_date &date2)
{
	tms::s_date tmp;

	tmp = date1;
	date1 = date2;
	date2 = tmp;
}

int	ultimate_difference_between_two_dates1(tms::s_date date1, tms::s_date date2, bool include_last_day = false)
{
	int		difference = 0;
	short	flag = 1;

	if (!tms::is_date1_less_than_date2(date1, date2))
	{
		swap_dates(date1, date2);
		flag = -1;
	}
	while (!tms::is_date1_equal_to_date2(date1, date2))
	{
		date1 = tms::add_one_day_to_date(date1);
		difference++;
	}
	return (include_last_day ? ++difference * flag : difference * flag);
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
	cout << "ultimate difference between the two dates: ";
	cout << ultimate_difference_between_two_dates1(date1, date2) << endl;
	cout << "ultimate difference between the two dates including last day: ";
	cout << ultimate_difference_between_two_dates1(date1, date2, true) << endl;
	return (0);
}
