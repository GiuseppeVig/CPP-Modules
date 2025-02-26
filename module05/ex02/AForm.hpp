#pragma once

#include <iostream>
#include <string>
#include "Bureaucrat.hpp"

class AForm
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

    class FormNotSignedException : public std::exception
    {
    public:
        virtual const char *what() const throw();
    };

    // Constructors & Destructor
    AForm();
    AForm(const std::string &name, int gradeToSign, int gradeToExecute);
    AForm(const AForm &src);
    virtual ~AForm();

    // Operators
    AForm &operator=(const AForm &src);

    // Getters
    const std::string &getName() const;
    bool isSigned() const;
    int getGradeToSign() const;
    int getGradeToExecute() const;

    // Public Methods
    void beSigned(const Bureaucrat &bureaucrat);
    void execute(Bureaucrat const &executor) const;

    // Pure virtual function to be implemented in derived classes
    virtual void executeAction() const = 0;
};

// Overload for output stream
std::ostream &operator<<(std::ostream &os, const AForm &form);
