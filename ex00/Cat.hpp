#include "Animal.hpp"
#include <iostream>
#include <string>

// Derived class from Animal the Cat inherits of all the attributes
// of its base class Animal.
class Cat : public Animal
{
	private:

	public:
		Cat();
		Cat(const Cat& other);
		Cat& operator=(const Cat& other);
		~Cat();
		void makeSound(void) const;
} ;
