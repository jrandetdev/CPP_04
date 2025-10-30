#ifndef CHARACTER_HPP
# define CHARACTER_HPP

#include "AMateria.hpp"
#include "ICharacter.hpp"
#include <iostream>
#include <string>

class Floor;

/**
 * @brief Character class implements the ICharacter interface. 
 */
class Character : public ICharacter
{
	private:
	/**
	 * @brief Inventory of 4 slots for objects of type Materia.
	 * The inventory is empty upon construction. The inventory is equiped 
	 * in the first empty slot they find, in the following order: from slot
	 * 0 to slot 3.
	 * 
	 * If the character tries to add a Materia to a full inventory, or
	 * use/unequip a non-existent Materia, nothing should happen
	 * (the cases still need to be handled).
	 */
		AMateria *inventory[4]; // pointer to pointer of materia 
		std::string name;

	public:
		Character();
		Character(std::string const name);
		Character(const Character& other);
		Character& operator=(const Character& other);
		virtual ~Character();
		virtual std::string const & getName() const;
		virtual void equip(AMateria* m);
		virtual void unequip(int idx); // will use the idex of the inventory
		virtual void use(int idx, ICharacter& target);
		bool	is_valid_idx(int idx);
};

#endif
