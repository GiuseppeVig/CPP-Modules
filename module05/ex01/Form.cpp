#include "Form.hpp"
#include "Bureaucrat.hpp"

// Constructor with validation
Form::Form(const std::string& name, int gradeToSign, int gradeToExecute)
    : _name(name), _isSigned(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute) {
    if (gradeToSign < 1 || gradeToExecute < 1)
        throw Form::GradeTooHighException();
    if (gradeToSign > 150 || gradeToExecute > 150)
        throw Form::GradeTooLowException();
}

// Copy Constructor
Form::Form(const Form& other)
    : _name(other._name), _isSigned(other._isSigned),
      _gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute) {}

// Assignment Operator
Form& Form::operator=(const Form& other) {
    if (this != &other) {
        _isSigned = other._isSigned; // _name and grades are const, so only _isSigned is copied
    }
    return *this;
}

// Destructor
Form::~Form() {}

// Getters
const std::string& Form::getName() const { return _name; }
bool Form::isSigned() const { return _isSigned; }
int Form::getGradeToSign() const { return _gradeToSign; }
int Form::getGradeToExecute() const { return _gradeToExecute; }

// Signing logic
void Form::beSigned(const Bureaucrat& b) {
    if (b.getGrade() > _gradeToSign)
        throw Form::GradeTooLowException();
    _isSigned = true;
}

// Exception Messages
const char* Form::GradeTooHighException::what() const throw() {
    return "FormException: Grade too high!";
}

const char* Form::GradeTooLowException::what() const throw() {
    return "FormException: Grade too low!";
}

// Overloaded Output Operator
std::ostream& operator<<(std::ostream& out, const Form& form) {
    out << "Form: " << form.getName() 
        << " | Signed: " << (form.isSigned() ? "Yes" : "No") 
        << " | Grade to Sign: " << form.getGradeToSign() 
        << " | Grade to Execute: " << form.getGradeToExecute();
    return out;
}
