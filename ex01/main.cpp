#include "Animal.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int main()
{
	{
		const Animal*	j = new Dog();
		const Animal*	i = new Cat();

		

		delete j;
		delete i;
	}
}
