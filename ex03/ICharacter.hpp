#ifndef ICHARACTER_HPP
# define ICHARACTER_HPP

#include <string>

//#include "AMateria.hpp"

class AMateria; // here only a pointer is needed, so no need for the complete definition
//Sufficient because we ony use pointers

/**
 * @brief contract with the derived classes that they need 
 * to implement the definitions below.
 */
class ICharacter
{
	public:
		virtual ~ICharacter() {};
		virtual std::string const & getName() const = 0; //get the Name of the character
		virtual void equip(AMateria* m) = 0;
		virtual void unequip(int idx) = 0;
		virtual void use(int idx, ICharacter& target) = 0;
};

#endif
