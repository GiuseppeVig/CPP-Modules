#include "RPN.hpp"

// Constructor
RPN::RPN() {}

// Destructor
RPN::~RPN() {}

// Check if a token is an operator
bool RPN::isOperator(const std::string &token) const {
    return (token == "+" || token == "-" || token == "*" || token == "/");
}

// Perform an operation on two operands
int RPN::performOperation(int a, int b, char op) const {
    switch (op) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': 
            if (b == 0) throw std::runtime_error("Error: division by zero.");
            return a / b;
    }
    throw std::runtime_error("Error: invalid operator.");
}

// Evaluate the RPN expression
int RPN::evaluate(const std::string &expression) {
    std::istringstream ss(expression);
    std::string token;

    while (ss >> token) {
        // If the token is an operator, perform operation
        if (isOperator(token)) {
            if (stack.size() < 2) {
                throw std::runtime_error("Error: insufficient operands.");
            }
            int b = stack.top(); stack.pop();
            int a = stack.top(); stack.pop();
            stack.push(performOperation(a, b, token[0]));
        }
        // If the token is a number, push it to stack
        else {
            if (token.length() != 1 || token[0] < '0' || token[0] > '9') {
                throw std::runtime_error("Error: invalid token.");
            }
            stack.push(token[0] - '0'); // Convert char to int
        }
    }

    // After processing, there should be exactly one result in the stack
    if (stack.size() != 1) {
        throw std::runtime_error("Error: invalid RPN expression.");
    }
    return stack.top();
}
