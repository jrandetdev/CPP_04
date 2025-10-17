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
		void makeSound(void) const;
} ;
