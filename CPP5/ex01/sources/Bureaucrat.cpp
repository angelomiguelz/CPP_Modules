#include "../includes/Bureaucrat.hpp"

// Orthodox Canon Form

Bureaucrat::Bureaucrat(): _name("Default"), _grade(42) {
	std::cout << "Default Constructor Called" << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade): _name(name), _grade(grade) {
	std::cout << "Name and Grade Constructor Called" << std::endl;
	if (this->_grade < 1) {
		throw GradeTooHighException();
	}
	if (this->_grade > 150) {
		throw GradeTooLowException();
	}
}

Bureaucrat::Bureaucrat(Bureaucrat const &src): _name(src._name), _grade(src._grade){ //why
	std::cout << "Copy Constructor Called" << std::endl;
}

Bureaucrat &Bureaucrat::operator=(Bureaucrat const &rhs) {
	std::cout << "Copy Assignment Operator Called" << std::endl;
	if (this != &rhs) {
		this->_grade = rhs._grade;
	}
	return *this;
}

Bureaucrat::~Bureaucrat() {
	std::cout << "Bureaucrat Default Deconstructor Called" << std::endl;
}

// Demanded by the subject

std::string Bureaucrat::getName() {
	return (this->_name);
}

int Bureaucrat::getGrade() {
	return (this->_grade);
}

void Bureaucrat::incrementGrade() {
	if (this->_grade - 1 < 1)
		throw GradeTooHighException();
	else
		this->_grade--;
}

void Bureaucrat::decrementGrade() {
	if (this->_grade + 1 > 150)
		throw GradeTooLowException();
	else
		this->_grade++;
}

void Bureaucrat::signForm(Form &f) {
	try {
		f.beSigned(*this);
		std::cout << this->getName() << " signed " << f.getName() << std::endl;
	}
	catch(const std::exception& e) {
		std::cout << this->getName() << " couldn't sign " << f.getName() << " because " << e.what() << std::endl;
	}	
}

std::ostream &operator<<(std::ostream &out, Bureaucrat &bureaucrat) {
	out << bureaucrat.getName() << ", bureaucrat grade is " << bureaucrat.getGrade() << "." << std::endl;
	return (out);
}

// Exceptions

const char *Bureaucrat::GradeTooHighException::what() const throw() {
	return ("The given grade is too high");
}

const char *Bureaucrat::GradeTooLowException::what() const throw() {
	return ("The given grade is too low");
}
