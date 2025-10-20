#include "Dog.hpp"

Dog::Dog() : Animal()
{
	type = "Dog";
	std::cout << GREEN << "Dog:: Derived class default constructor called" << RESET << '\n';
}

Dog::Dog(const Dog& other) : Animal(other)
{
	std::cout << "Dog:: Derived class copy constructor called" << '\n';
}

Dog& Dog::operator=(const Dog& other)
{
	if (this != &other)
	{
		Animal::operator=(other);
		std::cout << RED << "Dog:: Derived class copy assignment called" << RESET << '\n';
	}
	return (*this);
}

Dog::~Dog()
{
	std::cout << RED << "Dog:: Derived class default destructor called" << RESET << '\n';
}

void	Dog::makeSound(void) const
{
	std::cout << BLUE << "Wouf" <<  RESET << '\n';
}
