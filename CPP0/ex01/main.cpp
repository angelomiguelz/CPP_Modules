#include "PhoneBook.hpp"

int main(void){

    std::string key;
    Phonebook book;
    do {
		if (std::cin.eof())
			exit(1);
        std::cout << FBLU("Enter Command: ");
        getline(std::cin, key);
        if (key == "ADD")
            book.ADD();
		if (key == "SEARCH")
			book.SEARCH();
        if (key == "EXIT")
            std::cout << "\nThanks bud\n";
    } while (key != "EXIT");
}
