#ifndef CHARACTER_HPP
# define CHARACTER_hpp

#include "AMateria.hpp"

/**
 * Concrete class character will inherit the following interface
 * This is an abstract class. All functions are pure virtual functions.
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