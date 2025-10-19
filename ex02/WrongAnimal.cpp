#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
	std::cout << "WrongAnimal:: Default constructor called" << '\n';
}

WrongAnimal::WrongAnimal(const WrongAnimal& other) : type(other.type)
{
	std::cout << "WrongAnimal:: Copy constructor called" << '\n';
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& other)
{
	if (this != &other)
	{
		this->type = other.type;
	}
	return (*this);
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal:: Default destructor called" << '\n';
}

void	WrongAnimal::makeSound(void) const
{
	std::cout << "WrongAnimal generic sound" << '\n';
}

const std::string& WrongAnimal::getType(void) const
{
	return (this->type);
}

void	WrongAnimal::setType(const std::string& type)
{
	this->type = type;
}

