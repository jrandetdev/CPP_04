#include "Cat.hpp"

Cat::Cat() : Animal()
{
	type = "Cat";
	cat_brain = new Brain();
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
	return (*this);
}

Cat::~Cat()
{
	delete cat_brain;
	std::cout << "Cat:: Derived class default destructor called" << '\n';
}

void	Cat::makeSound(void) const
{
	std::cout << GREEN << "Miaou" << RESET << '\n';
}
