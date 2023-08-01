#include "Span.hpp"

const char* Span::OutOfRangeException::what(void) const throw()
{
	return ("Out of range error.");
}

const char* Span::InsufficientElementException::what(void) const throw()
{
	return ("Element");
}

Span::Span(unsigned int N)
	:	_vector(std::vector<int>(0))
	,	_size(N)
{}

Span::~Span(void)
{}

Span& Span::operator=(const Span& rhs)
{
	_size = rhs._size;
	_vector = std::vector<int>(rhs._vector);
	return (*this);
}

Span::Span(const Span& obj)
	:	_vector(std::vector<int>(obj._vector))
	,	_size(obj._size)
{}

void	Span::addNumber(int num)
{
	if (_vector.size() >= _size)
		throw (OutOfRangeException());
	_vector.push_back(num);
}

void	Span::fillVector(const std::vector<int>& target)
{
	if (_vector.size() + target.size() > _size)
		throw (OutOfRangeException());
	_vector.reserve(_vector.size() + target.size());
	_vector.insert(_vector.end(), target.begin(), target.end());

}

int	Span::shortestSpan(void)
{
	if (_vector.size() < 2)
		throw (InsufficientElementException());
	std::vector<int> temp(_vector);
	std::sort(temp.begin(), temp.end());
	int	gap = temp[1] - temp[0];
	for (size_t i = 1; i < _vector.size(); i++)
	{
		if (gap > temp[i] - temp[i - 1])
			gap = temp[i] - temp[i - 1];
	}
	return (gap);
}

int	Span::longestSpan(void)
{
	if (_vector.size() < 2)
		throw (InsufficientElementException());

	return (*std::max_element(_vector.begin(), _vector.end()) - \
			*std::min_element(_vector.begin(), _vector.end()));
}
