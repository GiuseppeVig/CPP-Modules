#include "Bureaucrat.hpp"
#include <iostream>

// Constructor with name and grade validation
Bureaucrat::Bureaucrat(const std::string& name, int grade) : _name(name) {
    if (grade < 1)
        throw Bureaucrat::GradeTooHighException();
    if (grade > 150)
        throw Bureaucrat::GradeTooLowException();
    _grade = grade;
}

// Copy Constructor
Bureaucrat::Bureaucrat(const Bureaucrat& other) : _name(other._name), _grade(other._grade) {}

// Assignment Operator
Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other) {
    if (this != &other)
        _grade = other._grade;  // Name is constant, so only grade is assigned
    return *this;
}

// Destructor
Bureaucrat::~Bureaucrat() {}

// Getters
const std::string& Bureaucrat::getName() const { return _name; }
int Bureaucrat::getGrade() const { return _grade; }

// Increment Grade (throws if out of range)
void Bureaucrat::incrementGrade() {
    if (_grade - 1 < 1)
        throw Bureaucrat::GradeTooHighException();
    _grade--;
}

// Decrement Grade (throws if out of range)
void Bureaucrat::decrementGrade() {
    if (_grade + 1 > 150)
        throw Bureaucrat::GradeTooLowException();
    _grade++;
}

// Exception Definitions
const char* Bureaucrat::GradeTooHighException::what() const throw() {
    return "BureaucratException: Grade too high!";
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
    return "BureaucratException: Grade too low!";
}

// Output Operator Overload
std::ostream& operator<<(std::ostream& out, const Bureaucrat& b) {
    out << b.getName() << ", bureaucrat grade " << b.getGrade();
    return out;
}
