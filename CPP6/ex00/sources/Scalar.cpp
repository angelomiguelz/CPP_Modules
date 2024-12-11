#include "../includes/Scalar.hpp"

// OCF :v

Scalar::Scalar() {}

Scalar::~Scalar() {}

Scalar::Scalar(Scalar const &src)
{
	*this = src;
}

Scalar &Scalar::operator=(Scalar const &rhs)
{
	(void)rhs;
	return *this;
}

// rest

void print(std::string c, int i, double d, float f)
{
	std::cout << "char: " << c << std::endl;
	std::cout << "int: " << i << std::endl;
	if (f - static_cast<int>(f) == 0)
	{
		std::cout << "float: " << f << ".0f" << std::endl;
		std::cout << "double: " << d << ".0" << std::endl;
	}
	else
	{
		std::cout << "float: " << f << "f" << std::endl;
		std::cout << "double: " << d << std::endl;
	}
}

bool isPseudo(std::string literal)
{
	if (literal == "-inff" || literal == "+inff" || literal == "-inf" || literal == "+inf" || literal == "nan")
		return (true);
	return (false);
}

void convPseudo(std::string literal)
{
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	if (literal == "-inf" || literal == "+inf" || literal == "nan")
	{
		std::cout << "float: " << literal << "f" << std::endl;
		std::cout << "double: " << literal << std::endl;
	}
	else
	{
		std::cout << "float: " << literal << std::endl;
		literal.erase(literal.length() - 1);
		std::cout << "double: " << literal << std::endl;
	}
}

bool isChar(std::string literal)
{
	if (literal.length() == 1 && !isdigit(literal[0]))
		return true;
	return false;
}

void convChar(std::string literal)
{
	char c = literal[0];
	int i = static_cast<int>(c);
	int d = static_cast<double>(c);
	int f = static_cast<float>(c);

	print(literal, i, d, f);
}

bool isInt(std::string literal)
{
	try
	{
		std::size_t pos;
		std::stoi(literal, &pos);
		return true;
	}
	catch (std::exception &e)
	{
		return false;
	}
}

void convInt(std::string literal)
{
	int i = std::stoi(literal);
	std::string c = "";
	double d = static_cast<double>(i);
	float f = static_cast<float>(i);

	if (isprint(i))
	{
		c = "'";
		c += static_cast<char>(i);
		c += "'";
	}
	else
		c = "Non displayable";
	print(c, i, d, f);
}

bool isDouble(std::string literal)
{
	try
	{
		std::size_t pos;
		std::stod(literal, &pos);
		return true;
	}
	catch (std::exception &e)
	{
		return false;
	}
}

void convDouble(std::string literal)
{
	double d = std::stod(literal);
	std::string c = "";
	int i = static_cast<int>(d);
	float f = static_cast<float>(d);
	if (isprint(i))
	{
		c = "'";
		c += static_cast<char>(i);
		c += "'";
	}
	else
		c = "Non displayable";
	print(c, i, d, f);
}

bool isFloat(std::string literal)
{
	try
	{
		std::size_t pos;
		std::stof(literal, &pos);
		return true;
	}
	catch (std::exception &e)
	{
		return false;
	}
}

void convFloat(std::string literal)
{
	float f = std::stof(literal);
	std::string c = "";
	int i = static_cast<int>(f);
	int d = static_cast<double>(f);
	if (isprint(i))
	{
		c = "'";
		c += static_cast<char>(i);
		c += "'";
	}
	else
		c = "Non displayable";
	print(c, i, d, f);
}

void Scalar::convert(std::string literal)
{
	if (!literal.length())
	{
		std::cout << "invalid input" << std::endl;
		return;
	}
	if (isPseudo(literal))
		convPseudo(literal);
	else if (isChar(literal))
		convChar(literal);
	else if (isInt(literal))
		convInt(literal);
	else if (isDouble(literal))
		convDouble(literal);
	else if (isFloat(literal))
		convFloat(literal);
	else
		std::cout << "invalid input" << std::endl;
}