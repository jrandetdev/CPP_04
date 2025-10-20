#include "WrongAnimal.hpp"
#include <iostream>
#include <string>

/**
 * @brief
 * 
 * @param WrongCat 
 */
class WrongCat : public WrongAnimal
{
	private:

	public:
		WrongCat();
		WrongCat(const WrongCat& other);
		WrongCat& operator=(const WrongCat& other);
		~WrongCat();
		//It does define the makesound function, but its not virtual in the baseclass!
		void makeSound(void) const;
} ;
