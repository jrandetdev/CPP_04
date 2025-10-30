#include "Character.hpp"
#include "Floor.hpp"

Character::Character() : ICharacter(), name("")
{
	for (int i = 0; i < 4; ++i)
	{
		inventory[i] = 0;
	}
	//std::cout << "Character:: Default constructor called." << std::endl;
}

Character::Character(std::string const name) : name(name)
{
	for (int i = 0; i < 4; ++i)
	{
		inventory[i] = 0;
	}
	//std::cout << "Character:: constructor called for " << this->name << std::endl;
}

/**
 * @brief copy constructor of Character class, performs a Deep copy of the Character,
 * meaning the new Character gets 
 * 
 * Using the clone function to create new independent character at a new memory
 * address.
 * 
 * If the original character's
 * 
 */
Character::Character(Character const & other) : name(other.name)
{
	for (int i = 0; i < 4; ++i)
	{
		if (other.inventory[i])
			this->inventory[i] = other.inventory[i]->clone(); // clone function returns a new pointer 
		else
			this->inventory[i] = 0;
	}
}


Character& Character::operator=(const Character& other)
{
	if (this != &other)
	{
		for (int i = 0; i < 4; ++i)
		{
			if (this->inventory[i])
			{
				delete this->inventory[i];
				this->inventory[i] = 0;
			}
		}
		for (int i = 0; i < 4; ++i)
		{
			if (other.inventory[i])
				this->inventory[i] = other.inventory[i]->clone();
			else
				this->inventory[i] = 0;
		}
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
	if (!m)
		return ;
	if (m->getType() != "ice" && m->getType() != "cure")
	{
		std::cout << RED << "Error! Character:: cannot equip a Materia other than ice or cure." << RESET << '\n';
		return ;
	}
	for (int i = 0; i < 4; ++i)
	{
		if (this->inventory[i] == 0)
		{
			this->inventory[i] = m;
			return ;
		}
		else if ((i == 3) && (this->inventory[i]))
		{
			Floor::getInstance().fillFloor(m);
			std::cout << RED << "Error! Character:: inventory is full! No more space, please unequip" \
					" if you wish to add this Materia to " << this->getName() << "'s inventory." \
			RESET << std::endl;
			return ;
		}
	}
}

bool	Character::is_valid_idx(int idx)
{
	if (0 <= idx && idx <= 3)
		return true;
	//std::cout << "Character:: inventory index is between 0 and 3." << '\n';
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
		return ;
	if (inventory[idx])
	{
		std::cout << "entered the part where he fills floor" << '\n';
		Floor::getInstance().fillFloor(inventory[idx]);
		inventory[idx] = 0;
	}
	else
	{
		std::cout << RED << "Error! Inventory slot is empty, no Materia to put on the floor." << RESET << '\n';
		return ;
	}
}


void Character::use(int idx, ICharacter& target)
{
	if (!(is_valid_idx(idx)))
		return ;
	if (this->inventory[idx])
		this->inventory[idx]->use(target);
	else
		std::cout << RED << "Error: No Materia at this index!" << RESET << '\n';
	return ;
}


Character::~Character()
{
	for (int i = 0; i < 4; ++i)
	{
		delete this->inventory[i];
	}
	//std::cout << "Character:: Default destructor called." << std::endl;
}
