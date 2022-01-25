#include <iostream>

int main()
{
    std::string str = "HI THIS IS BRAIN";
    std::string *stringPTR = &str;
    std::string &stringREF = str;

    std::cout << "Address: " << &str << std::endl;
    std::cout << "Pointer address: " << stringPTR << std::endl;
    std::cout << "Reference address: " << &stringREF << std::endl << std::endl;

    std::cout << "String: " << str << std::endl;
    std::cout << "String pointer: " << *stringPTR << std::endl;
    std::cout << "String reference: " << stringREF << std::endl;
}