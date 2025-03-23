#include "timelib.hpp"

short	get_day_order_in_week1(tms::s_date date)
{
	short	a;
	short	y;
	short	m;
	short	d;

	a = (14 - date.month) / 12;
	y = date.year - a;
	m = date.month + 12 * a - 2;
	d = (date.day + y + y / 4 - y / 100 + y / 400 + (31 * m) / 12) % 7;
	return (d);
}

void	print_current_date()
{
	tms::s_date	date;

	date = tms::get_system_date();
	cout << "Today is " << tms::day_name(get_day_order_in_week1(date));
	cout << " ";
	tms::print_date(date);
}

bool	is_end_of_week1(tms::s_date date)
{
	return (get_day_order_in_week1(date) == 6);
}

bool	is_weekend1(tms::s_date date)
{
	return (get_day_order_in_week1(date) >= 5);
}

bool	is_business_day1(tms::s_date date)
{
	return (!is_weekend1(date));
}

short	days_until_end_of_week1(tms::s_date date)
{
	return (6 - get_day_order_in_week1(date));
}

short	days_until_end_of_month1(tms::s_date date)
{
	tms::s_date	end_of_month;

	end_of_month = date;
	end_of_month.day = tms::number_of_days_in_month(date.month, date.year);
	return (tms::difference_between_two_dates(date, end_of_month));
}

short	days_until_end_of_year1(tms::s_date date)
{
	tms::s_date	end_of_year;

	end_of_year.year = date.year;
	end_of_year.month = 12;
	end_of_year.day = 31;
	return (tms::difference_between_two_dates(date, end_of_year));
}

int	main(void)
{
	tms::s_date	date;

	print_current_date();
	date = tms::get_system_date();
	cout << "\nIs it the end of week?" << endl;
	if (is_end_of_week1(date))
		cout << "Yes, this is the end of week" << endl;
	else
		cout << "No, this is not the end of week" << endl;
	cout << "\nIs it the weekend?" << endl;
	if (is_weekend1(date))
		cout << "Yes, this is the weekend" << endl;
	else
		cout << "No, this is not the weekend" << endl;
	cout << "\nIs it a business day?" << endl;
	if (is_business_day1(date))
		cout << "Yes, this is business day" << endl;
	else
		cout << "No, this is not business day" << endl;
	cout << "\nDays until end of week: " << days_until_end_of_week1(date);
	cout << "\nDays until end of month: " << days_until_end_of_month1(date);
	cout << "\nDays until end of year: " << days_until_end_of_year1(date) << endl;
	return (0);
}
