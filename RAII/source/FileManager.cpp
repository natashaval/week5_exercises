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
    // Be careful that you don't try to close a file that isn't open as this will cause a seg fault. 
    if (f)
    {
        std::fclose(f);
        std::cout << "File closed." << std::endl;
    }

    std::cout << "FileManager destructor" << std::endl;
}

bool FileManager::getData(int &n) {
    if (std::fscanf(f, "%d", &n) != EOF) {
        return true;
    }
    return false;
}