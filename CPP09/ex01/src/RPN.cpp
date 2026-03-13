/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsagaro- <jsagaro-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 17:14:59 by jsagaro-          #+#    #+#             */
/*   Updated: 2026/03/13 19:51:13 by jsagaro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/RPN.hpp"
#include <sstream>

RPN::RPN() {}
RPN::RPN(const RPN& src) : _stack(src._stack) {}
RPN& RPN::operator=(const RPN& src) {
    if (this != &src) {
        _stack = src._stack;
    }
    return *this;
}
RPN::~RPN() {}

void RPN::calculate(const std::string& expression) {
    if (expression.empty()) {
        std::cerr << "Error: empty expression." << std::endl;
        return;
    }

    std::istringstream iss(expression);
    std::string token;

    while (iss >> token) {
        if (isNumber(token)) {
            _stack.push(std::atoi(token.c_str()));
        } else if (isOperator(token)) {
            if (!performOperation(token)) {
                return;
            }
        } else {
            std::cerr << "Error: invalid token '" << token << "'." << std::endl;
            return;
        }
    }

    if (_stack.size() != 1) {
        if (_stack.empty())
            std::cerr << "Error: no operands provided." << std::endl;
        else
            std::cerr << "Error: too many operands, not enough operators." << std::endl;
        return;
    }

    std::cout << _stack.top() << std::endl;
}

bool RPN::isNumber(const std::string& token) const {
    if (token.empty()) return false;
    size_t i = 0;
    if (token[0] == '-' && token.length() > 1) {
        i = 1;
    }
    
    if (token.length() - i > 1) {
        return false;
    }

    for (; i < token.length(); ++i) {
        if (!std::isdigit(token[i])) {
            return false;
        }
    }
    return true;
}

bool RPN::isOperator(const std::string& token) const {
    return token.length() == 1 && (token[0] == '+' || token[0] == '-' || token[0] == '*' || token[0] == '/');
}

bool RPN::performOperation(const std::string& op) {
    if (_stack.size() < 2) {
        std::cerr << "Error: not enough operands for operator '" << op << "'." << std::endl;
        return false;
    }

    int right = _stack.top();
    _stack.pop();
    int left = _stack.top();
    _stack.pop();

    int result = 0;

    switch (op[0]) {
        case '+': result = left + right; break;
        case '-': result = left - right; break;
        case '*': result = left * right; break;
        case '/':
            if (right == 0) {
                std::cerr << "Error: division by zero." << std::endl;
                return false;
            }
            result = left / right;
            break;
    }

    _stack.push(result);
    return true;
}
