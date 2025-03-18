#pragma once
#include <iostream>
using namespace std;

int my_str_is_numeric(string str)
{
	int idx;

	idx = 0;
	if (str[idx] == '-' || str[idx] == '+')
		idx++;
	while (str[idx] != '\0')
	{
		if (str[idx] >= '0' && str[idx] <= '9')
			idx++;
		else
			return (0);
	}
	return (1);
}

int ft_atoi(string str)
{
	int nbr;
	int op;
	int i;

	nbr = 0;
	op = 1;
	i = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			op *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
		nbr = (nbr * 10) + str[i++] - '0';
	return (nbr * op);
}

namespace input
{
	int read_number(string message)
	{
		string number;

		number = "";
		cout << message;
		cin >> number;
		while (!my_str_is_numeric(number))
		{
			cout << "You did not enter a number, please enter a number: ";
			cin >> number;
		}
		return (ft_atoi(number));
	}

	int read_positive_number(string message)
	{
		string number;

		number = "";
		do
		{
			cout << message;
			cin >> number;
			while (!my_str_is_numeric(number))
			{
				cout << "you did not enter a number, please enter a number: ";
				cin >> number;
			}
		} while (ft_atoi(number) <= 0);
		return (ft_atoi(number));
	}

	int read_number_in_range(int from, int to)
	{
		int number;

		do
		{
			cout << "Enter a number from " << from << " to " << to << ": ";
			cin >> number;
		} while (number < from || number > to);

		return (number);
	}

	void read_array(int array[100], int &array_length)
	{
		array_length = read_positive_number("Enter the number of the array length: ");
		for (int counter = 0; counter < array_length; counter++)
		{
			cout << "Element[" << counter + 1 << "] = ";
			cin >> array[counter];
		}
	}

	string	read_string(string message)
	{
		string	str;

		cout << message;
		getline(cin, str);
		return (str);
	}
}
