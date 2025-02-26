#pragma once

#include <iostream>
#include <string>
#include "Form.hpp" // Include Form class

class Bureaucrat
{
private:
    const std::string _name;
    size_t _grade;

public:
    // Exceptions
    class GradeTooLowException : public std::exception
    {
    public:
        virtual const char *what() const throw();
    };

    class GradeTooHighException : public std::exception
    {
    public:
        virtual const char *what() const throw();
    };

    // Constructors & Destructor
    Bureaucrat();
    Bureaucrat(const std::string &name, int grade);
    Bureaucrat(const Bureaucrat &src);
    ~Bureaucrat();

    // Operators
    Bureaucrat &operator=(const Bureaucrat &src);

    // Getters
    const std::string &getName() const;
    int getGrade() const;

    // Methods
    void incrementGrade();
    void decrementGrade();
    void signForm(Form &form);
};

// Overload << operator
std::ostream &operator<<(std::ostream &os, const Bureaucrat &bureaucrat);
