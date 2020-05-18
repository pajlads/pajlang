#include <fstream>
#include <iostream>
#include <sstream>
 
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

    
    std::cout << str << "\n";
    return 0;
}