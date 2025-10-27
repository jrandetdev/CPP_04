#include "AMateria.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"
#include "Floor.hpp"

Floor* Floor::instancePtr = 0;

/**
 * The goal of this exercise is to learn how to use Subtype
 * polymorphism, ad-hoc polymorphism, and inheritance in general
 */
int main()
{
	{
		Floor *test = Floor::getInstance();
		Floor *test2 = Floor::getInstance();

		std::cout << test << '\n';
		std::cout << test2 << '\n';
	}
	{
		Character jojo;
		jojo.equip()
	}
}

