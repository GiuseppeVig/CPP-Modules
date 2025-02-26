#include "Intern.hpp"

int main()
{
    try
    {
        Intern someRandomIntern;

        AForm *form1 = someRandomIntern.makeForm("robotomy request", "Bender");
        AForm *form2 = someRandomIntern.makeForm("presidential pardon", "Zaphod");
        AForm *form3 = someRandomIntern.makeForm("shrubbery creation", "Garden");
        AForm *form4 = someRandomIntern.makeForm("invalid form", "Nowhere"); // Should fail

        Bureaucrat highRank("Alice", 1);

        // Sign and execute the created forms
        if (form1)
        {
            highRank.signForm(*form1);
            highRank.executeForm(*form1);
        }

        if (form2)
        {
            highRank.signForm(*form2);
            highRank.executeForm(*form2);
        }

        if (form3)
        {
            highRank.signForm(*form3);
            highRank.executeForm(*form3);
        }

        // Cleanup: delete dynamically allocated forms
        delete form1;
        delete form2;
        delete form3;
    }
    catch (const std::exception &e)
    {
        std::cerr << "Critical Exception: " << e.what() << std::endl;
    }

    return 0;
}
