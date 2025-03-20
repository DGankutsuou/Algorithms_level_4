#pragma once
# include <iostream>
using namespace std;

void	print_month_calender_header(string month_symbol)
{
	cout << "\n  _______________";
	printf ("%s", month_symbol.c_str());
	cout << "_______________\n";
	cout << "  sun  mon  tue  wed  thu  fri  sat" << endl;
}

namespace tms
{
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

	short	day_idx(short day, short month, short year)
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
		day_idx = tms::day_idx(1, month, year);
		number_of_days = tms::number_of_days_in_month(month, year);
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
}
