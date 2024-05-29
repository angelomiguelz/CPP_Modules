#include "../includes/Form.hpp"

// Orthodox Canon Form

Form::Form(): _name("Default"), _isSigned(false), _signGrade(42), _executeGrade(42) {
	std::cout << "Default Constructor Called" << std::endl;
}

Form::Form(std::string name, int executeGrade, int signGrade): _name(name), _isSigned(false), _signGrade(signGrade),  _executeGrade(executeGrade) {
	std::cout << "Name and Grade Constructor Called" << std::endl;
	if (this->_executeGrade < 1 || this->_signGrade < 1)
		throw GradeTooHighException();
	if (this->_executeGrade > 150 || this->_signGrade > 150)
		throw GradeTooLowException();
}

Form::Form(Form const &src): _name(src._name), _isSigned(src._isSigned), _signGrade(src._signGrade), _executeGrade(src._executeGrade) {
	std::cout << "Copy Constructor Called" << std::endl;
}

Form &Form::operator=(Form const &rhs) {
	std::cout << "Copy Assignment Operator Called" << std::endl;
	if (this != &rhs) {
		this->_isSigned = rhs._isSigned;
	}
	return *this;
}

Form::~Form() {
	std::cout << "Form Default Deconstructor Called" << std::endl;
}

// Demanded by the subject

std::string Form::getName() {
	return (this->_name);
}

bool Form::getSignState() {
	return (this->_isSigned);
}

int Form::getSignGrade() {
	return (this->_signGrade);
}

int Form::getExecuteGrade() {
	return (this->_executeGrade);
}

std::ostream &operator<<(std::ostream &out, Form &form) {
	std::string state;
	if (form.getSignState() == false)
		state = "is not";
	else
		state = "is";
	out << form.getName() << ", " << state << " signed and has a SignGrade of " << form.getSignGrade() << " and an ExecuteGrade of " << form.getExecuteGrade() << std::endl;
	return (out);
}

void Form::beSigned(Bureaucrat &b) {
	if (b.getGrade() > this->_signGrade)
		throw(GradeTooLowException());
	this->_isSigned = true;
}

// Exceptions

const char *Form::GradeTooHighException::what() const throw() {
	return ("The given grade is too high");
}

const char *Form::GradeTooLowException::what() const throw() {
	return ("The given grade is too low");
}
