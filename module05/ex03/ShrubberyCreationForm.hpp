#pragma once

#include "AForm.hpp"
#include <fstream>

class ShrubberyCreationForm : public AForm
{
private:
    std::string _target;

public:
    ShrubberyCreationForm(const std::string &target);
    ~ShrubberyCreationForm();

    void executeAction() const;
};
