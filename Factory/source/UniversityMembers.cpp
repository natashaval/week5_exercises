#include "UniversityMembers.h"
#include <iostream> 

int Student::ID_counter = 0;

Student::Student(std::string email_address) : student_ID(ID_counter++)
{
    email = email_address;
}

void Student::printDetails()
{
    std::cout << "Student ID: " << student_ID << std::endl;
    std::cout << "email address: " << email << std::endl;
}

void Staff::printDetails()
{
    std::cout << "Job title: " << job_title << std::endl;
    std::cout << "email address: " << email << std::endl;
}

Staff::Staff(std::string email_address, std::string job) : job_title(job)
{
    email = email_address;
}