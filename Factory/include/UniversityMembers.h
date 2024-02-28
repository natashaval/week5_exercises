#pragma once
#include <string> 

class UniversityMember
{
public:
    virtual void printDetails() = 0;

protected: 
    std::string email;
};

class Student : public UniversityMember
{
public:
    Student(std::string email_address);

    void printDetails();
private:
    // ID counter is used to create a new ID for everyone because it is a class property (static)
    static int ID_counter;
    const int student_ID;
};

class Staff : public UniversityMember
{
public:
    Staff(std::string email_address, std::string job);

    void printDetails();
private:
    std::string job_title;
};