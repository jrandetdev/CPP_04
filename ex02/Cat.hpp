#include "Animal.hpp"
#include "Brain.hpp"
#include <iostream>
#include <string>

/**
 * Cat anbd Dog have private attributes which is a pointer to Brain
 * 
 */
class Cat : public Animal
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
