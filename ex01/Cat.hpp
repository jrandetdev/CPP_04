#include "Animal.hpp"
#include "Brain.hpp"
#include <iostream>
#include <string>

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
		void setIdea(const std::string& idea, int i);
		const std::string getIdea(int i); 
} ;
