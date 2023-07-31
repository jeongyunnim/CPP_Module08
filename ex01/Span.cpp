#include "Span.hpp"

Span::Span(unsigned int N)
	:	_vector(std::vector<int>(N))
{}

Span::~Span(void)
{}

Span& Span::operator=(const Span& rhs)
{
	_vector = std::vector<int>(rhs._vector.capacity());
	for (int i = 0; i < rhs._vector.size(); i++)
		_vector[i] = rhs._vector[i];
}

Span::Span(const Span& obj)
	:	_vector(std::vector<int>(obj._vector.capacity()))
{}


void	Span::addNumber(int num)
{
	if (_vector.capacity() == _vector.size()) // size인지 size - 1인지 보아야 함.
		throw (std::exception()); // exception 정의하기.
	_vector.push_back(num);
}

void	Span::fillVector(size_t range, std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
	if (_vector.capacity() == _vector.size() + range)
		throw (std::exception()); // exception 정의하기.
	_vector.insert(_vector.begin() + _vector.size(), begin, end);
}

int	Span::shortSpan(void)
{
	if (_vector.size() < 2)
		throw (std::exception());
	std::vector temp(_vector);
	int	gap = temp[1] - temp[0];
	std::sort(temp.begin(), temp.end());
	for (int i = 1; i < _vector.size(); i++)
	{
		if (gap > temp[i] - temp[i - 1])
			gap = temp[i] - temp[i - 1];
	}
}

int	Span::longestSpan(void)
{
	if (_vector.size() < 2)
		throw (std::exception()); // exception 정의하기.
	return (std::max_element(_vector.begin(), _vector.end()) - std::min_element(_vector.begin(), _vector.end()));
}
