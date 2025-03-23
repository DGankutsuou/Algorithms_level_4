#include "timelib.hpp"

string	date_format1(string date, string format = "dd/mm/yyyy")
{
	vector <string>	date_splited;

	date_splited = ft::spliter(date, "/");
	format = ft::ft_str_replace(format, "dd", date_splited[0]);
	format = ft::ft_str_replace(format, "mm", date_splited[1]);
	format = ft::ft_str_replace(format, "yyyy", date_splited[2]);
	return (format);
}


string	date_format2(tms::s_date date, string format = "dd/mm/yyyy")
{
	format = ft::ft_str_replace(format, "dd", to_string(date.day));
	format = ft::ft_str_replace(format, "mm", to_string(date.month));
	format = ft::ft_str_replace(format, "yyyy", to_string(date.year));
	return (format);
}

int	main(void)
{
	string		date_string;
	tms::s_date	date;

	date_string = input::read_string("Enter a date (dd/mm/yyyy): ");
	date = tms::string_to_date(date_string);
	cout << "Date format 0: " << date_format2(date) << endl;
	cout << "Date format 1: " << date_format2(date, "dd-mm-yyyy") << endl;
	cout << "Date format 2: " << date_format2(date, "yyyy/mm/dd") << endl;
	cout << "Date format 3: " << date_format2(date, "yyyy-mm-dd") << endl;
	cout << "Date format 4: " << date_format2(date, "day:dd , month:mm, year:yyyy") << endl;
	return (0);
}
