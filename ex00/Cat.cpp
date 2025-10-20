#include "Cat.hpp"

Cat::Cat() : Animal()
{
	type = "Cat";
	std::cout << GREEN << "Cat:: Derived class default constructor called" << RESET << '\n';
}

Cat::Cat(const Cat& other) : Animal(other)
{
	std::cout << GREEN << "Cat:: Derived class copy constructor called" << RESET << '\n';
}

Cat& Cat::operator=(const Cat& other)
{
	if (this != &other)
	{
		Animal::operator=(other);
		std::cout << "Cat:: Derived class copy assignment called" << '\n';
	}
	return (*this);
}

Cat::~Cat()
{
	std::cout << RED << "Cat:: Derived class default destructor called" << RESET << '\n';
}

void	Cat::makeSound(void) const
{
	std::cout << GREEN << "Miaou" << RESET << '\n';
}
