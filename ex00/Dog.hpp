#include "Animal.hpp"

// Derived class from Animal the Dog inherits of all the attributes
// of its base class Animal.
class Dog : public Animal
{
	private:

	public:
		Dog();
		Dog(const Dog& other);
		Dog& operator=(const Dog& other);
		~Dog();
		void makeSound(void) const;
} ;

