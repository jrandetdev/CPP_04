#include "Dog.hpp"

Dog::Dog() : Animal()
{
	type = "Dog";
	dog_brain = new Brain();
	std::cout << "Dog:: Derived class default constructor called" << '\n';
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
		std::cout << "Dog:: Derived class copy assignment called" << '\n';
	}
	return (*this);
}

Dog::~Dog()
{
	delete dog_brain;
	std::cout << "Dog:: Derived class default destructor called" << '\n';
}

void	Dog::makeSound(void) const
{
	std::cout << "Wouf" << '\n';
}
