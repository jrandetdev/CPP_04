#ifndef ICE_HPP
# define ICE_HPP

#include "AMateria.hpp"

class Ice : public AMateria
{
	public:
		Ice();
		Ice(const Ice& other);
		Ice& operator=(const Ice &other);
		~Ice();
		/**
		 * @brief Clone is a member function belonging to the Animal class.
		 * 
		 * It returns a deep copy (a new independant instance) of the same type. Uses (copy constructor)
		 * 
		 * @return a pointer to a newly created heap-allocated deep copy of an Ice Materia. 
		 * @details This function will use the copy constructor with *this.
		 */
		Ice* clone() const;
		void use(ICharacter& target);

};

#endif