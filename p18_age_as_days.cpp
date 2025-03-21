#pragma warning(disable:4996)
#include "timelib.hpp"
#include <ctime>

short	difference_between_two_dates(tms::s_date date1, tms::s_date date2, bool include_last_day = false)
{
	short	difference = 0;

	if (tms::is_date1_less_than_date2(date1, date2))
	{
		while (!tms::is_date1_equal_to_date2(date1, date2))
		{
			date1 = tms::add_one_day_to_date(date1);
			difference++;
		}
		return (include_last_day ? ++difference : difference);
	}
	return (difference);
}

tms::s_date	get_system_date()
{
	time_t	t = time(0);
	tm		*now = localtime(&t);
	tms::s_date	current_date;

	current_date.year = now->tm_year + 1900;
	current_date.month = now->tm_mon + 1;
	current_date.day = now->tm_mday;
	return (current_date);
}

short	get_age_as_days(tms::s_date birthday)
{
	return (difference_between_two_dates(birthday, get_system_date(), true));
}

int	main(void)
{
	tms::s_date	birthday;

	birthday = tms::read_date("Enter your birthday\n");
	cout << "\n";
	cout << "Your birthday: ";
	tms::print_date(birthday);
	cout << endl;
	cout << "You have lived ";
	cout << get_age_as_days(birthday);
	cout << " days" << endl;
	return (0);
}
