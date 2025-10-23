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
 * @class Animal
 * @brief Abstract base class represemtomg a generic animal.
 * 
 * The animal class serves as a polymorphic base for a hierarchy of animal 
 * types. It provides a common interface through virtual functions and manages
 * the animal's type iodentification through a protected member accessible 
 * to derived classes.
 *
 * @details
 * This class demonstrates several C++ concepts:
 * - Virtual functions and runtime polymorphism 
 * - Protected members for controlled inheritance (only derived functions have access)
 * - The use of the canonical form
 * - Virtual function for the destuctor for proper cleanup of resources
 * 
 * Derived classes should:
 * - Call the base constructor of the Animal class (base of the derived class)
 * - Override the makesound function to provide animal type specific behaviour
 * - Set the type of the animal in the constructor.
 * 
 * @see Cat, Dog
 */
class Animal{
	protected:
		std::string type;
	public:
		Animal();

		/**
		 * @brief copy constructor
		 * 
		 * Creates a deep copy of another Animal object. Copies the type string from 
		 * the source object.
		 * 
		 * @param other Animal to copy from.
		 * @post Makes a completely independant copy
		 * 
		 */
		Animal(const Animal& other);
		Animal& operator=(const Animal& other);
		//making the destuctor virtual ensures that the most derived version is 
		// destryed first
		virtual ~Animal();
		virtual void makeSound(void) const;
		const std::string& getType(void) const;
		void	setType(const std::string& type);
};

#endif
