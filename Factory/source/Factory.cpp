#include "UniversityMembers.h"
#include <iostream>
#include <memory>
#include <vector>

std::unique_ptr<UniversityMember> UM_factory()
{
    // ask for details here using cout / cin

    // use these details to create the appropriate derived class and return

    std::string email;
    std::cout << "Please enter an email address." << std::endl;
    std::cin >> email;
    std::cout << "Please enter if you are staff or student." << std::endl;
    std::string member_type;
    std::cin >> member_type;
    if (member_type == "Staff" || member_type == "staff")
    {
        // generate a staff member derived class
        std::string job_title;
        std::cout << "Please enter your job title." << std::endl;
        std::getline(std::cin>>std::ws, job_title);  // this allows us to get titles that are multiple words
        return std::make_unique<Staff>(email, job_title);
    }
    else if (member_type == "Student" || member_type == "student")
    {
        // generate a student derived class
        return std::make_unique<Student>(email);  // ID is set by the constructor
    }
    else
    {
        throw std::runtime_error("University member type " + member_type + " is not valid. You may be either 'staff' or 'student'.");
    }
}

int main()
{  
    std::vector<std::unique_ptr<UniversityMember>> universityRoster;
    for(size_t i = 0; i < 3; i++)
    {
        universityRoster.push_back(UM_factory());
    }

    for(auto &p : universityRoster)
    {
        p->printDetails();
    }
}