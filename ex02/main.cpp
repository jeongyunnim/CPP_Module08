#include "MutantStack.hpp"

template <typename T>
void printStack(MutantStack<T>& mstack)
{
	std::stack<T> s(mstack);

	std::cout << Colors::Blue << "\n[print stack]" << Colors::Reset << std::endl;
	while (s.empty() == 0)
	{
		std::cout << "|" << std::left << std::setw(3) << s.top() << '|' << std::endl;
		s.pop();
	}
}

template <typename T>
void printList(MutantStack<T>& mstack)
{
	typename MutantStack<T>::iterator it = mstack.begin();
	typename MutantStack<T>::iterator ite = mstack.end();
	std::cout << Colors::Blue << "\n[print list]" << Colors::Reset << std::endl;
	++it;
	--it;
	while (it != ite)
	{
		std::cout << '|' << std::left << std::setw(3) << *it;
		if (it + 1 == ite)
			std::cout << "|" << std::endl;
		else
			std::cout << "| -> ";
		++it;
	}
}

void	subjectRequired(void)
{
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << Colors::Magenta << "[present stack top]" << Colors::Reset << std::endl;
	std::cout << mstack.top() << std::endl;
	mstack.pop();
	std::cout << Colors::Magenta << "\n[present stack size]" << Colors::Reset << std::endl;
	std::cout << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);
	printList(mstack);
	printStack(mstack);
}

int main()
{
	subjectRequired();
	MutantStack<std::string> stringStack;
	std::string	temp = "alphabet: ";

	for (int i = 0; i < 26; i++)
	{
		stringStack.push(temp + static_cast<char>('a' + i));
	}
	{
		std::cout << Colors::Magenta << "\n[Mutant stack iterator]" << Colors::Reset << std::endl;
		printList(stringStack);
		printStack(stringStack);
	}
	{
		std::cout << Colors::Magenta << "\n[Mutant stack const iterator]" << Colors::Reset << std::endl;
		MutantStack<std::string>::const_iterator cit = stringStack.cbegin();
		MutantStack<std::string>::const_iterator cite = stringStack.cend();
		std::cout << Colors::Blue << "[print list]" << Colors::Reset << std::endl;
		while (cit != cite)
		{
			std::cout << '|' << std::left << std::setw(10) << *cit;
			if (cit + 1 == cite)
				std::cout << "|" << std::endl;
			else
				std::cout << "| -> ";
			++cit;
		}
	}
	{
		std::cout << Colors::Magenta << "[Mutant stack reverse iterator]" << Colors::Reset << std::endl;
		MutantStack<std::string>::reverse_iterator rit = stringStack.rbegin();
		MutantStack<std::string>::reverse_iterator rite = stringStack.rend();
		std::cout << Colors::Blue << "[print list]" << Colors::Reset << std::endl;
		while (rit != rite)
		{
			std::cout << '|' << std::left << std::setw(10) << *rit;
			if (rit + 1 == rite)
				std::cout << "|" << std::endl;
			else
				std::cout << "| -> ";
			++rit;
		}
	}
	{
		std::cout << Colors::Magenta << "[Mutant stack const reverse iterator]" << Colors::Reset << std::endl;
		MutantStack<std::string>::const_reverse_iterator crit = stringStack.crbegin();
		MutantStack<std::string>::const_reverse_iterator crite = stringStack.crend();
		while (crit != crite)
		{
			std::cout << '|' << std::left << std::setw(10) << *crit;
			if (crit + 1 == crite)
				std::cout << "|" << std::endl;
			else
				std::cout << "| -> ";
			++crit;
		}
	}
	return 0;
}