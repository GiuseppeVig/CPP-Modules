#include <iostream>
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
    try
    {
        // Creating Bureaucrats
        Bureaucrat highRank("Alice", 1);
        Bureaucrat midRank("Bob", 50);
        Bureaucrat lowRank("Charlie", 150);

        // Creating Forms
        ShrubberyCreationForm shrubberyForm("Home");
        RobotomyRequestForm robotomyForm("Bender");
        PresidentialPardonForm pardonForm("Zaphod");

        std::cout << "\n==== Bureaucrats and Forms Initialized ====\n";
        std::cout << highRank << std::endl;
        std::cout << midRank << std::endl;
        std::cout << lowRank << std::endl;
        std::cout << shrubberyForm << std::endl;
        std::cout << robotomyForm << std::endl;
        std::cout << pardonForm << std::endl;

        // Signing Forms
        std::cout << "\n==== Signing Forms ====\n";
        highRank.signForm(shrubberyForm);
        midRank.signForm(robotomyForm);
        
        // Attempt to sign a form with insufficient grade
        try
        {
            lowRank.signForm(pardonForm);
        }
        catch (const std::exception &e)
        {
            std::cerr << "Exception: " << e.what() << std::endl;
        }

        // Executing Forms
        std::cout << "\n==== Executing Forms ====\n";
        highRank.executeForm(shrubberyForm);
        midRank.executeForm(robotomyForm);

        // Attempt to execute without signing
        try
        {
            lowRank.executeForm(pardonForm);
        }
        catch (const std::exception &e)
        {
            std::cerr << "Exception: " << e.what() << std::endl;
        }

        // Sign and Execute Pardon Form
        highRank.signForm(pardonForm);
        highRank.executeForm(pardonForm);
    }
    catch (const std::exception &e)
    {
        std::cerr << "Critical Exception: " << e.what() << std::endl;
    }

    return 0;
}
