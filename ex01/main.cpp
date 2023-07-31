#include "Span.hpp"
#include <vector>

int main()
{
	static const int vectorSize = 100;
	std::vector<int> intVector(vectorSize);
	int i = 0;
	for (std::vector<int>::iterator it = intVector.begin(); it != intVector.end(); it++)
	{
		*it = i++;
	}

	try
	{
		for (int i = 0;; i++)
		{
			std::vector<int>::iterator pos = easyfind(intVector, i);
			std::cout << *pos << std::endl;
		}
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	

	return (0);
}