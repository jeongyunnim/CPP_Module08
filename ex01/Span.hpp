#pragma once
#ifndef _SPAN_HPP_
#define _SPAN_HPP_
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <vector>
#include <iostream>

class Span
{

public:

	class OutOfRangeException : public std::exception
	{
		const char *what(void) const throw();
	};
	class InsufficientElementException : public std::exception
	{
		const char *what(void) const throw();
	};
	Span(unsigned int N);
	~Span(void);
	Span& operator=(const Span& rhs);
	Span(const Span& obj);

	void	addNumber(int num);
	int		shortestSpan(void);
	int		longestSpan(void);
	void	fillVector(const std::vector<int>& target);

private:

	Span(void);
	std::vector<int>	_vector;
	size_t				_size;

};

#endif