#ifndef IMATERIASOURCE_HPP
# define IMATERIASOURCE_HPP

#include <iostream>
#include <string>
#include "AMateria.hpp"

#define RED     "\033[31m"      /* Red */
#define YELLOW  "\033[33m"      /* Yellow */
#define GREEN   "\033[32m"      /* Green */
#define BLUE    "\033[34m"      /* Blue */
#define RESET   "\033[0m"		/* Reset */
#define MAG		"\033[35m"

//Interface made of pure virtual function, expects the derived class to implement 
/**
 * @brief Interface IMateriaSource behaves as such: 
 * 
 * - It contains the declaration of the methods, not definitions
 * 
 * - The interface methods must be declared public
 * 
 * - Any class can implement/inherit any interface.
 * 
 * - It contains only pure abstract virtual methods
 * 
 * - The implementing class must provide the definition of the methods otherwise
 * it becomes an abstract class
 * 
 * - An Instance of a pure virtual class cannot be initialised.
 */
class IMateriaSource
{
	public:
		virtual ~IMateriaSource() {}; //this forces me to make the destructor of the class 
		virtual void learnMateria(AMateria*) = 0;
		virtual AMateria* createMateria(std::string const & type) = 0;
} ;

#endif
