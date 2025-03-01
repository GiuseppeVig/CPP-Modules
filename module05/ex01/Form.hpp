#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <string>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form {
private:
    const std::string _name;
    bool _isSigned;
    const int _gradeToSign;
    const int _gradeToExecute;

public:
    // Constructors
    Form(const std::string& name, int gradeToSign, int gradeToExecute);
    Form(const Form& other);
    
    // Destructor
    ~Form();

    // Operator Overload
    Form& operator=(const Form& other);

    // Getters
    const std::string& getName() const;
    bool isSigned() const;
    int getGradeToSign() const;
    int getGradeToExecute() const;

    // Methods
    void beSigned(const Bureaucrat& b);

    // Exceptions
    class GradeTooHighException : public std::exception {
    public:
        virtual const char* what() const throw();
    };

    class GradeTooLowException : public std::exception {
    public:
        virtual const char* what() const throw();
    };
};

// Overloaded << operator for output
std::ostream& operator<<(std::ostream& out, const Form& form);

#endif
