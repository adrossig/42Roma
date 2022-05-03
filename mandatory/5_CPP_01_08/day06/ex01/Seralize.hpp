#ifndef SERALIZE_HPP
# define SERALIZE_HPP
# include <iostream>

struct Data {
	std::string		name;
	std::string		lastName;
};

Data*		initData(std::string name, std::string lastName);
uintptr_t 	serialize(Data* ptr);
Data* 		deserialize(uintptr_t raw);

#endif
