#ifndef RANDOMLIB_H
# define RANDOMLIB_H
#include <iostream>
#include <cstdlib>
using namespace std;

namespace rnd
{
	int	random_number(int from, int to)
	{
		return (rand() % (to - from + 1) + from);
	}
}
#endif
