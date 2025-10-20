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
		// Here this test was given to me by the subject.
		// We can already see that the base pointer and the Dog pointer are type compatible

		std::cout << "TEST 1" << '\n';
		const A_Animal*	j = new Dog();
		const A_Animal*	i = new Cat();

		delete j;
		delete i;
	}
	std::cout << '\n';
	{
		/*
			Now we need to use a container, in this case the array. When we do this, 
			we can use pointers to store objects of different derived types
			without worrying about object slicing. The dynamic memory allocation 
			ensures that the full object, including its derived type-specific data and
			bahaviour are preserved. 
		*/
		std::cout << "TEST 2" << '\n';
		const int n = 10;
		A_Animal *dogs_and_cats[n]; //tableau de pointeur de classe (obligee)

		std::cout << '\n';
		std::cout << "allocating the array of A_Animals pointers...." << '\n';
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
			std::cout << "Type of first A_Animal is " << dogs_and_cats[i]->getType() << '\n';
			dogs_and_cats[i]->makeSound();
		}
		
		// I need to delete the pointers within the array of pointers of objects
		for (size_t i = 0; i < n; ++i)
		{
			delete dogs_and_cats[i];
		}
	}
	std::cout << '\n';
	{
		// Test with stack allocated variables, no delete needed
		Dog dog_1;
		Dog dog_2;
		Cat cat_1;
		Cat cat_2;

		A_Animal *pets[4] = {&dog_1, &dog_2, &cat_1, &cat_2};

		std::cout << "---Making the pets bark or miaow---" << std::endl;
		for (int i = 0; i < 4; ++i)
		{
			pets[i]->makeSound();
		}
		
		// for (size_t i = 0; i < 4; ++i)
		// {
		// 	delete pets[i];
		// } no need to delete as we are allocating on the stack
	}
	{
		//test to see how an abstract class A_Animal CANNOT be instantiated
		//object of abstract class type "A_Animal" is not allowed:C/C++(322)
		//A_Animal tests_that_wont_work;
	}
	
}
