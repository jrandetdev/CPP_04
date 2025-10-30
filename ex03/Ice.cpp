#include "Ice.hpp"

Ice::Ice() : AMateria()
{
	this->type = "ice";
	//std::cout << "Ice:: Default constructor called" << std::endl;
}

// Start by creating the base class of Ice (AMateria)
Ice::Ice(const Ice& other) : AMateria("ice")
{
	(void)other;
//	std::cout << "Ice:: Copy constructor called" << std::endl;
}

Ice& Ice::operator=(const Ice& other)
{
	if (this != &other) // Protect against invalid self-assignment 
	{
		AMateria::operator=(other);
	}
	return (*this);
}

Ice::~Ice()
{
	//std::cout << "Ice:: Default destructor called" << std::endl;
}

AMateria* Ice::clone() const
{
	return new Ice(*this); // copy constructor using the instance obtained through dereference
}

void Ice::use(ICharacter& target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
