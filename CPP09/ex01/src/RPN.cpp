/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsagaro- <jsagaro-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 17:14:59 by jsagaro-          #+#    #+#             */
/*   Updated: 2026/03/06 19:18:46 by jsagaro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/RPN.hpp"

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

    for (size_t i = 0; i < expression.length(); i++) {
        char c = expression[i];

        if (std::isspace(c))
            continue;
        else if (std::isdigit(c))
            _stack.push(c - '0');
        else if (isOperator(c)) {
            if (!performOperation(c))
                return;
        } else {
            std::cerr << "Error: invalid token '" << c << "'." << std::endl;
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

bool RPN::isOperator(char c) const {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

bool RPN::performOperation(char op) {
    if (_stack.size() < 2) {
        std::cerr << "Error: not enough operands for operator '" << op << "'." << std::endl;
        return false;
    }

    int right = _stack.top();
    _stack.pop();
    int left = _stack.top();
    _stack.pop();

    int result = 0;

    switch (op) {
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
