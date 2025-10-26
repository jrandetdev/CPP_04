#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	std::cout << "MateriaSource:: Default constructor called" << std::endl;
}

MateriaSource::MateriaSource(const MateriaSource& other)
{
	(void)other;
}

MateriaSource& MateriaSource::operator=(const MateriaSource& other)
{
	(void)other;
	return (*this);
}

MateriaSource::~MateriaSource()
{

}

/// @brief not sure yet
/// @param  
void MateriaSource::learnMateria(AMateria*)
{
	for (int i = 0; i < 4; ++i)
	{
		if (materia_recipes[i])
		{
			delete materia_recipes[i];
			materia_recipes[i] = NULL;
		}
	}
}

// AMateria* MateriaSource::createMateria(std::string const & type)
// {
// 	(void)type;
// 	return (this);
// }
