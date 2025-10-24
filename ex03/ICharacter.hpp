#ifndef CHARACTER_HPP
# define CHARACTER_hpp

#include "AMateria.hpp"

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