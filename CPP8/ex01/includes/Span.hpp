#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <algorithm>
#include <vector>

class Span
{
private:
	std::vector<int> v;
	unsigned int limit;

public:
	class SpanIsFull : public std::exception
	{
	public:
		const char *what() const throw();
	};

	class SizeTooSmall : public std::exception
	{
	public:
		const char *what() const throw();
	};
	Span();
	Span(unsigned int limit);
	~Span();
	Span(Span const &other);
	Span &operator=(Span const &rhs);
	void addNumber(int value);
	void addNumbers(std::vector<int>::iterator begin, std::vector<int>::iterator end);
	unsigned int shortestSpan();
	unsigned int longestSpan();
};

#endif