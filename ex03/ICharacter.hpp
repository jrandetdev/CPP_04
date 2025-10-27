#ifndef ICHARACTER_HPP
# define ICHARACTER_HPP

#include <string>

#define RED     "\033[31m"      /* Red */
#define YELLOW  "\033[33m"      /* Yellow */
#define GREEN   "\033[32m"      /* Green */
#define BLUE    "\033[34m"      /* Blue */
#define RESET   "\033[0m"		/* Reset */
#define MAG		"\033[35m"


class AMateria; // here only a pointer is needed, so no need for the complete definition
//Sufficient because we ony use pointers

/**
 * @brief contract with the derived classes that they need 
 * to implement the definitions below.
 */
class ICharacter
{
	protected:
		AMateria *floor[100];
	public:
		virtual ~ICharacter() {};
		virtual std::string const & getName() const = 0; //get the Name of the character
		virtual void equip(AMateria* m) = 0;
		virtual void unequip(int idx) = 0;
		virtual void use(int idx, ICharacter& target) = 0;
};

#endif
