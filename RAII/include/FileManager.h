#pragma once
#include <iostream>
#include <vector>

class FileManager {
public:
    FileManager(std::string fileName);
    ~FileManager();
    std::vector<int> getData();

private:
    FILE *f = nullptr; // to check in destructor if it has been allocated or not
};