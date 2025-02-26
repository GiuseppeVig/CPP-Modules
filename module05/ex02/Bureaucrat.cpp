#include "Bureaucrat.hpp"

// Constructor
Bureaucrat::Bureaucrat(const std::string& name, int grade) : name(name) {
    if (grade < 1)
        throw GradeTooHighException(); // Throw an error if grade is too high
    if (grade > 150)
        throw GradeTooLowException(); // Throw an error if grade is too low
    this->grade = grade;
}

// Destructor (nothing to clean up, so it's empty)
Bureaucrat::~Bureaucrat() {}

// Exception Messages
const char* Bureaucrat::GradeTooHighException::what() const noexcept {
    return "Grade too high! Must be between 1 and 150.";
}

const char* Bureaucrat::GradeTooLowException::what() const noexcept {
    return "Grade too low! Must be between 1 and 150.";
}

// Getters
std::string Bureaucrat::getName() const {
    return name;
}

int Bureaucrat::getGrade() const {
    return grade;
}

// Grade Modification
void Bureaucrat::upgrade() {
    if (grade - 1 < 1)
        throw GradeTooHighException();
    grade--; // Move up in rank
}

void Bureaucrat::downgrade() {
    if (grade + 1 > 150)
        throw GradeTooLowException();
    grade++; // Move down in rank
}

void Bureaucrat::signForm(Form &form)
{
    try
    {
        form.beSigned(*this);
        std::cout << _name << " signed " << form.getName() << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cout << _name << " couldn’t sign " << form.getName() << " because " << e.what() << std::endl;
    }
}

// Converts the bureaucrat's details to a formatted string
std::string Bureaucrat::toString() const {
    return name + ", bureaucrat grade " + std::to_string(grade);
}

// Overloaded output operator
std::ostream& operator<<(std::ostream& out, const Bureaucrat& b) {
    out << b.toString();
    return out;
}
