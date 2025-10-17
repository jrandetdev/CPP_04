#ifndef BRAIN_HPP
# define BRAIN_HPP

#include <iostream>
#include <string>

class Brain
{
	private:
		std::string ideas[100];
	public:
		Brain();
		//Brain(std::string);
		Brain(const Brain& other);
		Brain& operator=(const Brain& other);
		~Brain();
		void	setIdea(const std::string& idea, int i);
		const std::string getIdea(void); 
};

#endif
