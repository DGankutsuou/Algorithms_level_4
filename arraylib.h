#ifndef ARRAYLIB_H
# define ARRAYLIB_H
#include "randomlib.h"
#include <iostream>
#include <cstdlib>
using namespace std;

namespace arr
{
	int	calculat_sum_of_array(int array[100], int array_length)
	{
		int	sum;

		sum = 0;
		for(int counter = 0; counter < array_length; counter++)
			sum += array[counter];
		return (sum);
	}
	void print_array(int array[100], int array_length)
	{
		cout << "Array elements: ";
		for(int counter = 0; counter < array_length; counter++)
			cout << array[counter] << " ";
		cout << endl;
	}
}
#endif
