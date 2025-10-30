#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"


/**
 * @brief Demonstrates polymorphism, abatract classes, and dynamic memory allocation.
 * 
 * KEY CONECPTS DEMONSTRATED:
 * 
 * 1. Polymorphism and inheritance
 * 
 * 		- A_Animal is an abstracr class (interface)
 * 
 * 		- Dog and Cat are concrete derived class of Animal.
 * 
 * 		- major learning: the Base class pointer can be used to access derived class
 * 		with virtual member functions. Mapping of all the virtual functions with the
 * 		vtable and vptr. Even if we use the Base pointer, the correct version of 
 * 		the object is used.
 * 
 * 2. Composition:
 * 
 * 		- Each animal contains a brain
 * 
 * 		- The brain is dynamically allocated during construction and deleted
 * 		during destruction assuring good memory management. 
 * 
 * 3. Dynamic polymorphism:
 * 
 * 		- Virtual functions enable runtime polymorphism
 * 
 * 		- makesound() behaviour depends on the actual object type
 * 
 * 		- When using polymorphism, virtual destructor must systematically 
 * 		be used for proper cleanup of resources. 
 * 
 * 4. Prevention of object slicing
 * 		- Allocation of the base class avoids slicing of the object and access
 * 		to the derived objects allocated on the heap
 * 
 * FINAL LEARNING:
 * 		- Animal dogs_and_cats[10] would cause object slicing and losing the derived data.
 * 		- Animal *dogs_and_cats[10] preserves complete derived objects
 * 		- Type compatibility: Cats and Dogs are both Animals*
 */
int main(void)
{
    {
        std::cout << "\nLEAK TEST" << std::endl;
        const A_Animal* j = new(std::nothrow) Dog();
        if (!j)
            return (1);
        const A_Animal* i = new(std::nothrow) Cat();
        if (!i)
            return (delete(j), 1);

        delete j;
        delete i;
    }
    {
        std::cout << "\nCAT COPY TEST" << RESET << std::endl;
        Cat        abyssian;
        Cat        persian;
        Cat        ragdoll(abyssian);

        persian = ragdoll;
        std::cout << abyssian.getIdea(0) << std::endl;
        std::cout << persian.getIdea(0) << std::endl;
        std::cout << ragdoll.getIdea(0) << std::endl;
        std::cout << "!! ITS NOON !!" << std::endl;
        persian.setIdea("I'm hungry !!", 0);
        ragdoll.setIdea("I'm going hunting", 0);
        std::cout << abyssian.getIdea(0) << std::endl;
        std::cout << persian.getIdea(0) << std::endl;
        std::cout << ragdoll.getIdea(0) << std::endl;
    }
    {
        std::cout << "\nDOG COPY TEST" << RESET << std::endl;
        Dog        borderCollie;
        Dog        goldenRetriver;
        Dog        bullterrier(borderCollie);

        goldenRetriver = bullterrier;
        std::cout << borderCollie.getIdea(0) << std::endl;
        std::cout << goldenRetriver.getIdea(0) << std::endl;
        std::cout << bullterrier.getIdea(0) << std::endl;
        std::cout << "!! ITS NOON !!"<< std::endl;
        goldenRetriver.setIdea("I'm hungry !!", 0);
        bullterrier.setIdea("I want to Play !!", 0);
        std::cout << borderCollie.getIdea(0) << std::endl;
        std::cout << goldenRetriver.getIdea(0) << std::endl;
        std::cout << bullterrier.getIdea(0) << std::endl;
    }
    {
        std::cout << "\nARRAY TEST" << std::endl;
        A_Animal *petShop[8];

        for (int i = 0; i < 4; i++)
        {
            petShop[i] = new(std::nothrow) Cat;
            petShop[i + 4] = new(std::nothrow) Dog;
        }

        for(int i = 0; i < 8; i++)
        {
            if (petShop[i])
            {
                std::cout << petShop[i]->getType() << " ";
                petShop[i]->makeSound();
                delete petShop[i];
            }
        }
    }
    return (0);
}
