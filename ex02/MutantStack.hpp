#pragma once
#ifndef _MUTANTSTACK_HPP_
#define _MUTANTSTACK_HPP_
#include <algorithm>
#include <stack>
#include <iostream>

template <typename T>
class MutantStack : public std::stack<T>
{

public:

	MutantStack(void)
		:	std::stack<T>() {}
	MutantStack(const MutantStack& obj)
		:	std::stack<T>(obj.c) {}
	~MutantStack(void) {}
	MutantStack& operator=(const MutantStack& rhs)
	{
		if (this == &rhs)
			return (*this);
		c = rhs.c;
		return (*this);
	}

	typename std::stack<T>::_container<T>::iterator begin(void)
	{
		return (c.begin());
	}
	typename std::stack<T>::_container<T>::iterator end(void)
	{
		return (c.end());
	}
	typename std::stack<T>::_container<T>::const_iterator begin(void)
	{
		return (c.begin());
	}
	typename std::stack<T>::_container<T>::const_iterator end(void)
	{
		return (c.end());
	}
	typename std::stack<T>::_container<T>::reverse_iterator rbegin(void)
	{
		return (c.rbegin());
	}
	typename std::stack<T>::_container<T>::reverse_iterator rend(void)
	{
		return (c.rend());
	}
	typename std::stack<T>::_container<T>::const_reverse_iterator rbegin(void)
	{
		return (c.rbegin());
	}
	typename std::stack<T>::_container<T>::const_reverse_iterator rend(void)
	{
		return (c.rend());
	}

};

#endif