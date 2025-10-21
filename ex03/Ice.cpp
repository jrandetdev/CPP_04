#include "Ice.hpp"

Ice::Ice()
{
	std::cout << "Ice:: Default constructor called" << std::endl;
}

Ice::Ice(const Ice& other)
{
	std::cout << "Ice:: Copy constructor called" << std::endl;
}

Ice& Ice::operator=(const Ice& other)
{
	if (this != &other)
	{

	}
	return (*this);
}

Ice::~Ice()
{
	std::cout << "Ice:: Default destructor called" << std::endl;
}
