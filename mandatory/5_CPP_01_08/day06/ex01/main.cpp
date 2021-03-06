#include "Seralize.hpp"

int		main(void) {
	Data*		data = initData("Jean", "PIERRE");
	uintptr_t 	testSeralize = 0;
	Data*		testDeseralize = NULL;

	std::cout << "-> Testing Seralization and Deseralization on Structure Data" << std::endl;
	testSeralize = serialize(data);
	testDeseralize = deserialize(testSeralize);

	std::cout << "   Unintptr_ t: " << testSeralize << std::endl;
	std::cout << "   Data Name: ";
	(testDeseralize->name.compare(data->name) == 0) ? std::cout << "Same;" << std::endl : std::cout << "Not same;" << std::endl;
	std::cout << "   Data Lastname: ";
	(testDeseralize->lastName.compare(data->lastName) == 0) ? std::cout << "Same." << std::endl : std::cout << "Not Same." << std::endl;

	std::cout << "-> Using struct after:" << std::endl;
	std::cout << "   Data: " << data->name << " - " << data->lastName << std::endl;
	delete data;
	return (0);
}
