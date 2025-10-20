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
 * This is the base class Animal. All the derived classes 
 * wil have access to its public and protected members but 
 * not its private members. 
 * 
 * The goal of this exercise is for instances of the derived animal class
 * to call the appropriate function and not the generic sound made by the 
 * base class. When executed, a virtual function executes the most 
 * derived version of that function. If it does not make sense to 
 * implement a function in the base class cpp file, we will mark
 * the virtual functions ad pure virtual function with the =0
 * meaning it has no implementation. 
 * 
 * this is see in the ex02 :)
 */
class Animal{
	protected:
		// type is private and is only visible to the class members
		std::string type;
	public:
		Animal();
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
