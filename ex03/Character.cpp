#include "Character.hpp"

Character::Character() : ICharacter()
{
	//how the fuck do I allocate this array 
	
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


}

Character& Character::operator=(const Character& other)
{

}

Character::~Character()
{
	//meaning when we delete character, we will need to make a separate pointe

}

std::string const & Character::getName() const
{
	return (this->name);
}

void Character::equip(AMateria* m)
{
	//equip you need to see if there is still space
	//how to check if there is space?

}

void Character::unequip(int idx) // will use the idex of the inventory
{

}

void Character::use(int idx, ICharacter& target)
{

}
