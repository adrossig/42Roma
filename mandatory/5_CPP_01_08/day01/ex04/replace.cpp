#include "replace.hpp"

void replace(std::string FILENAME, std::string s1, std::string s2)
{
    std::ifstream ifs(FILENAME);

    if (s1.empty() || s2.empty())
        std::cerr << "[ERROR]: s1 or s2 is empty!" << std::endl;
    else if (ifs)
    {
        std::string line = "";
        std::ofstream newfile(FILENAME + "_replace", std::ios::out);

        while (getline(ifs,line))
        {
            size_t i = 0;
            while ((i = line.find(s1, i)) != std::string::npos)
            {
                line.replace(i, s1.size(), s2);
                i += s1.size();
            }
            newfile << line << std::endl;
        }
        newfile.close();
        ifs.close();
        std::cout << "[SUCCESS]: All accurences have been replaced!" << std::endl;
    }
    else
        std::cout << "[ERROR]: Can't open the file (" << FILENAME << ")!" <<std::endl;
    return ;
}