#include "Ice.hpp"

Ice::Ice() : AMateria()
{
	std::cout << "Ice:: Default constructor called" << std::endl;
}

Ice::Ice(const Ice& other)
{
	std::cout << "Ice:: Copy constructor called" << std::endl;
}

Ice& Ice::operator=(const Ice& other)
{
	{
		this->type = other.type;
	}
	return (*this);
}

/**
 * @brief
 * 
 * @return pointer on Amateria 
 * @
 */
AMateria* Ice::clone() const
{
	
}

void Ice::use(ICharacter& target)
{
	std::cout << "* shoots an ice bolt at " << target.name << " *" << std::endl;
}

Ice::~Ice()
{
	std::cout << "Ice:: Default destructor called" << std::endl;
}
