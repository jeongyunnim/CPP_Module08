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

class InvalidContainerTypeException : public std::exception
{
	const char *what(void) const throw()
	{
		return ("Invalid container type.");
	}
};

template <typename T>
typename T::iterator easyfind(T& container, int value)
{
	T::iterator it = container.begin();
	if (*it != static_cast<int>(*it) || *it != reinterpret_cast<int>(*it))
		throw (InvalidContainerTypeException());
	for (it; it != container.end(); it++)
	{
		if (*it == value)
			return (it);
	}
	throw (ValueNotFoundException());
}

#endif