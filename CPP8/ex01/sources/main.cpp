#include "../includes/Span.hpp"
#include <cstdlib>

// write a good main
// review add various

//  int main()
//  {
//  	std::srand(NULL);
//  	Span sp = Span(5);
//  	for (int i = 0; i < 5; ++i) {
//  		sp.addNumber(std::rand() % 100);
//  	}
//  	std::cout << "Shortest Span: " << sp.shortestSpan() << std::endl;
//  	std::cout << "Longest Span: " << sp.longestSpan() << std::endl;

// 	try {
// 		sp.addNumber(std::rand() % 100);
// 	} catch (std::exception &e) {
// 		std::cerr << e.what() << std::endl;
// 	}

// 	Span sp2 = Span(1);
// 	sp2.addNumber(std::rand() % 100);
// 	try {
// 		std::cout << "Shortest Span: " << sp2.shortestSpan() << std::endl; // This should throw an exception
// 	} catch (const Span::SizeTooSmall &e) {
// 		std::cerr << e.what() << std::endl;
// 	}

// 	return 0;
// }

int main()
{
	Span sp = Span(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
	return 0;
}