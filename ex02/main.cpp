#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"


/**
 * @brief Demonstrates polymorphism, abatract classes, and dynamic memory allocation.
 * 
 * KEY CONECPTS DEMONSTRATED:
 * 
 * 1. Polymorphism and inheritance
 * 
 * 		- A_Animal is an abstracr class (interface)
 * 
 * 		- Dog and Cat are concrete derived class of Animal.
 * 
 * 		- major learning: the Base class pointer can be used to access derived class
 * 		with virtual member functions. Mapping of all the virtual functions with the
 * 		vtable and vptr. Even if we use the Base pointer, the correct version of 
 * 		the object is used.
 * 
 * 2. Composition:
 * 
 * 		- Each animal contains a brain
 * 
 * 		- The brain is dynamically allocated during construction and deleted
 * 		during destruction assuring good memory management. 
 * 
 * 3. Dynamic polymorphism:
 * 
 * 		- Virtual functions enable runtime polymorphism
 * 
 * 		- makesound() behaviour depends on the actual object type
 * 
 * 		- When using polymorphism, virtual destructor must systematically 
 * 		be used for proper cleanup of resources. 
 * 
 * 4. Prevention of object slicing
 * 		- Allocation of the base class avoids slicing of the object and access
 * 		to the derived objects allocated on the heap
 * 
 * FINAL LEARNING:
 * 		- Animal dogs_and_cats[10] would cause object slicing and losing the derived data.
 * 		- Animal *dogs_and_cats[10] preserves complete derived objects
 * 		- Type compatibility: Cats and Dogs are both Animals*
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
