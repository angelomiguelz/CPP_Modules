# include "PhoneBook.hpp"

Phonebook::Phonebook(){
	index = 0;
}

void	Phonebook::ADD(){
	contacts[index % 8].getInfoBase("FIRST NAME");
	contacts[index % 8].getInfoBase("LAST NAME");
	contacts[index % 8].getInfoBase("NICKNAME");
	contacts[index % 8].getInfoBase("PHONE NUMBER");
	contacts[index % 8].getInfoBase("DARKEST SECRET");
	std::cout << "Contact Added" << std::endl;
	contacts[index % 8].showInfo();
	index++;
}

void	Contact::getInfoBase(std::string keyword) {
	std::string buff;
	do {
		if (std::cin.eof())
			exit(1);
		std::cout << ("ENTER ") << keyword << (": ");
		getline(std::cin, buff);
	} while(buff.empty()); //empty returns true while empty
	if (keyword == "FIRST NAME") {
		first_name = buff;
	}
	if (keyword == "LAST NAME") {
		last_name = buff;
	}
	if (keyword == "NICKNAME") {
		nickname = buff;
	}
	if (keyword == "PHONE NUMBER") {
		phone = buff;
	}
	if (keyword == "DARKEST SECRET") {
		secret = buff;
	}
		
}


