#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base*	generate(void)
{
	int i = std::rand() % 3;
	switch (i)
	{
	case 0:
		return new A();

	case 1:
		return new B();
	case 2:
		return new C();
	}
	return NULL;
}

void	identify(Base* p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "A" << '\n';
	else if (dynamic_cast<B*>(p))
		std::cout << "B" << '\n';
	else if (dynamic_cast<C*>(p))
		std::cout << "C" << '\n';
}

void	identify(Base& p)
{
	try
	{
		dynamic_cast<A&>(p);
		std::cout << "A" << '\n';
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		dynamic_cast<B&>(p);
		std::cout << "B" << '\n';
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		dynamic_cast<C&>(p);
		std::cout << "C" << '\n';
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
}

int main()
{
	srand(time(NULL));
	Base* ptr = generate();
	identify(*ptr);
	return 0;
}