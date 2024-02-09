#include "FileManager.h"

FileManager::FileManager(std::string fileName) {
    std::cout << "FileManager constructor" << std::endl;

    f = std::fopen(fileName.c_str(), "rw");
    if(!f) {
        std::string err_msg = "Failed to open file " + fileName;
        throw std::runtime_error(err_msg);
    }
    std::cout << "File opened." << std::endl;
}

FileManager::~FileManager() {
    if (f)
    {
        std::fclose(f);
        std::cout << "File closed." << std::endl;
    }

    std::cout << "FileManager destructor" << std::endl;
}

std::vector<int> FileManager::getData() {
    std::vector<int> factorialList;
    int n;
    while (std::fscanf(f, "%d", &n) != EOF) {
        factorialList.push_back(n);
    }
    return factorialList;
}