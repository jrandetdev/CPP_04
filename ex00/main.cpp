#include "Animal.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Cat.hpp"
#include "Dog.hpp"


/**
 * @Brief 
 * 
 * A simple base class @param Animal is the base class and two classes
 * @param Dog and @param Cat inherit from Animal. These two 
 * derived classes set their own types depending on their name and the 
 * type of Animal is left empty. 
 * 
 * The objective of this excercise was to understand virtual functions 
 * and the need to make member functions which will be overwritten
 * to have a behaviour specific to its type virtual.
 * 
 * Dogs dont go miaw and cats dont bark :)
 * 
 * When using polymorphism we need to allocate pointers to objects.
 * Pointers are essential when working with ccollections, witout 
 * pointers colelctions are subject to object slicing where 
 * the base of an object is stored with the derived behaviour cut off.
 * 
 * @def Subtype Polymorphism is the ability to use the shared interface of
 * derived clases by way of references or pointers to the base class. 
 * 
 */
int main()
{
	{	// use the operator new to request memory from the free store (heap)

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
		delete(metacat); //delete does not delete memory, it simply returns it to the heap
		delete(metawrong);
	}
}
