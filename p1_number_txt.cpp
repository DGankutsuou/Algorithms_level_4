#include <iostream>
#include <limits.h>
#include "inputslib.h"
using namespace std;

string	units[20] = {
	"zero",
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

// void	handle_after_99(string text, int number)
// {

// }

void	convert_number_into_text(long number)
{
	if (number <= 0)
		return ;
	if (number < 20)
	{
		cout << units[number] << " ";
		return ;
	}
	else if (number < 100)
	{
		cout << dozens[number / 10 - 2] << " ";
		number %= 10;
	}
	else if (number < 1000)
	{
		convert_number_into_text(number / 100);
		cout << "hundered";
		if (number >= 200)
			cout << "s";
		cout << " ";
		number %= 100;
	}
	else if (number < 1000000)
	{
		convert_number_into_text(number / 1000);
		cout << "thousand";
		if (number >= 2000)
			cout << "s";
		cout << " ";
		number %= 1000;
	}
	else if (number < 1000000000)
	{
		convert_number_into_text(number / 1000000);
		cout << "million";
		if (number >= 2000000)
			cout << "s";
		cout << " ";
		number %= 1000000;
	}
	else if (number < 1000000000000)
	{
		convert_number_into_text(number / 1000000000);
		cout << "billion";
		if (number >= 2000000000)
			cout << "s";
		cout << " ";
		number %= 1000000000;
	}
	convert_number_into_text(number);
}

int	main(void)
{
	long	number;

	cout << "Enter a number: ";
	cin >> number;
	if (number > INT_MAX)
		number = INT_MAX;
	cout << "The number as a text is: ";
	convert_number_into_text(number);
	cout << endl;
	return 0;
}
