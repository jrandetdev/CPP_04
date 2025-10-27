#include "Character.hpp"
#include "Floor.hpp"
Character::Character() : ICharacter(), name("")
{
	for (int i = 0; i < 4; ++i)
	{
		inventory[i] = NULL;
	}
	std::cout << "Character:: Default character called" << std::endl;
}

Character::Character(std::string const name) : name(name)
{
	for (int i = 0; i < 4; ++i)
	{
		inventory[i] = NULL;
	}
	std::cout << "Character:: constructor called for " << this->name << std::endl;
}

/**
 * @brief copy constructor of Character class, performs a Deep copy of the character
 * 
 * Using the clone function to create a new clone of the derived Materia.
 * 
 */
Character::Character(Character const & other) : name(other.name)
{
	for (int i = 0; i < 4; ++i)
	{
		if (other.inventory[i])
			inventory[i] = other.inventory[i]->clone(); // clone function returns a new pointer 
		else
			inventory[i] = NULL;
	}
}

Character& Character::operator=(const Character& other)
{
	if (this != &other)
	{
		this->name = other.name;
	}
	return (*this);
}


std::string const & Character::getName() const
{
	return (this->name);
}

/**
 * @brief equip in the first empty slot they find from slot 0 to 3
 * 
 * Invariants:
 * 
 * - Valid Materia, if not ice or cure it will return and nothing will happen.
 * 
 * - Free space in inventory, if full, it will return and nothing will happen.
 */
void Character::equip(AMateria* m)
{
	if (m->getType() != "ice" && m->getType() != "cure")
	{
		std::cout << RED << "Error! Character:: cannot equip a Materia other than ice or cure." << RESET << '\n';
		return ;
	}
	for (int i = 0; i < 4; ++i)
	{
		if (this->inventory[i] == NULL)
		{
			this->inventory[i] = m;
		}
		else if ((i == 4) && (this->inventory[i]))
		{
			std::cout << RED << "Error! Character:: inventory is full! No more space, please unequip \
			if you wish to add this Materia to " << this->getName() << "'s inventory." \
			RESET << std::endl;
			return ;
		}
	}
}

bool	Character::is_valid_idx(int idx)
{
	if (0 <= idx && idx <= 3)
		return true;
	return false;
}

/**
 * @brief The unequip() function cannot unequip an innexisting materia.
 * 
 * The unequip function must not delete the Materia.
 */
void Character::unequip(int idx)
{
	if (!(is_valid_idx(idx)))
	{
		std::cout << "Character:: inventory index is between 0 and 3." << '\n';
		return ;
	}
	if (inventory[idx])
	{
		floorPtr->fillFloor(inventory[idx]);
	}
	else
	{
		std::cout << RED << "Error! Inventory slot is empty, no Materia to put on the floor." << RESET << '\n';
		return ;
	}
}

void Character::use(int idx, ICharacter& target)
{
	(void)target;
	(void)idx;
	//delete the materia in inventory after use
}

Character::~Character()
{
	std::cout << "Character:: Default destructor called." << std::endl;
}
