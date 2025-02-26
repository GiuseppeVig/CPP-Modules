#include "ShrubberyCreationForm.hpp"

// Constructor
ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target)
    : AForm("ShrubberyCreationForm", 145, 137), _target(target)
{
}

// Destructor
ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

// Execute action
void ShrubberyCreationForm::executeAction() const
{
    std::ofstream outfile(_target + "_shrubbery");
    outfile << "      /\\" << std::endl;
    outfile << "     /\\*\\" << std::endl;
    outfile << "    /\\O\\*\\" << std::endl;
    outfile << "   /*/\\/\\/\\\\" << std::endl;
    outfile << "  /\\O\\/\\*\\/\\\\" << std::endl;
    outfile << " /\\*\\/\\*\\/\\/\\\\" << std::endl;
    outfile.close();
}
