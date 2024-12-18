#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <algorithm>
#include <vector>

// exception class
class ValueNotFound : public std::exception
{
public:
	const char *what() const throw();
};

template <typename T>
typename T::iterator easyfind(T &c, int find)
{
	typename T::iterator i = std::find(c.begin(), c.end(), find);
	if (i == c.end())
		throw ValueNotFound();
	return i;
}
#endif