#include "Character.hpp"

//you cannot instantiate or implement it withut instructions #
// If I did inventory = new AMateria[4] it would block 
Character::Character() : ICharacter()
{
	for (int i = 0; i < 4; ++i)
	{
		inventory[i] = NULL;
	}
	std::cout << "Character:: Default character called" << std::endl;
}

Character::Character(std::string& const name)
{
	this->name = name;
	std::cout << "Character:: constructor called for " << this->name << std::endl;
}

Character::Character(const Character& other)
{
	//Character has a deep copy of it?
	//means we need to have a separate memory space or 
	// pointer for the other memory.
	//another name as well. 
	for (int i = 0; i < 4; ++i)
	{
		delete other.inventory[i];
	}

	


}

Character& Character::operator=(const Character& other)
{
	if (this != &other)
	{
		
	}
}

Character::~Character()
{
	//meaning when we delete character, we will need to make a separate pointe

}

std::string const & Character::getName() const
{
	return (this->name);
}

/**
 * @brief equip in the first empty slot they find from slot 0 to 3
 * 
 * if the inventory is full, 
 */
void Character::equip(AMateria* m)
{
	//checks to do: if valie materia pointer,
	// if available space
	// 
	//equip you need to see if there is still space
	//how to check if there is space?
	int i = 0;
	while (inventory[i])
	{
		if (inventory[i] == NULL)
			inventory[i] = m;
		else
			i++;
		return ;
	}
}

void Character::unequip(int idx) // will use the idex of the inventory
{

}

void Character::use(int idx, ICharacter& target)
{

}
