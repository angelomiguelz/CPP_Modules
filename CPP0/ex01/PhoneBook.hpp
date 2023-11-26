#ifndef PHONE_BOOK_HPP
#define PHONE_BOOK_HPP

#include <string.h>
#include <iostream>
#include <iomanip>
# include "Contact.hpp"

//COLORS
# define RST "\x1B[0m"
# define KBLU "\x1B[34m"
# define FBLU(x) KBLU x RST

class Phonebook {
    private:
        Contact contacts[8];
		int		index;
    public:
		Phonebook();
        void ADD();
		void SEARCH();
};


#endif
