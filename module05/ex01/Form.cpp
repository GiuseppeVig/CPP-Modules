#include "Form.hpp"

// Exception Messages
const char *Form::GradeTooHighException::what() const throw()
{
    return "Form: Grade too high!";
}

const char *Form::GradeTooLowException::what() const throw()
{
    return "Form: Grade too low!";
}

// Default Constructor
Form::Form() : _name("Default Form"), _isSigned(false), _gradeToSign(50), _gradeToExecute(25)
{
}

// Parameterized Constructor
Form::Form(const std::string &name, int gradeToSign, int gradeToExecute)
    : _name(name), _isSigned(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
    if (gradeToSign < 1 || gradeToExecute < 1)
        throw GradeTooHighException();
    if (gradeToSign > 150 || gradeToExecute > 150)
        throw GradeTooLowException();
}

// Copy Constructor
Form::Form(const Form &src)
    : _name(src._name), _isSigned(src._isSigned), _gradeToSign(src._gradeToSign), _gradeToExecute(src._gradeToExecute)
{
}

// Destructor
Form::~Form()
{
}

// Assignment Operator
Form &Form::operator=(const Form &src)
{
    if (this != &src)
        _isSigned = src._isSigned;
    return *this;
}

// Getters
const std::string &Form::getName() const { return _name; }
bool Form::isSigned() const { return _isSigned; }
int Form::getGradeToSign() const { return _gradeToSign; }
int Form::getGradeToExecute() const { return _gradeToExecute; }

// Signing the form
void Form::beSigned(const Bureaucrat &bureaucrat)
{
    if (bureaucrat.getGrade() > _gradeToSign)
        throw GradeTooLowException();
    _isSigned = true;
}

// Overload << Operator
std::ostream &operator<<(std::ostream &os, const Form &form)
{
    os << "Form: " << form.getName()
       << " | Required Grade to Sign: " << form.getGradeToSign()
       << " | Required Grade to Execute: " << form.getGradeToExecute()
       << " | Signed: " << (form.isSigned() ? "Yes" : "No");
    return os;
}
