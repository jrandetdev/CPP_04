#ifndef BRAIN_HPP
# define BRAIN_HPP

#include <iostream>
#include <string>

/**
 * @brief
 * 
 * to understand 
 */
class Brain
{
	private:
		std::string ideas[100]; //declaring on the stack because the size is known
	public:
		Brain();
		Brain(const Brain& other);
		Brain& operator=(const Brain& other);
		~Brain();
		void	setIdea(const std::string& idea, int i);
		//const std::string getIdea(void); 
};

#endif
