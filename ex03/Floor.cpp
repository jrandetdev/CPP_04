#include "Floor.hpp"

Floor::Floor()
{
	for (int i = 0; i < 100; ++i)
	{
		floor_storage[i] = NULL;
	}
	std::cout << "Floor: default constructor called" << std::endl;
}

Floor::Floor(const Floor& other)
{
	// The default constructor is not called automatically when the copy const is called
	
	
	
	for (int i = 0; i < 100; ++i)
	{
		// first need to check if the other pointer to a materia is valid
		if (other.floor_storage[i] != NULL)
		{
			// this line is wrong but I kept it for learning purpose. this just assigns
			// pointers from one array to anothe but this is a shallow copy.
			// It would mean both floor arrays point to the same AMateria objects in memory
			// It would cause a double deletion of a materia Ice at address 0x2000
			// If floor2 deletes, then floor1 would delete too.
			//this->floor_storage[i] = other.floor_storage[i];
		}
	}
}

Floor& Floor::operator=(const Floor& other)
{
	if (this != &other)
	{
		return (*this);
	}
	return (*this);
}
