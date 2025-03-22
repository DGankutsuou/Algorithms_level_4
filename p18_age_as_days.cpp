#pragma warning(disable:4996)
#include "timelib.hpp"
#include <ctime>

tms::s_date	get_system_date1()
{
	time_t	t = time(0);
	tm		*now = localtime(&t);
	tms::s_date	current_date;

	current_date.year = now->tm_year + 1900;
	current_date.month = now->tm_mon + 1;
	current_date.day = now->tm_mday;
	return (current_date);
}

short	get_age_as_days1(tms::s_date birthday)
{
	return (tms::difference_between_two_dates(birthday, get_system_date1(), true));
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
	cout << get_age_as_days1(birthday);
	cout << " days" << endl;
	return (0);
}
