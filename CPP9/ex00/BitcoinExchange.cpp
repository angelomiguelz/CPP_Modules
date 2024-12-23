#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
	// std::cout << "BitcoinExchange Default constructor called" << std::endl;
	std::ifstream file("data.csv");
	if (!file.is_open())
	{
		throw std::runtime_error("File not found");
	}
	std::string line;
	while (std::getline(file, line))
	{
		std::cout << line << std::endl;
	}
	file.close();
}

BitcoinExchange::~BitcoinExchange()
{
	// std::cout << "BitcoinExchange Destructor called" << std::endl;
}

BitcoinExchange::BitcoinExchange(BitcoinExchange const &o)
{
	// std::cout << "BitcoinExchange Copy constructor called" << std::endl;
	(void)o;
}

BitcoinExchange &BitcoinExchange::operator=(BitcoinExchange const &rhs)
{
	// std::cout << "BitcoinExchange Assignment operator called" << std::endl;
	(void)rhs;
	return *this;
}