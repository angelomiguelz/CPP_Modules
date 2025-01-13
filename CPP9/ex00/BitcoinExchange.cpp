#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
	// std::cout << "BitcoinExchange Default constructor called" << std::endl;
	std::ifstream file("data.csv");
	if (!file.is_open())
		throw std::runtime_error("data.csv: File not found");
	std::string line;
	size_t commaPos;
	// verify
	std::getline(file, line); // skips first line
	while (std::getline(file, line))
	{
		commaPos = line.find(',');
		if (commaPos == std::string::npos)
		{
			std::cout << "Error: bad input => " << line << "\n";
			continue;
		}
		std::string date = line.substr(0, commaPos);
		std::string value = line.substr(commaPos + 1, line.length());

		double rate;
		std::istringstream valueStream(value);
		if (!(valueStream >> rate))
		{
			std::cerr << "Error: bad input => " << value << '\n';
			continue;
		}
		this->rates[date] = rate;
	}
	file.close();
}

std::string trim(std::string const &str)
{
	size_t first = str.find_first_not_of(" \t\n\r");
	if (std::string::npos == first)
	{
		return str;
	}
	size_t last = str.find_last_not_of(" \t\n\r");
	return str.substr(first, (last - first + 1));
}

bool BitcoinExchange::validDate(std::string date)
{
	int year, month, day;
	char sep;
	std::istringstream stream(date);
	if (!(stream >> year >> sep >> month >> sep >> day))
	{
		std::cerr << "Error: bad input => " << date << '\n';
		return false;
	}
	if (year < 0 || month < 1 || month > 12 || day < 1 || day > 31)
		return false;
	if (day > 30 && (month == 4 || month == 6 || month == 9 || month == 11))
		return false;
	if (month == 2)
	{
		bool isLeap = (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0));
		if ((isLeap && day > 29) || (!isLeap && day > 28))
			return false;
	}
	return true;
}

bool BitcoinExchange::validValue(std::string valueStr)
{
	float value;
	std::istringstream stream(valueStr);
	if (!(stream >> value))
	{
		std::cerr << "Error: bad input => " << valueStr << '\n';
		return false;
	}
	if (value < 0)
	{
		std::cerr << "Error: not a positive number.\n";
		return false;
	}
	if (value > 1000)
	{
		std::cerr << "Error: too large a number.\n";
		return false;
	}
	return true;
}

void BitcoinExchange::exchange(std::string fileName)
{
	std::ifstream file(fileName.c_str());
	if (!file.is_open())
		throw std::runtime_error(fileName + ": File not found");
	std::string line;
	std::getline(file, line); // skips first line
	size_t pipe;
	std::string date;
	std::string value;
	while (std::getline(file, line))
	{
		if ((pipe = line.find("|")) && pipe == std::string::npos)
		{
			std::cout << "Error: bad input => " << line << "\n";
			continue;
		}
		date = trim(line.substr(0, pipe));
		value = trim(line.substr(pipe + 1, line.length()));
		if (!validDate(date) || !validValue(value))
			continue;
		std::map<std::string, double>::iterator it = rates.lower_bound(date);
		if (rates.empty() || it == rates.end())
		{
			std::cout << "Error: cant find date => " << line << "\n";
			continue;
		}
		double exchangeRate = it->second;
		std::istringstream stream(value);
		double value;
		if (!(stream >> value))
			if (pipe == std::string::npos)
			{
				std::cout << "Error: bad input in value => " << line << "\n";
				continue;
			}
		std::cout << date << " => " << value << " = " << value * exchangeRate << '\n';
	}
}

BitcoinExchange::~BitcoinExchange()
{
	// std::cout << "BitcoinExchange Destructor called" << std::endl;
}

BitcoinExchange::BitcoinExchange(BitcoinExchange const &o)
{
	// std::cout << "BitcoinExchange Copy constructor called" << std::endl;
	*this = o;
}

BitcoinExchange &BitcoinExchange::operator=(BitcoinExchange const &rhs)
{
	// std::cout << "BitcoinExchange Assignment operator called" << std::endl;
	(void)rhs;
	return *this;
}