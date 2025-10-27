#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	std::cout << "MateriaSource:: Default constructor called" << std::endl;
}

MateriaSource::MateriaSource(const MateriaSource& other)
{
	for (int i = 0; i < 4; ++i)
	{
		this->materia_recipes[i] = other.materia_recipes[i]->clone();
	}
}

MateriaSource& MateriaSource::operator=(const MateriaSource& other)
{
	(void)other;
	return (*this);
}

MateriaSource::~MateriaSource()
{
	for (int i = 0; i < 4; ++i)
	{
		if (materia_recipes[i])
		{
			delete materia_recipes[i];
			materia_recipes[i] = 0;
		}
	}
}

/// @brief not sure yet
/// @param  
void MateriaSource::learnMateria(AMateria* m)
{
	if (!m)
		return ;
	for (int i = 0; i < 4; ++i)
	{
		if (this->materia_recipes[i] == 0)
		{
			this->materia_recipes[i] = m;
		}
	}
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
	
}
