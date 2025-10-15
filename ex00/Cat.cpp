#include "Cat.hpp"

Cat::Cat() : Animal()
{
	type = "Cat";
	std::cout << "Cat:: Derived class default constructor called" << '\n';
}

Cat::Cat(const Cat& other) : Animal(other)
{
	std::cout << "Cat:: Derived class copy constructor called" << '\n';
}

Cat& Cat::operator=(const Cat& other)
{
	if (this != &other)
	{
		Animal::operator=(other);
		std::cout << "Cat:: Derived class copy assignment called" << '\n';
	}
}

Cat::~Cat()
{
	std::cout << "Cat:: Derived class default destructor called" << '\n';
}
