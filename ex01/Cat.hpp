#include "Animal.hpp"
#include <iostream>
#include <string>

class Cat : public Animal, public Brain
{
	private:
		Brain *cat_brain;
	public:
		Cat();
		Cat(const Cat& other);
		Cat& operator=(const Cat& other);
		~Cat();
		void makeSound(void) const;
} ;
