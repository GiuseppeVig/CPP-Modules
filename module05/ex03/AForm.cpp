#include "AForm.hpp"

// Exception Messages
const char *AForm::GradeTooHighException::what() const throw()
{
    return "AForm: Grade too high!";
}

const char *AForm::GradeTooLowException::what() const throw()
{
    return "AForm: Grade too low!";
}

const char *AForm::FormNotSignedException::what() const throw()
{
    return "AForm: Form is not signed!";
}

// Constructor
AForm::AForm(const std::string &name, int gradeToSign, int gradeToExecute)
    : _name(name), _isSigned(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
    if (gradeToSign < 1 || gradeToExecute < 1)
        throw GradeTooHighException();
    if (gradeToSign > 150 || gradeToExecute > 150)
        throw GradeTooLowException();
}

// Copy Constructor
AForm::AForm(const AForm &src)
    : _name(src._name), _isSigned(src._isSigned), _gradeToSign(src._gradeToSign), _gradeToExecute(src._gradeToExecute)
{
}

// Destructor
AForm::~AForm()
{
}

// Assignment Operator
AForm &AForm::operator=(const AForm &src)
{
    if (this != &src)
        _isSigned = src._isSigned;
    return *this;
}

// Getters
const std::string &AForm::getName() const { return _name; }
bool AForm::isSigned() const { return _isSigned; }
int AForm::getGradeToSign() const { return _gradeToSign; }
int AForm::getGradeToExecute() const { return _gradeToExecute; }

// Signing the form
void AForm::beSigned(const Bureaucrat &bureaucrat)
{
    if (bureaucrat.getGrade() > _gradeToSign)
        throw GradeTooLowException();
    _isSigned = true;
}

// Execute function
void AForm::execute(Bureaucrat const &executor) const
{
    if (!_isSigned)
        throw FormNotSignedException();
    if (executor.getGrade() > _gradeToExecute)
        throw GradeTooLowException();
    executeAction();
}

// Overload << Operator
std::ostream &operator<<(std::ostream &os, const AForm &form)
{
    os << "AForm: " << form.getName()
       << " | Required Grade to Sign: " << form.getGradeToSign()
       << " | Required Grade to Execute: " << form.getGradeToExecute()
       << " | Signed: " << (form.isSigned() ? "Yes" : "No");
    return os;
}
