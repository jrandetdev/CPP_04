#include "Animal.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int main()
{
	{
		const Animal* meta = new Animal();
		const Animal* j = new Dog();
		const Animal* i = new Cat();
		std::cout << "the type of the first animal is " << j->getType() << " " << std::endl;
		std::cout << "the type of the second animal is" << i->getType() << " " << std::endl;
		std::cout << "Dog makes the following sound" << '\n';
		i->makeSound();
		std::cout << "Dog makes the following sound" << '\n';
		j->makeSound();
		meta->makeSound();
		delete(i);
		delete(j);
		delete(meta);
	}
	std::cout << '\n' << '\n';
	{
		const WrongAnimal *metawrong = new WrongAnimal();
		const WrongAnimal *metacat = new WrongCat();
		std::cout << "the type of the first animal is " << metawrong->getType() << std::endl;
		std::cout << "the type of the first animal is " << metacat->getType() << std::endl;
		metawrong->makeSound();
		metacat->makeSound();
		delete(metacat);
		delete(metawrong);
	}
}
