#include "AMateria.hpp"

AMateria::AMateria()
{
	// Zero initialisation 
	type = "";
	std::cout << GREEN << "AMateria:: Default constructor called" << RESET << std::endl;
}

AMateria::AMateria(std::string const & type)
{
	this->type = type;
	std::cout << GREEN << "AMateria:: constructor called with type" << RESET << '\n';
}

AMateria::AMateria(const AMateria& other)
{
	this->type = other.type;
	std::cout << GREEN << "AMateria:: Copy constructor called with type" << RESET << '\n';
}

AMateria& AMateria::operator=(const AMateria& other)
{
	if (this != &other)
	{
		//it says that copying the type does not make sense
	}
	return (*this);
}

void	AMateria::use(ICharacter& target)
{
	(void)target;
	std::cout << "Amateria:: base spell used, no power..." << std::endl;
}

AMateria::~AMateria()
{
	
	std::cout << RED << "AMateria:: default destructor called" << RESET << '\n';
}
