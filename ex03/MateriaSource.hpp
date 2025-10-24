#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
	protected:
		AMateria *materia_recipes[4];
	public:
		~MateriaSource() {};
		void learnMateria(AMateria*) = 0;
		AMateria* createMateria(std::string const & type) = 0;
};

#endif