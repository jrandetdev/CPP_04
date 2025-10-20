#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal()
{
	type = "WrongCat";
	std::cout << "WrongCat:: Derived class default constructor called" << '\n';
}

WrongCat::WrongCat(const WrongCat& other) : WrongAnimal(other)
{
	std::cout << "WrongCat:: Derived class copy constructor called" << '\n';
}

WrongCat& WrongCat::operator=(const WrongCat& other)
{
	if (this != &other)
	{
		WrongAnimal::operator=(other);
		std::cout << "WrongCat:: Derived class copy assignment called" << '\n';
	}
	return (*this);
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat:: Derived class default destructor called" << '\n';
}

void	WrongCat::makeSound(void) const
{
	std::cout << GREEN << "Miaou" << RESET << '\n';
}

