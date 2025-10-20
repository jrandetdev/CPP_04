#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

#include <iostream>
#include <string>

#define RESET   "\033[0m"		/* Reset */
#define GREEN   "\033[32m"      /* Green */

/**
 * The excercise made sure we understoof how it works and aske us 
 * to implement a WrongAnimal and a WrongCat class. By not putting 
 * the virtual keyword on makesound, if it is called by Dog class,
 * it will just to the generic animal because there is no 
 * vptr or vtable that will go get the most derived version of 
 * the function
 */
class WrongAnimal{
	protected:
		std::string type;
	public:
		WrongAnimal();
		WrongAnimal(const WrongAnimal& other);
		WrongAnimal& operator=(const WrongAnimal& other);
		virtual ~WrongAnimal();
		void makeSound(void) const; // no virtual
		const std::string& getType(void) const;
		void	setType(const std::string& type);
};

#endif
