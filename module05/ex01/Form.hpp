#pragma once

#include <iostream>
#include <string>
#include "Bureaucrat.hpp"  // Include Bureaucrat class

class Form
{
private:
    const std::string _name;
    bool _isSigned;
    const int _gradeToSign;
    const int _gradeToExecute;

public:
    // Exceptions
    class GradeTooHighException : public std::exception
    {
    public:
        virtual const char *what() const throw();
    };

    class GradeTooLowException : public std::exception
    {
    public:
        virtual const char *what() const throw();
    };

    // Constructors & Destructor
    Form();
    Form(const std::string &name, int gradeToSign, int gradeToExecute);
    Form(const Form &src);
    ~Form();

    // Operators
    Form &operator=(const Form &src);

    // Getters
    const std::string &getName() const;
    bool isSigned() const;
    int getGradeToSign() const;
    int getGradeToExecute() const;

    // Public Methods
    void beSigned(const Bureaucrat &bureaucrat);
};

// Overload for output stream
std::ostream &operator<<(std::ostream &os, const Form &form);