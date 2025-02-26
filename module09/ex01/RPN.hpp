#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <stack>
#include <sstream>
#include <stdexcept>

class RPN {
private:
    std::stack<int> stack; // Stack for RPN calculation

public:
    RPN();
    ~RPN();

    int evaluate(const std::string &expression);
    bool isOperator(const std::string &token) const;
    int performOperation(int a, int b, char op) const;
};

#endif
