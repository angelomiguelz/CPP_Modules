#ifndef WHATEVER_HPP
#define WHATEVER_HPP

#include <iostream>

template <typename T>
void swap(T &x, T &y) {
	T aux = x;
	x = y;
	y = aux;
}

template <typename T>
T min(T x, T y) {
	if (x < y)
		return x;
	return y;
}

template <typename T>
T max(T x, T y) {
	if (x > y)
		return x;
	return y;
}


#endif
