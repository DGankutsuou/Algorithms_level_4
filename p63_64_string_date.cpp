#include "timelib.hpp"

string	date_to_string1(tms::s_date date)
{
	string	date_string = "";

	date_string += to_string(date.day) + "/" + to_string(date.month) + "/" + to_string(date.year);
	return (date_string);
}

tms::s_date	string_to_date1(string date)
{
	tms::s_date		date_struct;
	vector <string>	date_splited;

	date_splited = ft::spliter(date, "/");
	date_struct.day = stoi(date_splited[0]);
	date_struct.month = stoi(date_splited[1]);
	date_struct.year = stoi(date_splited[2]);
	return (date_struct);
}

void	print_date_struct1(tms::s_date date)
{
	cout << "day: " << date.day << endl;
	cout << "month: " << date.month << endl;
	cout << "year: " << date.year << endl;
}

int	main(void)
{
	tms::s_date	date;
	string		date_string;

	date_string = input::read_string("Enter a date (dd/mm/yyyy): ");
	date = string_to_date1(date_string);
	cout << "\nDate as struct:\n";
	print_date_struct1(date);
	cout << "\nYou entered: " << date_to_string1(date) << endl;
	cout << endl;
	return (0);
}
