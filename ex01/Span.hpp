#pragma once
#ifndef _SPAN_HPP_
#define _SPAN_HPP_
#include <algorithm>
#include <vector>

class Span
{
public:
	Span(unsigned int N);
	~Span(void);
	Span& operator=(const Span& rhs);
	Span(const Span& obj);

	void	addNumber(int num);
	int		shortSpan(void);
	int		longestSpan(void);
	void	fillVector(size_t range, std::vector<int>::iterator begin, std::vector<int>::iterator end);
	
private:

	Span(void);
	std::vector<int>	_vector;

};

#endif