#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public A_Animal
{
	private:
		Brain *dog_brain;
	public:
		Dog();
		Dog(const Dog& other);
		Dog& operator=(const Dog& other);
		~Dog();
		void makeSound(void) const;
} ;

