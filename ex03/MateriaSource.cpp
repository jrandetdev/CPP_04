#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	//std::cout << "MateriaSource:: Default constructor called" << std::endl;
	for (int i = 0; i < 4; ++i)
	{
		materia_recipes[i] = 0;
	}
}

MateriaSource::MateriaSource(const MateriaSource& other)
{
		for (int i = 0; i < 4; ++i)
	{
		materia_recipes[i] = 0;
	}
	for (int i = 0; i < 4; ++i)
	{
		this->materia_recipes[i] = other.materia_recipes[i]->clone();
	}
}

MateriaSource& MateriaSource::operator=(const MateriaSource& other)
{
	for (int i = 0; i < 4; ++i)
	{
		if (other.materia_recipes[i] && (this->materia_recipes[i] == 0))
			this->materia_recipes[i] = other.materia_recipes[i]->clone();
		else
			this->materia_recipes[i] = 0;
	}
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
	//std::cout << "the type of m is " << m->getType() << '\n';
	for (int i = 0; i < 4; ++i)
	{
		if (this->materia_recipes[i] == 0)
		{
			//std::cout << "MateriaSource:: learning a materia for " << m->getType() << " Materia" << '\n';
			this->materia_recipes[i] = m;
			return ;
		}
		else if (i == 3 && this->materia_recipes[i])
		{
			delete m;
			//std::cout << "MateriaSource inventory of Materias is full" << '\n';
			return ;
		}
	}
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
	if (type != "ice" && type != "cure")
	{
		std::cout << RED << "Error: MateriaSource::createMateria type enteted is not ice or cure." << RESET << '\n';
		return (NULL);
	}
	for (int i = 0; i < 4; ++i)
	{
		if (type == "ice" && (this->materia_recipes[i]->getType() == "ice"))
		{
			return this->materia_recipes[i]->clone();
		}
		else if (type == "cure" && (this->materia_recipes[i]->getType() == "cure"))
		{
			return this->materia_recipes[i]->clone();
		}
	}
	std::cout << RED << "Error: MateriaSource does not have the recipe" \
					" for a Materia of type " << type << ". Please use MateriaSource::learnMateria" \
					" first to store it in memory." << RESET << '\n';
	return (NULL);
}
