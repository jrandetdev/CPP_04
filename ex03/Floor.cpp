#include "Floor.hpp"

Floor::Floor() : currentIndex(0)
{
	for (int i = 0; i < 100; ++i)
	{
		floor[i] = 0;
	}
	//std::cout << "Floor:: Default constructor called" << '\n';
}

Floor &Floor::getInstance()
{
	static Floor instancePtr;
	
	return (instancePtr);
}

void	Floor::fillFloor(AMateria* m)
{
	std::cout << "entered fillfloor function" << '\n';
	if (!m)
		return ;
	currentIndex++;
	if (currentIndex > 99)
		delete floor[currentIndex % 100];
	floor[currentIndex % 100] = m;
	std::cout << "Floor:: Character dropped his " << m->getType() << " Materia" \
			" on the floor." << '\n';
	std::cout << "character has dropped on the floor" << '\n';
}

Floor::~Floor()
{
	for (int i = 0; i < 100; ++i)
	{
		if (floor[i])
		{
			delete floor[i];
			floor[i] = 0;
		}
	}
	//std::cout << "Floor:: Default destructor called" << '\n';
}
