#include "Cure.hpp"

Cure::Cure()
{
	std::cout << "Cure:: Default constructor called" << std::endl;
}

Cure::Cure(const Cure& other)
{
	std::cout << "Cure:: Copy constructor called" << std::endl;
}

Cure& Cure::operator=(const Cure& other)
{
	if (this != &other)
	{

	}
	return (*this);
}

Cure::~Cure()
{
	std::cout << "Cure:: Default destructor called" << std::endl;
}
