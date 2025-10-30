#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include <iostream>
#include <new>

// ============================================================================
// Test Functions
// ============================================================================

/**
 * @brief Tests basic memory allocation and polymorphic destruction
 * 
 * This test verifies:
 * 1. Proper allocation of derived class objects via base class pointers
 * 2. Correct polymorphic destruction (virtual destructors must be defined)
 * 3. Memory leak prevention through proper cleanup
 * 
 * The std::nothrow specifier prevents exceptions on allocation failure,
 * returning nullptr instead, which we can check explicitly.
 */
void testBasicAllocationAndDestruction()
{
    std::cout << "\n=== BASIC ALLOCATION & DESTRUCTION TEST ===" << std::endl;
    
    const Animal* dog = new(std::nothrow) Dog();
    if (!dog)
    {
        std::cerr << "Failed to allocate Dog" << std::endl;
        return;
    }
    
    const Animal* cat = new(std::nothrow) Cat();
    if (!cat)
    {
        std::cerr << "Failed to allocate Cat" << std::endl;
        delete dog;
        return;
    }
    
    std::cout << "Successfully allocated Dog and Cat" << std::endl;
    std::cout << "Cleaning up..." << std::endl;
    
    delete dog;  // Calls Dog's destructor, then Animal's destructor
    delete cat;  // Calls Cat's destructor, then Animal's destructor
    
    std::cout << "Test completed - check for memory leaks with valgrind" << std::endl;
}

/**
 * @brief Tests deep copy semantics for Cat objects
 * 
 * This test demonstrates the Rule of Three/Five:
 * - Copy constructor: Cat ragdoll(abyssian)
 * - Copy assignment operator: persian = ragdoll
 * - Destructor: handled automatically when objects go out of scope
 * 
 * Each Cat owns a Brain object. Without proper deep copying, multiple
 * Cat objects would share the same Brain pointer, leading to:
 * 1. Unexpected behavior when modifying ideas
 * 2. Double-free errors during destruction
 * 
 * Expected behavior: Each Cat has its own independent Brain, so
 * modifying one Cat's ideas does not affect the others.
 */
void testCatDeepCopy()
{
    std::cout << "\n=== CAT DEEP COPY TEST ===" << RESET << std::endl;
    
    Cat abyssian;
    Cat persian;
    Cat ragdoll(abyssian);  // Copy constructor
    
    persian = ragdoll;      // Copy assignment operator
    
    std::cout << "\nInitial state (all should have default ideas):" << std::endl;
    std::cout << "  Abyssian idea[0]: " << abyssian.getIdea(0) << std::endl;
    std::cout << "  Persian idea[0]:  " << persian.getIdea(0) << std::endl;
    std::cout << "  Ragdoll idea[0]:  " << ragdoll.getIdea(0) << std::endl;
    
    std::cout << "\n!! IT'S NOON - Time to update ideas !!" << std::endl;
    persian.setIdea("I'm hungry !!", 0);
    ragdoll.setIdea("I'm going hunting", 0);
    
    std::cout << "\nAfter modifications (each should be independent):" << std::endl;
    std::cout << "  Abyssian idea[0]: " << abyssian.getIdea(0) << std::endl;
    std::cout << "  Persian idea[0]:  " << persian.getIdea(0) << std::endl;
    std::cout << "  Ragdoll idea[0]:  " << ragdoll.getIdea(0) << std::endl;
    
    if (abyssian.getIdea(0) != persian.getIdea(0) && 
        abyssian.getIdea(0) != ragdoll.getIdea(0))
    {
        std::cout << "\n✓ Deep copy working correctly - each Cat has independent Brain" << std::endl;
    }
    else
    {
        std::cout << "\n✗ Deep copy FAILED - Cats are sharing Brain data!" << std::endl;
    }
}

/**
 * @brief Tests deep copy semantics for Dog objects
 * 
 * Identical test to testCatDeepCopy() but for the Dog class.
 * Verifies that Dog implements the Rule of Three/Five correctly
 * and that each Dog maintains its own independent Brain.
 */
