#pragma once
# include <iostream>
# include "inputslib.h"
# include <ctime>
using namespace std;

enum e_cmparation {before = -1, equal, after};

void	print_month_calender_header(string month_symbol)
{
	cout << "\n  _______________";
	printf ("%s", month_symbol.c_str());
	cout << "_______________\n";
	cout << "  sun  mon  tue  wed  thu  fri  sat" << endl;
}

void	print_year_calender_header(short year)
{
	cout << "\n  _________________________________\n";
	cout << "            Calender . " << year << "            ";
	cout << "\n  _________________________________" << endl;
}

namespace tms
{
	struct s_date
	{
		short	day;
		short	month;
		short	year;
	};

	struct	s_period
	{
		s_date	start;
		s_date	end;
	};

	bool is_leap_year(unsigned short year)
	{
		return (year % 400 == 0 || (year % 100 != 0 && year % 4 == 0));
	}

	short number_of_days_in_year(short year)
	{
		return (is_leap_year(year) ? 366 : 365);
	}

	short number_of_hours_in_year(short year)
	{
		return (number_of_days_in_year(year) * 24);
	}

	int number_of_minutes_in_year(short year)
	{
		return (number_of_hours_in_year(year) * 60);
	}

	int number_of_seconds_in_year(short year)
	{
		return (number_of_minutes_in_year(year) * 60);
	}

