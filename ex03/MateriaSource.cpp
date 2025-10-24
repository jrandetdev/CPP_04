#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	std::cout << "MateriaSource:: Default constructor called" << std::endl;
}

MateriaSource::MateriaSource(const MateriaSource& other)
{
	
}

MateriaSource& MateriaSource::operator=(const MateriaSource& other)
{

}

MateriaSource::~MateriaSource()
{

}

void MateriaSource::learnMateria(AMateria*)
{

}

AMateria* MateriaSource::createMateria(std::string const & type)
{

}
