#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string.h>
#include <iostream>

class Contact {
	private:
		std::string first_name;
		std::string last_name;
		std::string nickname;
		std::string phone;
		std::string secret;
	public:
		Contact();
		~Contact();
		void getInfoBase(std::string keyword);
		void showInfo();
};


#endif