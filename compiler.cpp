#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>
 
std::vector<std::string> split(const std::string &s, char delim)
{
    std::stringstream ss(s);
    std::string item;
    std::vector<std::string> elems;
    while (std::getline(ss, item, delim))
    {
        elems.push_back(item);
    }

    return elems;
}

int main(int argc, char *argv[])
{
    if (argc <= 1) { 
        std::cout << "no input files" << std::endl;
        return 1;
    }
    std::string file = argv[1];

    std::ifstream inFile;
    inFile.open(file);
    std::stringstream strStream;
    strStream << inFile.rdbuf();
    std::string str = strStream.str();

    auto instructions = split(str, ';');

    for (auto it = instructions.begin(); it != instructions.end(); ++it) {
        std::cout << *it;
    }

    return 0;
}
