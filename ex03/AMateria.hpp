#ifndef AMATERIA_HPP
# define AMATERIA_HPP

#include <iostream> 
#include <string>
#include "ICharacter.hpp"

#define RED     "\033[31m"      /* Red */
#define GREEN   "\033[32m"      /* Green */
#define BLUE    "\033[34m"      /* Blue */
#define RESET   "\033[0m"		/* Reset */
#define MAG		"\033[35m"


class AMateria
{
	protected:
	/**
	 * @brief Base class for spells, type set by derived classes (ice or cure)
	 */
		std::string type;
	public:
		AMateria();
		AMateria(std::string const & type); // sets the type of Materia
		AMateria(const AMateria& other);
		AMateria& operator=(const AMateria& other);
		/**
		 * @brief Return the type of the Materia spell
		 * @return a string with the spell name (ice or cure)
		 */

		std::string const & getType() const;
		/**
		 * @brief Creates a deep copy of the Materia in question. For type safety, it will
		 * 			return Ice* for the Ice class. 
		 * @return a pointer to newly created heap-allocated copy of this materia. 
		 * @details This is a pure virtual function that enforces the prototype design pattern,
		 * 			enabling polymorphism copying. Each derived class must override this function to return
		 * 			a deep copy of itself, using the copy constructor with *this.
		 */
		virtual AMateria* AMateria::clone() const = 0;
		/**
		 * @brief virtual function to be overriden by Ice and Cure
		 * @param target a reference to the base class ICharacter 
		 * @see ICharacter.hpp, Ice.cpp and Cure.cpp
		 */
		virtual void use(ICharacter& target);
		virtual ~AMateria();
}

#endif