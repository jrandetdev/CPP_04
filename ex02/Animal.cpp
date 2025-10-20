#include "Animal.hpp"

A_Animal::A_Animal()
{
	std::cout << GREEN << "A_Animal:: Default constructor called" << RESET << '\n';
}

A_Animal::A_Animal(const A_Animal& other) : type(other.type)
{
	std::cout << GREEN << "A_Animal:: Copy constructor called" << RESET << '\n';
}

A_Animal& A_Animal::operator=(const A_Animal& other)
{
	if (this != &other)
	{
		this->type = other.type;
	}
	return (*this);
}

A_Animal::~A_Animal()
{
	std::cout << RED << "A_Animal:: Default destructor called" << RESET << '\n';
}

const std::string& A_Animal::getType(void) const
{
	return (this->type);
}

void	A_Animal::setType(const std::string& type)
{
	this->type = type;
}

