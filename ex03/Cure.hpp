#ifndef CURE_HPP
# define CURE_HPP

#include "AMateria.hpp"

/**
 * @brief Cure is a concrete class for Materias and inherits AMateria.
 * 
 * The defining characteristics of a concrete class is that its representation
 * is part of its definition. We can place objects of concrete types on the stack,
 *  in statically allocated memory, and in other objects. Cure classes can also
 * be initialised immediately and completely using constructors and we can copy the object 
 */
class Cure : public AMateria
{
	public:
		Cure();
		Cure(const Cure& other);
		Cure& operator=(const Cure &other);
		~Cure();
		AMateria* clone() const;
		void use(ICharacter& target);
};

#endif
