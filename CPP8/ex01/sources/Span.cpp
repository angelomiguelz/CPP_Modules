#include "../includes/Span.hpp"

// OCF

Span::Span() : limit(0)
{
	// std::cout << "Span default constructor called" << std::endl;
}
Span::Span(unsigned int limit) : limit(limit)
{
	// std::cout << "Span parameter constructor called" << std::endl;
}

Span::~Span()
{
	// std::cout << "Span destructor called" << std::endl;
}

Span::Span(Span const &other) : limit(other.limit), v(other.v)
{
	// std::cout << "Span copy constructor called" << std::endl;
}
Span &Span::operator=(Span const &rhs)
{
	// std::cout << "Span assignation operator called" << std::endl;
	if (this != &rhs)
	{
		limit = rhs.limit;
		v = rhs.v;
	}
	return *this;
}

// exceptions

const char *Span::SpanIsFull::what() const throw()
{
	return "Container is full";
}

const char *Span::SizeTooSmall::what() const throw()
{
	return "Size is too small";
}

// methods

void Span::addNumber(int value)
{
	if (v.size() > limit)
		throw SpanIsFull();
	v.push_back(value);
}

void Span::addNumbers(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{

	if (this->v.size() + std::distance(begin, end) <= this->limit)
		this->v.insert(this->v.end(), begin, end);
	else
		throw SpanIsFull();
}

unsigned int Span::shortestSpan()
{
	if (v.size() < 2 || limit < 2)
		throw SizeTooSmall();
	std::sort(v.begin(), v.end());
	unsigned int min = UINT_MAX;
	for (unsigned int i = 1; i < v.size(); i++)
	{
		unsigned int diff = v[i] - v[i - 1];
		if (diff < min)
			min = diff;
	}
	return min;
}

unsigned int Span::longestSpan()
{
	if (v.size() < 2 || limit < 2)
		throw SizeTooSmall();
	std::sort(v.begin(), v.end());
	return v[v.size() - 1] - v[0];
}