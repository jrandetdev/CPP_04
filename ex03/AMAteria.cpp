#include "AMateria.hpp"

AMateria::AMateria()
{
	type = "";
	std::cout << GREEN << "AMateria:: Default constructor called" << RESET << std::endl;
}

AMateria::AMateria(std::string const & type)
{
	this->type = type;
	std::cout << GREEN << "AMateria:: constructor called with type" << RESET << '\n';
}

AMateria::AMateria(const AMateria& other)
{
	this->type = other.type;
	std::cout << GREEN << "AMateria:: Copy constructor called with type" << RESET << '\n';
}

AMateria& AMateria::operator=(const AMateria& other)
{
	if (this != &other)
	{
		//it says that copying the type does not make sense
	}
	return (*this);
}

/**
 * @brief Activates the materia's spell effect on a target character.
 * @param target	Reference to the character that will be affected by the spell.
 * @invariant The target must be a valid reference to an ICharacter object.
 * @details This is the default implementation in the AMateria abstract base class. 
 * 			It performs no actual effect and simply outputs that a spell was used. 
 * 			This method is intended to be overriden by derived classes (such as Ice and Cube), and these
 * 			derived functions **must** override them.
 * @note This function should only be called as a debugging tool.
 * @see Ice::use for Ice spell implementation
 * @see Cure:use for healing spell
 * @see Icharatcer interface documentation
 * 
 * @example usage:
 * Ice* ice = new Ice();
 * ICharacter* player = new Character("Alice");
 * ice->use(*player) // Calls Ice::use(), not AMateria::use()
 * 
 * @warning If you see output from this base implementation in production, verify that:
 * 			1. Your derived class properly overrides use() witht the correct signature
 * 			2. You are not slicing objects durring assignment. 
 * 			3. Virtual function dispatch works correctly.
 */
void	AMateria::use(ICharacter& target)
{
	std::cout << "Amateria:: base spell used, no power..." << std::endl;
}

AMateria::~AMateria()
{
	std::cout << RED << "AMateria:: default destructor called" << RESET << '\n';
}
