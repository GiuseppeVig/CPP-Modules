#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <stdexcept>

class Bureaucrat {
private:
    const std::string name;
    int grade;

public:
    // Custom Exceptions
    class GradeTooHighException : public std::exception {
    public:
        const char* what() const noexcept override;
    };

    class GradeTooLowException : public std::exception {
    public:
        const char* what() const noexcept override;
    };

    // Constructor & Destructor
    Bureaucrat(const std::string& name, int grade);
    ~Bureaucrat();

    // Getters
    std::string getName() const;
    int getGrade() const;

    // Grade Modification
    void upgrade();
    void downgrade();

    // Function for formatted output (to replace friend operator<<)
    std::string toString() const;
};

// Overloaded output operator (calls toString() instead of using friend)
std::ostream& operator<<(std::ostream& out, const Bureaucrat& b);

#endif // BUREAUCRAT_HPP
