#ifndef AMATERIA_HPP
# define AMATERIA_HPP

#include <iostream> 
#include <string>
#include "ICharacter.hpp"

#define RED     "\033[31m"      /* Red */
#define GREEN   "\033[32m"      /* Green */
#define BLUE    "\033[34m"      /* Blue */
#define RESET   "\033[0m"		/* Reset */
#define MAG		"\033[35m"


class AMateria
{
	protected:
		std::string type;
	public:
		AMateria();
		AMateria(std::string const & type); // sets the type of Materia
		AMateria(const AMateria& other);
		AMateria& operator=(const AMateria& other);

		std::string const & getType() const; // Returns the materia type
		//void	setType(std::string const type);

		virtual AMateria* AMateria::clone() const = 0;
		virtual void use(ICharacter& target);

		virtual ~AMateria() = 0;
};

#endif