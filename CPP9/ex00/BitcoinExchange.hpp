#ifndef BITCOIN_EXCHANGE_HPP
#define BITCOIN_EXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <algorithm>
#include <map>

class BitcoinExchange
{
private:
	std::map<std::string, double> rates;

public:
	// OCF
	BitcoinExchange();
	~BitcoinExchange();
	BitcoinExchange(BitcoinExchange const &o);
	BitcoinExchange &operator=(BitcoinExchange const &rhs);
};
#endif