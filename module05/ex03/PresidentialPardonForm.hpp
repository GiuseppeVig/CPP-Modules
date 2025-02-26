#pragma once

#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
private:
    std::string _target;

public:
    PresidentialPardonForm(const std::string &target);
    ~PresidentialPardonForm();

    void executeAction() const;
};
