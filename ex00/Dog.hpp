#include "Animal.hpp"

class Dog : virtual public Animal
{
	private:

	public:
		Dog();
		Dog(const Dog& other);
		Dog& operator=(const Dog& other);
		~Dog();
}