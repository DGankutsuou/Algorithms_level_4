#include "timelib.hpp"

string	date_format(string date, string format)
{
	vector <string>	date_splited;

	date_splited = ft::spliter(date, "/");
	ft::ft_str_replace(format, "dd", date_splited[0]);
	ft::ft_str_replace(format, "mm", date_splited[1]);
	ft::ft_str_replace(format, "yyyy", date_splited[2]);
	return (format);
}

int	main(void)
{
	string		date_string;

	date_string = input::read_string("Enter a date (dd/mm/yyyy): ");
	cout << "Date format 1: " << date_format(date_string, "dd-mm-yyyy\n");
	cout << "Date format 2: " << date_format(date_string, "yyyy/mm/dd\n");
	cout << "Date format 3: " << date_format(date_string, "yyyy-mm-dd\n");
	cout << "Date format 4: " << date_format(date_string, "day:dd, month:mm, year:yyyy\n");
	return (0);
}