void testDogDeepCopy()
{
    std::cout << "\n=== DOG DEEP COPY TEST ===" << RESET << std::endl;
    
    Dog borderCollie;
    Dog goldenRetriever;
    Dog bullTerrier(borderCollie);  // Copy constructor
    
    goldenRetriever = bullTerrier;   // Copy assignment operator
    
    std::cout << "\nInitial state (all should have default ideas):" << std::endl;
    std::cout << "  Border Collie idea[0]:  " << borderCollie.getIdea(0) << std::endl;
    std::cout << "  Golden Retriever idea[0]: " << goldenRetriever.getIdea(0) << std::endl;
    std::cout << "  Bull Terrier idea[0]:   " << bullTerrier.getIdea(0) << std::endl;
    
    std::cout << "\n!! IT'S NOON - Time to update ideas !!" << std::endl;
    goldenRetriever.setIdea("I'm hungry !!", 0);
    bullTerrier.setIdea("I want to Play !!", 0);
    
    std::cout << "\nAfter modifications (each should be independent):" << std::endl;
    std::cout << "  Border Collie idea[0]:  " << borderCollie.getIdea(0) << std::endl;
    std::cout << "  Golden Retriever idea[0]: " << goldenRetriever.getIdea(0) << std::endl;
    std::cout << "  Bull Terrier idea[0]:   " << bullTerrier.getIdea(0) << std::endl;
    
    if (borderCollie.getIdea(0) != goldenRetriever.getIdea(0) && 
        borderCollie.getIdea(0) != bullTerrier.getIdea(0))
    {
        std::cout << "\n✓ Deep copy working correctly - each Dog has independent Brain" << std::endl;
    }
    else
    {
        std::cout << "\n✗ Deep copy FAILED - Dogs are sharing Brain data!" << std::endl;
    }
}

/**
 * @brief Tests polymorphic array of Animals
 * 
 * This test demonstrates several key C++ concepts:
 * 
 * 1. Polymorphic containers: An array of base class pointers (Animal*)
 *    can hold pointers to derived class objects (Cat, Dog)
 * 
 * 2. Dynamic binding: Calls to virtual functions (makeSound(), getType())
 *    are resolved at runtime based on the actual object type, not the
 *    pointer type
 * 
 * 3. Heterogeneous collections: Unlike an array of Animal objects (which
 *    would slice derived class data), an array of Animal* preserves the
 *    full derived class behavior
 * 
 * 4. Resource management: Each allocated object must be explicitly deleted
 *    to prevent memory leaks
 * 
 * Array layout: [Cat, Cat, Cat, Cat, Dog, Dog, Dog, Dog]
 */
void testPolymorphicArray()
{
    std::cout << "\n=== POLYMORPHIC ARRAY TEST ===" << std::endl;
    
    const int ARRAY_SIZE = 8;
    const int HALF_SIZE = ARRAY_SIZE / 2;
    Animal* petShop[ARRAY_SIZE];
    
    // Allocate half Cats, half Dogs
    std::cout << "\nAllocating animals..." << std::endl;
    for (int i = 0; i < HALF_SIZE; i++)
    {
        petShop[i] = new(std::nothrow) Cat();
        petShop[i + HALF_SIZE] = new(std::nothrow) Dog();
        
        if (!petShop[i] || !petShop[i + HALF_SIZE])
        {
            std::cerr << "Allocation failed at index " << i << std::endl;
            // Clean up already allocated animals
            for (int j = 0; j <= i; j++)
            {
                delete petShop[j];
                if (j < i + HALF_SIZE)
                    delete petShop[j + HALF_SIZE];
            }
            return;
        }
    }
    
    // Demonstrate polymorphic behavior
    std::cout << "\nTesting polymorphic behavior:" << std::endl;
    for (int i = 0; i < ARRAY_SIZE; i++)
    {
        std::cout << "  Animal[" << i << "] - Type: " << petShop[i]->getType() 
                  << ", Sound: ";
        petShop[i]->makeSound();
    }
    
    // Clean up
    std::cout << "\nCleaning up animals..." << std::endl;
    for (int i = 0; i < ARRAY_SIZE; i++)
    {
        delete petShop[i];  // Virtual destructor ensures proper cleanup
    }
    
    std::cout << "Array test completed" << std::endl;
}

// ============================================================================
// Main Function
// ============================================================================

/**
 * @brief Main test driver
 * 
 * Executes a comprehensive test suite that validates:
 * - Memory management (allocation/deallocation)
 * - Polymorphism (virtual functions, dynamic binding)
 * - Deep copy semantics (copy constructor, copy assignment)
 * - Resource management (RAII principles via Brain ownership)
 * 
 * Each test is isolated in its own scope to ensure proper cleanup
 * and to prevent state from leaking between tests.
 * 
 * Run with valgrind to verify no memory leaks:
 *   valgrind --leak-check=full ./program_name
 */
int main()
{
    std::cout << "========================================" << std::endl;
    std::cout << "   ANIMAL HIERARCHY TEST SUITE" << std::endl;
    std::cout << "========================================" << std::endl;
    
    testBasicAllocationAndDestruction();
    testCatDeepCopy();
    testDogDeepCopy();
    testPolymorphicArray();
    
    std::cout << "\n========================================" << std::endl;
    std::cout << "   ALL TESTS COMPLETED" << std::endl;
    std::cout << "========================================" << std::endl;
    
    return 0;
}
