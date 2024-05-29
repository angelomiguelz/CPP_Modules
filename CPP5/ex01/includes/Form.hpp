#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
private:
	const std::string _name;
	bool _isSigned;
	const int _signGrade;
	const int _executeGrade;

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
	Form();
	Form(std::string name, int executeGrade, int signGrade);
	~Form();
	// Copy Constructor
	Form(Form const &src);
	// Operator Overload
	Form &operator=(Form const &rhs);
	// Setters & Getters
	std::string getName();
	bool getSignState();
	int getSignGrade();
	int getExecuteGrade();
	// Member Functions
	void beSigned(Bureaucrat &b);
};

std::ostream &operator<<(std::ostream &out, Form &form);

#endif
