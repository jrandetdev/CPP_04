#include "Cure.hpp"

/**
 * @brief Cure default constructor is derived from the AMateria class.
 * 
 * It needs to construct the AMateria base first, so it has access to the 
 * AMateria class attributed
 */
Cure::Cure() : AMateria()
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

void	Cure::use(ICharacter& target)
{
	std::cout << "* heals " << target.name << "'s wounds *" << std::endl;
}