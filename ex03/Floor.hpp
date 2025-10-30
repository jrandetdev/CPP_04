#ifndef FLOOR_HPP
# define FLOOR_HPP

#include "AMateria.hpp"

class Floor
{
	private:
		Floor();
		~Floor();
	protected:
		AMateria *floor[100];
		int currentIndex;
	public:
		static Floor &getInstance();
		void	fillFloor(AMateria* m);
};

#endif
