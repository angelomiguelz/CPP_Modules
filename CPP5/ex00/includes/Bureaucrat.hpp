#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <fstream>

class Bureaucrat
{
private:
	const std::string _name;
	int _grade;

public:
	// Exception Classes
	class GradeTooHighException : public std::exception
	{
		const char *what() const throw();
	};
	class GradeTooLowException : public std::exception
	{
		const char *what() const throw();
	};
	// Constructor & Destructor
	Bureaucrat();
	Bureaucrat(std::string name, int grade);
	~Bureaucrat();
	// Copy Constructor
	Bureaucrat(Bureaucrat const &src);
	// Operator Overload
	Bureaucrat &operator=(Bureaucrat const &rhs);
	// Setters & Getters
	std::string getName();
	int getGrade();
	// Member Functions
	void incrementGrade();
	void decrementGrade();
};

std::ostream &operator<<(std::ostream &out, Bureaucrat &bureaucrat);

#endif
