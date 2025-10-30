#include "AMateria.hpp"

AMateria::AMateria()
{
	// Zero initialisation 
	type = "";
	//std::cout << GREEN << "AMateria:: Default constructor called" << RESET << std::endl;
}

AMateria::AMateria(std::string const & type)
{
	this->type = type;
	//std::cout << GREEN << "AMateria:: constructor called with type" << RESET << '\n';
}

AMateria::AMateria(const AMateria& other) : type(other.type)
{
	//std::cout << GREEN << "AMateria:: Copy constructor called." << RESET << '\n';
}

AMateria& AMateria::operator=(const AMateria& other)
{
	(void)other;
	return (*this);
}

void	AMateria::use(ICharacter& target)
{
	std::cout << "Amateria:: base spell used, no power on " << target.getName()
			<< " ..." << std::endl;
}

std::string const & AMateria::getType() const
{
	return (this->type);
}

AMateria::~AMateria()
{
	//std::cout << RED << "AMateria:: default destructor called" << RESET << '\n';
}
