#include "Contact.hpp"

Contact::Contact(){
    return ;
}

Contact::~Contact(){
    return ;
}

void Contact::showInfo() {
	std::cout << first_name << std::endl;
	std::cout << last_name << std::endl;
	std::cout << nickname << std::endl;
	std::cout << phone << std::endl;
	std::cout << secret << std::endl;
}
