#include "Convert.hpp"

long double 		toConvD = 0;
long int			toConvI = 0;
std::string const	convertToType[4] = { "Char: ",
						"Int: ","Float: ", "Double: " };

void	convert(std::string const conv) {

	if (convertInvalidAlpha(conv) != 1 || convertInvalidNum(conv) != 1) {
		if (conv.size() == 1 && isdigit(conv.at(0)) == 0)
			toConvD = conv.at(0);
		else
			toConvD = atof(conv.c_str());
		toConvI = static_cast<long int>(toConvD);
		return (convertTo());
	}
	return (convertInvalid());
}
