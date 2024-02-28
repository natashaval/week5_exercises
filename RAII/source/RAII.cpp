#include <cstdio>
#include <iostream>
#include <stdexcept>
#include <fstream>
#include "FileManager.h"

int factorial(int n)
{
    if (n < 0) {
        throw std::runtime_error("Value is negative!");
    }
    return n == 0 ? 1 : n * factorial(n-1);
}

void printProcessedFile(std::vector<int> data)
{
    for (int n : data)
    {
        std::cout << n << "! = " << factorial(n) << std::endl;
    }
}

void printProcessedData(std::string fileName) {
    std::ifstream filestream;
    filestream.open(fileName);
    int n;
    while (filestream >> n) {
        std::cout << n << "! = " << factorial(n) << std::endl;
    }
    filestream.close();
}

int main()
{
    // FileManager fileManager = FileManager("testFile.txt");
    try
    {
        // FileManager fileManager = FileManager("testFile.txt");
        // printProcessedFile(fileManager.getData());

        printProcessedData("testFile.txt");
    }
    catch(std::exception &e)
    {
        std::cout << "Exception caught: " << e.what() << std::endl;
        std::cout << "We no longer have access to the file handle." << std::endl;
    }

    return 0;
}