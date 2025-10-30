#include "Brain.hpp"

Brain::Brain()
{
  for (int i = 0; i < 100; ++i)
  {
    this->ideas[i] = "sleeping";
  }
  std::cout << "Brain:: Default constructor called." << '\n';
}

Brain::Brain(const Brain& other)
{
  for (int i = 0; i < 100; i++)
  {
    this->ideas[i] = other.ideas[i];
  }
  std::cout << "Brain:: Copy constructor called" << '\n';
}

Brain& Brain::operator=(const Brain& other)
{
  if (this != &other)
  {
    for (int i = 0; i < 100; i++)
    {
      this->ideas[i] = other.ideas[i];
    }
  }
  return (*this);
}

Brain::~Brain()
{
  std::cout << "Brain:: default destructor called" << '\n';
}

void	Brain::setIdea(const std::string& idea, int i)
{
  this->ideas[i] = idea;
}

const std::string Brain::getIdea(int i)
{
  //std::cout << "index sent to getIdea is " << i << "and idea is " << this->ideas[i] << '\n';
  return this->ideas[i];
}
