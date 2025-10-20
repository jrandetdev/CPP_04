#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"


/**
 * @brief 
 * @param Animal is the base class.
 * @param Dog and @param Cat are derived classes.
 * Cat and dog have a pointer to a @param Brain object (see Brain.hpp) as their
 * private attribute.
 * Upon construction, Cat and Dog will create their Brain using new Brain();
 * Upon destruction, Cat and Dog will delete their Brain.
 * 
 * @param dogs_and_cats is an arrray of @class Animal objects. Half of it
 * is composed of Dog @class objects, and the other half will be Cat @class objects
 * The base type of Dog and Cat is an Animal. 
 * if it was an array of animals, then I would need only animal objects.
 * It needs to be an array of pointers to its derived objects so that 
 * 
 * 
 * Polymorphism with a base class and derived classes 
 * 1. create the mold of base class to sstocl the different types of the same type Animal
 * 2. I need to create an array of pointers of type Animal 
 * 
 * this works because a pointer to thew base class and a pointer to the $
 * derived class are type compatible
 * 
 * A pointer to a derived class is a pointer of a base class pointing to a derived class but
 * it will hold its aspect
 */
int main()
{
	{
		std::cout << "TEST 1" << '\n';
		const Animal*	j = new Dog();
		const Animal*	i = new Cat();

		delete j;
		delete i;
	}
	std::cout << '\n';
	{
		std::cout << "TEST 2" << '\n';
		const int n = 10;
		Animal *dogs_and_cats[n]; //tableau de pointeur de classe (obligee)

		std::cout << '\n';
		std::cout << "allocating the array of animals...." << '\n';
		for (size_t i = 0; i < n; ++i)
		{
			if (i < (n / 2))
				dogs_and_cats[i] = new Dog(); // des le moment que  new, on a des pointeurs 
			else
				dogs_and_cats[i] = new Cat();
			std::cout << '\n';
		}
		std::cout << '\n';
		std::cout << "getting types and debugging...." << '\n';
		for (size_t i = 0; i < n; ++i)
		{
			std::cout << "Type of first animal is " << dogs_and_cats[i]->getType() << '\n';
			dogs_and_cats[i]->makeSound();
		}
		
		for (size_t i = 0; i < n; ++i)
		{
			delete dogs_and_cats[i];
		}
	}
	
}