	short number_of_days_in_month(short month, short year)
	{
		short number_of_days[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
		return (month == 2 ? (is_leap_year(year) ? 29 : 28)
				: number_of_days[month - 1]);
	}

	short number_of_hours_in_month(short month, short year)
	{
		return (number_of_days_in_month(month, year) * 24);
	}

	int number_of_minutes_in_month(short month, short year)
	{
		return (number_of_hours_in_month(month, year) * 60);
	}

	int number_of_seconds_in_month(short month, short year)
	{
		return (number_of_minutes_in_month(month, year) * 60);
	}

	short	get_day_order_in_week(short day, short month, short year)
	{
		short	a;
		short	y;
		short	m;
		short	d;

		a = (14 - month) / 12;
		y = year - a;
		m = month + 12 * a - 2;
		d = (day + y + y / 4 - y / 100 + y / 400 + (31 * m) / 12) % 7;
		return (d);
	}

	short	get_day_order_in_week(s_date date)
	{
		return (get_day_order_in_week(date.day, date.month, date.year));
	}

	string	day_name(short index)
	{
		string	week_days[7] = {
			"Sunday",
			"Monday",
			"Tuesday",
			"Wednesday",
			"Thursday",
			"Friday",
			"Saturday"
		};

		return (week_days[index]);
	}

	string	day_symbol(short index)
	{
		string	week_days[7] = {
			"Sun", "Mon", "Tue",
			"Wed", "Thu", "Fri",
			"Sat"
		};

		return (week_days[index]);
	}

	string	get_month_symbol(short month)
	{
		string	symbol[12] = {
			"Jan", "Feb", "Mar", "Apr",
			"May", "Jun", "Jul", "Aug",
			"Sep", "Oct", "Nov", "Dec"
		};

		return (symbol[month - 1]);
	}

	void	print_month_calender(short month, short year)
	{
		short	day_idx;
		short	number_of_days;

		print_month_calender_header(get_month_symbol(month));
		day_idx = get_day_order_in_week(1, month, year);
		number_of_days = number_of_days_in_month(month, year);
		for (int i = 0; i < day_idx; i++)
		{
			cout << "     ";
		}
		for (int i = 1; i <= number_of_days; i++)
		{
			// cout << right << setw(3) << i << "  ";
			printf ("%5d", i);
			if (day_idx == 6)
			{
				cout << "\n";
				day_idx = 0;
				continue ;
			}
			day_idx++;
		}
		cout << "\n" << endl;
	}

	void	print_year_calender(short year)
	{
		print_year_calender_header(year);
		for (int m = 1; m <= 12; m++)
		{
			print_month_calender(m, year);
		}
	}

	short	get_day_order_in_year(short day, short month, short year)
	{
		short	number_of_days = 0;

		for (int m = 1; m < month; m++)
		{
			number_of_days += number_of_days_in_month(m, year);
		}
		number_of_days += day;
		return (number_of_days);
	}

	short	get_day_order_in_year(s_date date)
	{
		return (get_day_order_in_year(date.day, date.month, date.year));
	}

	s_date	get_date_from_day_order_in_year(short number_of_days, short year)
	{
		s_date	date;
		short	number_of_days_of_month;

		date.year = year;
		date.month = 1;
		while (true)
		{
			number_of_days_of_month = number_of_days_in_month(date.month, year);
			if (number_of_days > number_of_days_of_month)
			{
				number_of_days -= number_of_days_of_month;
				date.month++;
			}
			else
			{
				date.day = number_of_days;
				break ;
			}
		}
		return (date);
	}

	void	print_date(s_date date)
	{
		cout << date.day << "/" << date.month << "/" << date.year << endl;
	}

	s_date	read_date(string message)
	{
		s_date	date;
		short	number_of_days_of_month;

		cout << message;
		date.year = input::read_number("Enter the year: ");
		date.month = input::read_number_in_range("Enter a month ", 1, 12);
		number_of_days_of_month = number_of_days_in_month(date.month, date.year);
		date.day = input::read_number_in_range("Enter a day ", 1, number_of_days_of_month);
		return (date);
	}

	bool	is_date1_before_date2(s_date date1, s_date date2)
	{
		return (date1.year < date2.year ? true : (date1.year == date2.year ? (date1.month < date2.month ? true : (date1.month == date2.month ? date1.day < date2.day : false)) : false));
	}

	bool	is_date1_equal_to_date2(s_date date1, s_date date2)
	{
		return (date1.year == date2.year ? (date1.month == date2.month ? date1.day == date2.day : false) : false);
	}

	bool	is_last_day_in_month(s_date date)
	{
		return (date.day == number_of_days_in_month(date.month, date.year));
	}

	bool	is_last_month_in_year(s_date date)
	{
		return (date.month == 12);
	}

	s_date	add_one_day_to_date(s_date date)
	{
		if (is_last_day_in_month(date))
		{
			if (is_last_month_in_year(date))
			{
				date.year++;
				date.month = 1;
				date.day = 1;
			}
			else
			{
				date.month++;
				date.day = 1;
			}
		}
		else
		{
			date.day++;
		}
		return (date);
	}

	int	difference_between_two_dates(s_date date1, s_date date2, bool include_last_day = false)
	{
		int	difference = 0;

		if (is_date1_before_date2(date1, date2))
		{
			while (!is_date1_equal_to_date2(date1, date2))
			{
				date1 = add_one_day_to_date(date1);
				difference++;
			}
			return (include_last_day ? ++difference : difference);
		}
		else if (is_date1_equal_to_date2(date1, date2) && include_last_day)
			return (1);
		return (difference);
	}

	s_date	get_system_date()
	{
		time_t	t = time(0);
		tm		*now = localtime(&t);
		s_date	current_date;

		current_date.year = now->tm_year + 1900;
		current_date.month = now->tm_mon + 1;
		current_date.day = now->tm_mday;
		return (current_date);
	}

	short	get_age_as_days(s_date birthday)
	{
		return (difference_between_two_dates(birthday, get_system_date(), true));
	}

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

		if (!tms::is_date1_before_date2(date1, date2))
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

	s_date	add_x_days_to_date(s_date date, int x)
	{
		short	counter = 0;

		while (counter < x)
		{
			date = add_one_day_to_date(date);
			counter++;
		}
		return (date);
	}

	s_date	add_one_week_to_date(s_date date)
	{
		short	counter = 0;

		while (counter < 7)
		{
			date = add_one_day_to_date(date);
			counter++;
		}
		return (date);
	}

	s_date	add_x_weeks_to_date(s_date date, int x)
	{
		short	counter = 0;

		while (counter < x)
		{
			date = add_one_week_to_date(date);
			counter++;
		}
		return (date);
	}

	s_date	add_one_month_to_date(s_date date)
	{
		short	days;

		date.month++;
		if (date.month == 13)
		{
			date.month = 1;
			date.year++;
		}
		days = number_of_days_in_month(date.month, date.year);
		if (date.day > days)
		{
			date.day = days;
		}
		return (date);
	}

	s_date	add_x_months_to_date(s_date date, int x)
	{
		short	counter = 0;

		while (counter < x)
		{
			date = add_one_month_to_date(date);
			counter++;
		}
		return (date);
	}

	s_date	add_one_year_to_date(s_date date)
	{
		date.year++;
		return (date);
	}

	s_date	add_x_years_to_date(s_date date, int x)
	{
		date.year += x;
		return (date);
	}

	s_date	add_one_decade_to_date(s_date date)
	{
		date.year += 10;
		return (date);
	}

	s_date	add_x_decades_to_date(s_date date, int x)
	{
		date.year += x * 10;
		return (date);
	}

	s_date	add_one_century_to_date(s_date date)
	{
		date.year += 100;
		return (date);
	}

	s_date	add_one_millemuim_to_date(s_date date)
	{
		date.year += 1000;
		return (date);
	}

	tms::s_date	decrease_one_day_from_date(tms::s_date date)
	{
		if (date.day == 1)
		{
			if (date.month == 1)
			{
				date.year--;
				date.month = 12;
				date.day = 31;
			}
			else
			{
				date.month--;
				date.day = tms::number_of_days_in_month(date.month, date.year);
			}
		}
		else
		{
			date.day--;
		}
		return (date);
	}

	tms::s_date	decrease_x_days_from_date(tms::s_date date, int x)
	{
		short	counter = 0;

		while (counter < x)
		{
			date = decrease_one_day_from_date(date);
			counter++;
		}
		return (date);
	}

	tms::s_date	decrease_one_week_from_date(tms::s_date date)
	{
		short	counter = 0;

		while (counter < 7)
		{
			date = decrease_one_day_from_date(date);
			counter++;
		}
		return (date);
	}

	tms::s_date	decrease_x_weeks_from_date(tms::s_date date, int x)
	{
		short	counter = 0;

		while (counter < x)
		{
			date = decrease_one_week_from_date(date);
			counter++;
		}
		return (date);
	}

	tms::s_date	decrease_one_month_from_date(tms::s_date date)
	{
		short	days;

		date.month--;
		if (date.month == 0)
		{
			date.month = 12;
			date.year--;
		}
		days = tms::number_of_days_in_month(date.month, date.year);
		if (date.day > days)
		{
			date.day = days;
		}
		return (date);
	}

	tms::s_date	decrease_x_months_from_date(tms::s_date date, int x)
	{
		short	counter = 0;

		while (counter < x)
		{
			date = decrease_one_month_from_date(date);
			counter++;
		}
		return (date);
	}

	tms::s_date	decrease_one_year_from_date(tms::s_date date)
	{
		date.year--;
		return (date);
	}

	tms::s_date	decrease_x_years_from_date(tms::s_date date, int x)
	{
		date.year -= x;
		return (date);
	}

	tms::s_date	decrease_one_decade_from_date(tms::s_date date)
	{
		date.year -= 10;
		return (date);
	}

	tms::s_date	decrease_x_decades_from_date(tms::s_date date, int x)
	{
		date.year -= x * 10;
		return (date);
	}

	tms::s_date	decrease_one_century_from_date(tms::s_date date)
	{
		date.year -= 100;
		return (date);
	}

	tms::s_date	decrease_one_millemuim_from_date(tms::s_date date)
	{
		date.year -= 1000;
		return (date);
	}

	void	print_current_date()
	{
		tms::s_date	date;

		date = tms::get_system_date();
		cout << "Today is " << tms::day_name(get_day_order_in_week(date));
		cout << " ";
		tms::print_date(date);
	}

	bool	is_end_of_week(tms::s_date date)
	{
		return (get_day_order_in_week(date) == 6);
	}

	bool	is_weekend(tms::s_date date)
	{
		return (get_day_order_in_week(date) >= 5);
	}

	bool	is_business_day(tms::s_date date)
	{
		return (!is_weekend(date));
	}

	short	days_until_end_of_week(tms::s_date date)
	{
		return (6 - get_day_order_in_week(date));
	}

	short	days_until_end_of_month(tms::s_date date)
	{
		tms::s_date	end_of_month;

		end_of_month = date;
		end_of_month.day = tms::number_of_days_in_month(date.month, date.year);
		return (tms::difference_between_two_dates(date, end_of_month));
	}

	short	days_until_end_of_year(tms::s_date date)
	{
		tms::s_date	end_of_year;

		end_of_year.year = date.year;
		end_of_year.month = 12;
		end_of_year.day = 31;
		return (tms::difference_between_two_dates(date, end_of_year));
	}

	short	calculate_vacation_days(tms::s_date start, tms::s_date end)
	{
		short	counter = 0;

		while (tms::is_date1_before_date2(start, end))
		{
			if (tms::is_business_day(start))
				counter++;
			start = tms::add_one_day_to_date(start);
		}
		return (counter);
	}

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

	bool	is_date1_after_date2(tms::s_date date1, tms::s_date date2)
	{
		return (tms::is_date1_before_date2(date2, date1));
	}

	e_cmparation	compare_two_dates(tms::s_date date1, tms::s_date date2)
	{
		if (tms::is_date1_equal_to_date2(date1, date2))
			return (e_cmparation::equal);
		else if (tms::is_date1_before_date2(date1, date2))
			return (e_cmparation::before);
		return (e_cmparation::after);
	}

	s_period	read_period(string message)
	{
		s_period	period;

		cout << message;
		period.start = tms::read_date("\nEnter start date\n");
		period.end = tms::read_date("\nEnter end date\n");
		cout << endl;
		return (period);
	}

	bool	does_periods_overlap(s_period period1, s_period period2)
	{
		e_cmparation	condition1;
		e_cmparation	condition2;

		condition1 = tms::compare_two_dates(period1.end, period2.start);
		condition2 = tms::compare_two_dates(period1.start, period2.end);
		if (condition1 == e_cmparation::before || condition2 == e_cmparation::after)
			return (false);
		return (true);
	}

	int	period_length_in_days(tms::s_period period, bool include_last_day = false)
	{
		return (tms::difference_between_two_dates(period.start, period.end, include_last_day));
	}

	bool	is_day_within_period(tms::s_period period, tms::s_date date)
	{
		e_cmparation	condition1;
		e_cmparation	condition2;

		condition1 = tms::compare_two_dates(date, period.end);
		condition2 = tms::compare_two_dates(date, period.start);
		return (!(condition1 == e_cmparation::after || condition2 == e_cmparation::before));
	}
}
