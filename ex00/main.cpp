#include "Animal.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Cat.hpp"
#include "Dog.hpp"


/**
 * @Brief 
 * 
 * A simple base class @param Animal is the base class and two classes
 * @param Dog and @param Cat inherit from Animal. These two 
 * derived classes set their own types depending on their name and the 
 * type of Animal is left empty. 
 * 
 * The objective of this excercise was to understand virtual functions 
 * and the need to make member functions which will be overwritten
 * to have a behaviour specific to its type virtual.
 * 
 * Dogs dont go miaw and cats dont bark :)
 * 
 * When using polymorphism we need to allocate pointers to objects.
 * Pointers are essential when working with ccollections, witout 
 * pointers colelctions are subject to object slicing where 
 * the base of an object is stored with the derived behaviour cut off.
 * 
 * @def Subtype Polymorphism is the ability to use the shared interface of
 * derived clases by way of references or pointers to the base class. 
 * 
 */
int main()
{
    // ===================================================================
    // SECTION 1: Demonstrating Correct Polymorphism (Virtual Functions)
    // ===================================================================
    {
        std::cout << "=== Testing Polymorphism with Virtual Functions ===\n\n";
        
        const Animal* meta = new Animal();
        const Animal* cat = new Cat();
        const Animal* dog = new Dog();
        
        // Display types
        std::cout << "Object types:\n";
        std::cout << "  - dog->getType(): " << dog->getType() << '\n';
        std::cout << "  - cat->getType(): " << cat->getType() << '\n';
        std::cout << "  - meta->getType(): " << meta->getType() << '\n';
        std::cout << '\n';
        
        // Demonstrate polymorphic behavior
        std::cout << "Sounds produced (via base class pointers):\n";
        std::cout << "  Cat: ";
        cat->makeSound();
        
        std::cout << "  Dog: ";
        dog->makeSound();
        
        std::cout << "  Animal: ";
        meta->makeSound();
        
        std::cout << '\n';
        
        // Clean up
        delete cat;
        delete dog;
        delete meta;
    }
    
    std::cout << "\n";
    
    // ===================================================================
    // SECTION 2: Demonstrating Incorrect Behavior (Non-Virtual Functions)
    // ===================================================================
    {
        std::cout << "=== Testing WITHOUT Virtual Functions (Wrong Behavior) ===\n\n";
        
        const WrongAnimal* wrongAnimal = new WrongAnimal();
        const WrongAnimal* wrongCat = new WrongCat();
        
        std::cout << "Object types:\n";
        std::cout << "  - wrongAnimal->getType(): " << wrongAnimal->getType() << '\n';
        std::cout << "  - wrongCat->getType(): " << wrongCat->getType() << '\n';
        std::cout << '\n';
        
        std::cout << "Sounds produced (static binding - notice the problem):\n";
        std::cout << "  WrongAnimal: ";
        wrongAnimal->makeSound();
        
        std::cout << "  WrongCat (but calls WrongAnimal's sound!): ";
        wrongCat->makeSound();
        
        std::cout << '\n';
        
        // Clean up - returns memory to the free store
        delete wrongCat;
        delete wrongAnimal;
    }
    
    return 0;
}
