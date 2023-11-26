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
	index++;
}

bool	is_num_limits(std::string s, int lim) {
	if (s.size() != 1)
		return (false);
	if (s[0] >= '0' && s[0] <= '0' + lim)
		return (true);
	return (false);
}

void Phonebook::SEARCH() {
	std::string buff;
	int i = index;
	int max = index - 1;

	if (index == 0) {
		std::cout << "No contacts to show" << std::endl;
		return ;
	}
	std::cout << "|     INDEX|FIRST NAME| LAST NAME|  NICKNAME|" << std::endl;
	for (int i = 0; i < index; i++) {
		std::cout << "|    ";
		std::cout << i;
		std::cout << "     |";
		contacts[i].showInfoBase("FIRST NAME");
		std::cout << "|";
		contacts[i].showInfoBase("LAST NAME");
		std::cout << "|";
		contacts[i].showInfoBase("NICKNAME");
		std::cout << std::endl;
	}
	while (1) {
		std::cout << "Select the index: ";
		getline(std::cin, buff);
		if (std::cin.eof())
			exit(1);
		if (buff.empty())
			continue;
		if (is_num_limits(buff, max))
			i = atoi(buff.c_str());
		else
        {
            std::cout << "Enter a valid index." << std::endl;
            continue;
        }
		contacts[i].showInfoAll();
		break;
	}
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


