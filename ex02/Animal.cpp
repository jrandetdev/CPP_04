#include "Animal.hpp"

Animal::Animal()
{
	std::cout << GREEN << "Animal:: Default constructor called" << RESET << '\n';
}

Animal::Animal(const Animal& other) : type(other.type)
{
	std::cout << GREEN << "Animal:: Copy constructor called" << RESET << '\n';
}

Animal& Animal::operator=(const Animal& other)
{
	if (this != &other)
	{
		this->type = other.type;
	}
	return (*this);
}

Animal::~Animal()
{
	std::cout << RED << "Animal:: Default destructor called" << RESET << '\n';
}

const std::string& Animal::getType(void) const
{
	return (this->type);
}

void	Animal::setType(const std::string& type)
{
	this->type = type;
}

