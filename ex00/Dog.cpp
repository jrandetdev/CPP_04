#include "Dog.hpp"

Dog::Dog() : Animal()
{
	type = "Dog";
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
}

Dog::~Dog()
{
	std::cout << "Dog:: Derived class default destructor called" << '\n';
}

void	Dog::makeSound()
{

}