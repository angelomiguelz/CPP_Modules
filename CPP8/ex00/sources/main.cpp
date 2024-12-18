#include "../includes/easyfind.hpp"
#include <list>
#include <array>
#include <forward_list>

int main(int ac, char **av)
{
	// data - limits should be > 0
	int find = 7;
	int vectorLimit = 3;
	int dequeLimit = 5;
	int listLimit = 8;
	int forwardListLimit = 1;
	// array
	std::array<int, 10> a = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	if (ac == 2)
		find = std::atoi(av[1]);
	std::cout << "Finding: " << find << " > in array : ";
	try
	{
		std::array<int, 9>::iterator it = easyfind(a, find);
		(void)it;
		std::cout << "SUCCESS" << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	// vector
	std::vector<int> v;
	for (int i = 0; i < vectorLimit; i++)
		v.push_back(i);
	std::cout << "Finding: " << find << " > in vector : ";
	try
	{
		std::vector<int>::iterator it = easyfind(v, find);
		(void)it;
		std::cout << "SUCCESS" << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	// deque
	std::deque<int> d;
	for (int i = 0; i <= dequeLimit; i++)
		d.push_back(i);
	std::cout << "Finding: " << find << " > in deque : ";
	try
	{
		std::deque<int>::iterator it = easyfind(d, find);
		(void)it;
		std::cout << "SUCCESS" << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	// list
	std::list<int> l;
	for (int i = 0; i <= listLimit; i++)
		l.push_back(i);
	std::cout << "Finding: " << find << " > in list : ";
	try
	{
		std::list<int>::iterator it = easyfind(l, find);
		(void)it;
		std::cout << "SUCCESS" << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	// forwardlist
	std::forward_list<int> f;
	for (int i = 0; i <= forwardListLimit; i++)
		f.push_front(i);
	std::cout << "Finding: " << find << " > in forward_list : ";
	try
	{
		std::forward_list<int>::iterator it = easyfind(f, find);
		(void)it;
		std::cout << "SUCCESS" << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	return 0;
}
