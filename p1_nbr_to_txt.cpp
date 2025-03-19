#include <iostream>
#include <limits.h>
#include "inputslib.h"
using namespace std;

string	units[20] = {
	"",
	"one",
	"two",
	"three",
	"four",
	"five",
	"six",
	"seven",
	"eight",
	"nine",
	"ten",
	"eleven",
	"twelve",
	"thirteen",
	"forteen",
	"fifteen",
	"sixteen",
	"seventeen",
	"eightteen",
	"nineteen"
};

string	dozens[16] = {
	"twentey",
	"thiry",
	"fourty",
	"fifty",
	"sixty",
	"seventy",
	"eightty",
	"ninety"
};

string	nbr_to_txt(long number)
{
	if (number <= 0)
		return ("");
	if (number < 20)
		return (units[number] + " ");
	else if (number < 100)
		return (dozens[number / 10 - 2] + " " + nbr_to_txt(number % 10));
	else if (number < 1000)
	{
		if (number >= 200)
		{
			return (
				nbr_to_txt(number / 100) +
				"hundereds " +
				nbr_to_txt(number % 100)
			);
		}
		return (
			"one hundered " +
			nbr_to_txt(number % 100)
		);
	}
	else if (number < 1000000)
	{
		if (number >= 2000)
		{
			return (
				nbr_to_txt(number / 1000) +
				"thousands " +
				nbr_to_txt(number % 1000)
			);
		}
		return (
			"one thousand " +
			nbr_to_txt(number % 1000)
		);
	}
	else if (number < 1000000000)
	{
		if (number >= 2000000)
		{
			return (
				nbr_to_txt(number / 1000000) +
				"millions " +
				nbr_to_txt(number % 1000000)
			);
		}
		return (
			"one million " +
			nbr_to_txt(number % 1000000)
		);
	}
	else if (number < 1000000000000)
	{
		if (number >= 2000000000)
		{
			return (
				nbr_to_txt(number / 1000000000) +
				"billions " +
				nbr_to_txt(number % 1000000000)
			);
		}
		return (
			"one billion " +
			nbr_to_txt(number % 1000000000)
		);
	}
	return ("");
}

int	main(void)
{
	long	number;

	cout << "Enter a number: ";
	cin >> number;
	if (number > INT_MAX)
		number = INT_MAX;
	cout << "The number as a text is: " << nbr_to_txt(number);
	cout << endl;
	return 0;
}
