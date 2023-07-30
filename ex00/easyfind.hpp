#pragma once
#ifndef _EASYFIND_HPP_
#define _EASYFIND_HPP_

#include <algorithm>
#include <iostream>
#include <exception>

class ValueNotFoundException : public std::exception
{
	const char *what(void) const throw()
	{
		return ("Value not found.");
	}
};

template <typename T>
typename T::iterator easyfind(T& container, int value)
{
	typename T::iterator it = std::find(container.begin(), container.end(), value);
	if (it == container.end())
		throw (ValueNotFoundException());
	return (it);
}

#endif