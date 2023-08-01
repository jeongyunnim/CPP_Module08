#include "Span.hpp"

void myGenerate(std::vector<int>::iterator first, std::vector<int>::iterator last, int (*fp)(void))
{
	std::srand(static_cast<unsigned int>(std::time(NULL)));
    for (; first != last; ++first)
        *first = fp();
}

int main()
{
	Span sp = Span(5);

	try
	{
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);

		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
		// sp.addNumber(-1);

	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	{
		const int million = 1000000;
		Span millionSpans(million);
		std::vector<int> temp(million);
		myGenerate(temp.begin(), temp.end(), std::rand);
		millionSpans.fillVector(temp);
		std::cout << millionSpans.shortestSpan() << std::endl;
		std::cout << millionSpans.longestSpan() << std::endl;
	}
	return (0);
}