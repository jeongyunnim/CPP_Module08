#pragma once
#ifndef _MUTANTSTACK_HPP_
#define _MUTANTSTACK_HPP_
#include <algorithm>
#include <stack>
#include <iostream>
#include <iomanip>
#include "../Colors.hpp"

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
		std::stack<T>::c = rhs.c;
		return (*this);
	}

	typedef typename std::stack<T>::container_type::iterator iterator;
	iterator begin(void)
	{
		return (std::stack<T>::c.begin());
	}
	iterator end(void)
	{
		return (std::stack<T>::c.end());
	}
	
	typedef typename std::stack<T>::container_type::const_iterator const_iterator;
	const_iterator cbegin(void) const
	{
		return (std::stack<T>::c.begin());
	}
	const_iterator cend(void) const
	{
		return (std::stack<T>::c.end());
	}
	
	typedef typename std::stack<T>::container_type::reverse_iterator reverse_iterator;
	reverse_iterator rbegin(void)
	{
		return (std::stack<T>::c.rbegin());
	}
	reverse_iterator rend(void)
	{
		return (std::stack<T>::c.rend());
	}
	
	typedef typename std::stack<T>::container_type::const_reverse_iterator const_reverse_iterator;
	const_reverse_iterator crbegin(void) const
	{
		return (std::stack<T>::c.rbegin());
	}
	const_reverse_iterator crend(void) const
	{
		return (std::stack<T>::c.rend());
	}
};

#endif