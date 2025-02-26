#include "Intern.hpp"

// Default Constructor
Intern::Intern() {}

// Copy Constructor
Intern::Intern(const Intern &src)
{
    (void)src; // Nothing to copy, as Intern has no attributes
}

// Destructor
Intern::~Intern() {}

// Assignment Operator (Nothing to assign, just return *this)
Intern &Intern::operator=(const Intern &src)
{
    (void)src;
    return *this;
}

// Function to create forms
AForm *Intern::makeForm(std::string formName, std::string target)
{
    // Array of form types and corresponding constructors
    struct FormTypes
    {
        std::string name;
        AForm *(*create)(std::string);
    };

    FormTypes formList[] = {
        {"shrubbery creation", [](std::string target) { return new ShrubberyCreationForm(target); }},
        {"robotomy request", [](std::string target) { return new RobotomyRequestForm(target); }},
        {"presidential pardon", [](std::string target) { return new PresidentialPardonForm(target); }}
    };

    // Check which form matches the request
    for (int i = 0; i < 3; i++)
    {
        if (formName == formList[i].name)
        {
            std::cout << "Intern creates " << formName << std::endl;
            return formList[i].create(target);
        }
    }

    // If no form matches, print error
    std::cerr << "Intern couldn't find form: " << formName << std::endl;
    return nullptr;
}
