#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(const std::string &target)
    : AForm("RobotomyRequestForm", 72, 45), _target(target)
{
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}

void RobotomyRequestForm::executeAction() const
{
    std::cout << "* Drilling noises *" << std::endl;
    if (rand() % 2)
        std::cout << _target << " has been successfully robotomized!" << std::endl;
    else
        std::cout << "Robotomy failed on " << _target << "!" << std::endl;
}
