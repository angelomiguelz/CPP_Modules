#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <algorithm>
#include <vector>

template <typename T>
typename T::iterator easyfind(T &c, int find)
{
	typename T::iterator i = std::find(c.begin(), c.end(), find);
	if (i == c.end())
		throw std::runtime_error("Value not found in container");
	return i;
}
#endif