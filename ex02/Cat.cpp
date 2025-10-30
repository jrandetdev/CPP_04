#include "Cat.hpp"

Cat::Cat() : A_Animal()
{
	type = "Cat";
	cat_brain = new Brain();
	std::cout << GREEN << "Cat:: Derived class default constructor called" << RESET << '\n';
}

Cat::Cat(const Cat& other) : A_Animal(other), cat_brain(new Brain(*(other.cat_brain)))
{
	std::cout << "Cat:: Derived class copy constructor called" << '\n';
}

Cat& Cat::operator=(const Cat& other)
{
	if (this != &other)
	{
		A_Animal::operator=(other);
		*(this->cat_brain) = *(other.cat_brain);
		std::cout << "Cat:: Derived class copy assignment called" << '\n';
	}
	return (*this);
}

Cat::~Cat()
{
	delete cat_brain;
	std::cout << RED << "Cat:: Derived class default destructor called" << RESET <<'\n';
}

void	Cat::makeSound(void) const
{
	std::cout << GREEN << "Miaou" << RESET << '\n';
}

void	Cat::setIdea(const std::string& idea, int i)
{
	cat_brain->setIdea(idea, i);
}

const std::string Cat::getIdea(int i)
{
	return (cat_brain->getIdea(i));
}

