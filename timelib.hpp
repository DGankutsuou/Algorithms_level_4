#pragma once
# include <iostream>
# include "inputslib.h"
using namespace std;

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

	short	day_index(short day, short month, short year)
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
			"jan", "feb", "mar", "apr",
			"may", "jun", "jul", "aug",
			"sep", "oct", "nov", "dec"
		};

		return (symbol[month - 1]);
	}

	void	print_month_calender(short month, short year)
	{
		short	day_idx;
		short	number_of_days;

		print_month_calender_header(get_month_symbol(month));
		day_idx = day_index(1, month, year);
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

		cout << message;
		date.year = input::read_number("Enter the year: ");
		date.month = input::read_number_in_range("Enter a month ", 1, 12);
		date.day = input::read_number_in_range("Enter a day ", 1, 31);
		return (date);
	}
}
