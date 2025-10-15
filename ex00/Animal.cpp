#include "Animal.hpp"

Animal::Animal()
{
	std::cout << "Animal:: Default constructor called" << '\n';
}

Animal::Animal(const Animal& other) : type(other.type)
{
	std::cout << "Animal:: Copy constructor called" << '\n';
}

Animal& Animal::operator=(const Animal& other)
{
	if (this != &other)
	{
		this->type = other.type;
	}
}

Animal::~Animal()
{
	std::cout << "Animal:: Default destructor called" << '\n';
}
