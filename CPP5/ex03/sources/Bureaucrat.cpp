#include "../includes/Bureaucrat.hpp"

// OCF

// Constructor & Destructor

Bureaucrat::Bureaucrat() : name("Default"), grade(150)
{
	std::cout << "Bureaucrat Default Constructor Called" << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade) : name(name), grade(grade)
{
	std::cout << "Bureaucrat Custom Constructor Called" << std::endl;
	if (grade < 1)
		throw GradeTooHighException();
	if (grade > 150)
		throw GradeTooLowException();
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "Bureaucraft Destructor Called" << std::endl;
}

// Copy Constructor & Copy Assignment Operator

Bureaucrat::Bureaucrat(Bureaucrat const &src) : name(src.name), grade(src.grade)
{
	std::cout << "Bureaucrat Copy Constructor Called" << std::endl;
}

Bureaucrat &Bureaucrat::operator=(Bureaucrat const &rhs)
{
	std::cout << "Bureaucrat Copy Assignment Operator Called" << std::endl;
	if (this != &rhs)
	{
		this->grade = rhs.grade;
	}
	return *this;
}

// Setters and Getters

std::string Bureaucrat::getName() const
{
	return this->name;
}

int Bureaucrat::getGrade() const
{
	return this->grade;
}

// Member Functions

void Bureaucrat::increment()
{
	if (this->grade - 1 < 1)
		throw GradeTooHighException();
	this->grade--;
}

void Bureaucrat::decrement()
{
	if (this->grade + 1 > 150)
		throw GradeTooLowException();
	this->grade++;
}

void Bureaucrat::signForm(AForm &form)
{
	try
	{
		form.beSigned(*this);
		std::cout << this->getName() << " signed " << form.getName() << std::endl;
	}
	catch (std::exception &err)
	{
		std::cout << this->getName() << " couldn't sign " << form.getName() << " because " << err.what() << "." << std::endl;
	}
}

void Bureaucrat::executeForm(AForm const &form)
{
	try
	{
		form.execute(*this);
	}
	catch (std::exception &err)
	{
		std::cout << "Form Execution Failed because: " << err.what() << std::endl;
		std::cout << "Details: " << this->getName() << " tried to execute " << form.getName() << std::endl;
	}
}

// Exception Classes

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return "Invalid Grade: Too High";
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return "Invalid Grade: Too Low";
}

// Operator Overloads

std::ostream &operator<<(std::ostream &out, Bureaucrat &bureaucrat)
{
	out << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << "." << std::endl;
	return out;
}