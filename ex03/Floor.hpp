#ifndef FLOOR_HPP
# define FLOOR_HPP

#include <iostream> 
#include <string>
#include "AMateria.hpp"

class Floor
{
	protected:
		AMateria *floor_storage[100];
	public:
		Floor();
		Floor(const Floor& other);
		Floor& operator=(const Floor& other);
		~Floor();
};

#endif

