#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <iostream>
#include <string>

#define RED     "\033[31m"      /* Red */
#define GREEN   "\033[32m"      /* Green */
#define BLUE    "\033[34m"      /* Blue */
#define RESET   "\033[0m"		/* Reset */
#define MAG		"\033[35m"

/**
 * @Brief
 * @param base class Animal contains pure virual functions =0 and the functions have no body
 * The pure virtual functions are overridden in derived classes. A class with such a  
 * function is called an abstract class abd ut cannot be instantiated. 
 * 
 * 
 * CAREFUL: the base class destructor is declared with = 0 in an abstract
 * class. It ensures the derived destructor is called first.
 * 
 * Early binding happens when a function call is resoved during compilation. 
 * Late binding happen where the exact fuhnction to cal us decuded at tyrbtine deoeednig on
 * the actual object type. Happens with virtual functions. 
 * 
 * This class is literally an interface.
 */
class Animal{
	protected:
		std::string type;
	public:
		Animal();
		Animal(const Animal& other);
		Animal& operator=(const Animal& other);
		// Pure virtual function
		virtual void makeSound(void) const = 0;
		// Pure virtual destructor
		virtual ~Animal() = 0;
		const std::string& getType(void) const;
		void	setType(const std::string& type);
};

#endif
