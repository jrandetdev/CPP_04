#include "Animal.hpp"

class Cat : virtual public Animal
{
	private:

	public:
		Cat();
		Cat(const Cat& other);
		Cat& operator=(const Cat& other);
		~Cat();
}