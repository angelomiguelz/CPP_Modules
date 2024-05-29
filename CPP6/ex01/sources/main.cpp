#include "../includes/Serializer.hpp"

int main(void)
{
	Data data = {"beterraba"};

	std::cout << "Data Pointer Before: ->" << &data << "<-" << std::endl;
	std::cout << "Data Before Info: ->" << data.preciousInformation << "<-" << std::endl;
	uintptr_t raw = Serializer::serialize(&data);
	std::cout << "Data Raw: ->" << raw << "<-" << std::endl;
	Data* back = Serializer::deserialize(raw);
	std::cout << "Data After Info: ->" << back->preciousInformation << "<-" << std::endl;
	std::cout << "Data Pointer After: ->" << back << "<-" << std::endl;
}
